#include "NetworkDispatcher.h"

void outputNetworkError(int errorCode) {
	switch (errorCode)
	{
	case WSANOTINITIALISED:
		cout << "在使用此函数之前，必须成功调用 WSAStartup 。" << "\n";
		break;
	case WSAENETDOWN:
		cout << "网络子系统或关联的服务提供商发生故障。" << "\n";
		break;
	case WSAEAFNOSUPPORT:
		cout << "不支持指定的地址系列。 例如，应用程序尝试为 AF_IRDA 地址系列创建套接字，但未在本地计算机上安装红外适配器和设备驱动程序。" << "\n";
		break;
	case WSAEINPROGRESS:
		cout << "阻止 Windows 套接字 1.1 调用正在进行，或者服务提供商仍在处理回调函数。" << "\n";
		break;
	case WSAEMFILE:
		cout << "无法提供更多套接字描述符。" << "\n";
		break;
	case WSAEINVAL:
		cout << "	提供的参数无效。 如果 af 参数设置为 AF_UNSPEC 且类型和协议参数未指定，则返回此错误。" << "\n";
		break;
	case WSAEINVALIDPROVIDER:
		cout << "服务提供商返回了 2.2 以外的版本。" << "\n";
		break;
	case WSAEINVALIDPROCTABLE:
		cout << "服务提供商向 WSPStartup 返回了无效或不完整的过程表。" << "\n";
		break;
	case WSAENOBUFS:
		cout << "未提供任何缓冲区空间。 无法创建套接字。" << "\n";
		break;
	case WSAEPROTONOSUPPORT:
		cout << "指定的协议不受支持。" << "\n";
		break;
	case WSAEPROTOTYPE:
		cout << "指定的协议是此套接字的错误类型。" << "\n";
		break;
	case WSAEPROVIDERFAILEDINIT:
		cout << "服务提供程序初始化失败。 如果分层服务提供程序 (LSP) 或命名空间提供程序安装不正确或提供程序无法正常运行，则返回此错误。" << "\n";
		break;
	case WSAESOCKTNOSUPPORT:
		cout << "在此地址系列中，不支持指定的套接字类型。" << "\n";
	case WSASYSNOTREADY:
		cout << "基础网络子系统尚未准备好进行网络通信。" << "\n";
		break;
	case WSAVERNOTSUPPORTED:
		cout << "此特定 Windows 套接字实现不提供所请求的 Windows 套接字支持版本。。" << "\n";
		break;
	case WSAEPROCLIM:
		cout << "已达到 Windows 套接字实现支持的任务数限制。" << "\n";
		break;
	case WSAEFAULT:
		cout << "lpWSAData 参数不是有效的指针" << "\n";
		break;
	case WSAEADDRINUSE:
		cout << "套接字的本地地址已在使用中，并且未将套接字标记为允许使用 SO_REUSEADDR 重用地址。" << endl;
		break;
	case WSAEINTR:
		cout << "阻塞的 Windows 套接字 1.1 调用已通过 WSACancelBlockingCall 取消。" << endl;
		break;
	case WSAEALREADY:
		cout << "正在指定的套接字上进行非阻止连接调用。" << endl;
		break;
	case WSAEADDRNOTAVAIL:
		cout << "远程地址不是有效的地址 (例如 INADDR_ANY 或 in6addr_any) 。" << endl;
		break;
	case WSAECONNREFUSED:
		cout << "尝试连接被强制性拒绝。" << endl;
		break;
	case WSAEISCONN:
		cout << "仅面向连接的套接字已连接。" << endl;
		break;
	case WSAENETUNREACH:
		cout << "此时不可以从此主机访问该网络。" << endl;
		break;
	case WSAEHOSTUNREACH:
		cout << "套接字操作尝试访问无法访问的主机。" << endl;
		break;
	case WSAENOTSOCK:
		cout << "描述符不是套接字。" << endl;
		break;
	case WSAETIMEDOUT:
		cout << "尝试连接超时，但未建立连接。" << endl;
		break;
	case WSAEWOULDBLOCK:
		cout << "套接字标记为非阻止，无法立即完成连接。" << endl;
		break;
	case WSAEACCES:
		cout << "尝试将数据报套接字连接到广播地址失败，因为未启用 SO_BROADCAST。" << endl;
		break;
	default:
		cout << "未知错误码：" << errorCode << endl;
		break;
	}
}
void printNetworkError(const string errorStr, int errorCode) {
	outputNetworkError(errorCode);
	throw runtime_error(errorStr);
}


NetworkDispatcher::NetworkDispatcher(int addressType, int type, int protocol)
{
	WSADATA wdSockeMsg;
	
	int nRes = WSAStartup(MAKEWORD(2,2),&wdSockeMsg);

	if (nRes!=0) printNetworkError("WSAStartup()无法初始化......", nRes);
	
	this->connectionSocket = socket(addressType, type, protocol);
	
	if (this->connectionSocket == INVALID_SOCKET)
	{
		printNetworkError("Socket()无法创建......",WSAGetLastError());
	}
	this->addr = (sockaddr_in*)malloc(sizeof(sockaddr_in));
}

NetworkDispatcher::~NetworkDispatcher()
{
	closesocket(this->connectionSocket);
	delete this->addr;
	WSACleanup();
}

bool NetworkDispatcher::setAddress(unsigned short addr_fmily,const char* ip_address, int addr_post)
{
	
	this->addr->sin_family = addr_fmily;
	in_addr ip_addr;
	inet_pton(AF_INET, ip_address, &ip_addr);
	this->addr->sin_addr = ip_addr;
	this->addr->sin_port = htons(addr_post);
	this->addressReady = true;
	return true;
}

bool NetworkDispatcher::runServer()
{
	while (!this->connection_Status)
	{
		try
		{
			this->connectServer();
		}
		catch (const runtime_error& e)
		{
			cerr << e.what() << endl;
		}
	}
	cout << "[*]连接成功!" << endl;
	return true;
}

bool NetworkDispatcher::connectServer()
{
	if (!this->addressReady) return false;

	int sign = connect(this->connectionSocket, (sockaddr*)this->addr, sizeof(sockaddr));

	if (!(sign==0))
	{
		printNetworkError("connectServer连接失败....", sign);
		return false;
	}
	this->connection_Status = true;
	return true;
}

int NetworkDispatcher::sendData(const char* buf)
{
	if (!this->addressReady && this->connection_Status) {
		printNetworkError("没有初始化连接或没有设置ip等数据",999);
	}
	send(this->connectionSocket, buf,strlen(buf), 0);
	return 0;
}




