#include "NetworkDispatcher.h"

void outputNetworkError(int errorCode) {
	switch (errorCode)
	{
	case WSANOTINITIALISED:
		cout << "��ʹ�ô˺���֮ǰ������ɹ����� WSAStartup ��" << "\n";
		break;
	case WSAENETDOWN:
		cout << "������ϵͳ������ķ����ṩ�̷������ϡ�" << "\n";
		break;
	case WSAEAFNOSUPPORT:
		cout << "��֧��ָ���ĵ�ַϵ�С� ���磬Ӧ�ó�����Ϊ AF_IRDA ��ַϵ�д����׽��֣���δ�ڱ��ؼ�����ϰ�װ�������������豸��������" << "\n";
		break;
	case WSAEINPROGRESS:
		cout << "��ֹ Windows �׽��� 1.1 �������ڽ��У����߷����ṩ�����ڴ���ص�������" << "\n";
		break;
	case WSAEMFILE:
		cout << "�޷��ṩ�����׽�����������" << "\n";
		break;
	case WSAEINVAL:
		cout << "	�ṩ�Ĳ�����Ч�� ��� af ��������Ϊ AF_UNSPEC �����ͺ�Э�����δָ�����򷵻ش˴���" << "\n";
		break;
	case WSAEINVALIDPROVIDER:
		cout << "�����ṩ�̷����� 2.2 ����İ汾��" << "\n";
		break;
	case WSAEINVALIDPROCTABLE:
		cout << "�����ṩ���� WSPStartup ��������Ч�������Ĺ��̱�" << "\n";
		break;
	case WSAENOBUFS:
		cout << "δ�ṩ�κλ������ռ䡣 �޷������׽��֡�" << "\n";
		break;
	case WSAEPROTONOSUPPORT:
		cout << "ָ����Э�鲻��֧�֡�" << "\n";
		break;
	case WSAEPROTOTYPE:
		cout << "ָ����Э���Ǵ��׽��ֵĴ������͡�" << "\n";
		break;
	case WSAEPROVIDERFAILEDINIT:
		cout << "�����ṩ�����ʼ��ʧ�ܡ� ����ֲ�����ṩ���� (LSP) �������ռ��ṩ����װ����ȷ���ṩ�����޷��������У��򷵻ش˴���" << "\n";
		break;
	case WSAESOCKTNOSUPPORT:
		cout << "�ڴ˵�ַϵ���У���֧��ָ�����׽������͡�" << "\n";
	case WSASYSNOTREADY:
		cout << "����������ϵͳ��δ׼���ý�������ͨ�š�" << "\n";
		break;
	case WSAVERNOTSUPPORTED:
		cout << "���ض� Windows �׽���ʵ�ֲ��ṩ������� Windows �׽���֧�ְ汾����" << "\n";
		break;
	case WSAEPROCLIM:
		cout << "�Ѵﵽ Windows �׽���ʵ��֧�ֵ����������ơ�" << "\n";
		break;
	case WSAEFAULT:
		cout << "lpWSAData ����������Ч��ָ��" << "\n";
		break;
	case WSAEADDRINUSE:
		cout << "�׽��ֵı��ص�ַ����ʹ���У�����δ���׽��ֱ��Ϊ����ʹ�� SO_REUSEADDR ���õ�ַ��" << endl;
		break;
	case WSAEINTR:
		cout << "������ Windows �׽��� 1.1 ������ͨ�� WSACancelBlockingCall ȡ����" << endl;
		break;
	case WSAEALREADY:
		cout << "����ָ�����׽����Ͻ��з���ֹ���ӵ��á�" << endl;
		break;
	case WSAEADDRNOTAVAIL:
		cout << "Զ�̵�ַ������Ч�ĵ�ַ (���� INADDR_ANY �� in6addr_any) ��" << endl;
		break;
	case WSAECONNREFUSED:
		cout << "�������ӱ�ǿ���Ծܾ���" << endl;
		break;
	case WSAEISCONN:
		cout << "���������ӵ��׽��������ӡ�" << endl;
		break;
	case WSAENETUNREACH:
		cout << "��ʱ�����ԴӴ��������ʸ����硣" << endl;
		break;
	case WSAEHOSTUNREACH:
		cout << "�׽��ֲ������Է����޷����ʵ�������" << endl;
		break;
	case WSAENOTSOCK:
		cout << "�����������׽��֡�" << endl;
		break;
	case WSAETIMEDOUT:
		cout << "�������ӳ�ʱ����δ�������ӡ�" << endl;
		break;
	case WSAEWOULDBLOCK:
		cout << "�׽��ֱ��Ϊ����ֹ���޷�����������ӡ�" << endl;
		break;
	case WSAEACCES:
		cout << "���Խ����ݱ��׽������ӵ��㲥��ַʧ�ܣ���Ϊδ���� SO_BROADCAST��" << endl;
		break;
	default:
		cout << "δ֪�����룺" << errorCode << endl;
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

	if (nRes!=0) printNetworkError("WSAStartup()�޷���ʼ��......", nRes);
	
	this->connectionSocket = socket(addressType, type, protocol);
	
	if (this->connectionSocket == INVALID_SOCKET)
	{
		printNetworkError("Socket()�޷�����......",WSAGetLastError());
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
	cout << "[*]���ӳɹ�!" << endl;
	return true;
}

bool NetworkDispatcher::connectServer()
{
	if (!this->addressReady) return false;

	int sign = connect(this->connectionSocket, (sockaddr*)this->addr, sizeof(sockaddr));

	if (!(sign==0))
	{
		printNetworkError("connectServer����ʧ��....", sign);
		return false;
	}
	this->connection_Status = true;
	return true;
}

int NetworkDispatcher::sendData(const char* buf)
{
	if (!this->addressReady && this->connection_Status) {
		printNetworkError("û�г�ʼ�����ӻ�û������ip������",999);
	}
	send(this->connectionSocket, buf,strlen(buf), 0);
	return 0;
}




