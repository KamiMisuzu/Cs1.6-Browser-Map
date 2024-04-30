#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>
#include <Winerror.h>


using namespace std;
#pragma comment(lib,"ws2_32.lib")
class NetworkDispatcher
{
public:
    // 构造函数：初始化网络调度器
    NetworkDispatcher(int addressType, int type, int protocol);

    // 析构函数：释放资源
    ~NetworkDispatcher();

    // 设置地址：设置服务器地址和端口
    bool setAddress(unsigned short addr_family, const char* address, int addr_port);

    // 运行服务器：启动服务器
    bool runServer();

    // 发送数据：向连接的客户端发送数据
    int sendData(const char* buf);

    // 连接状态
    bool connection_Status = false;

private:
    // 连接服务器：与服务器建立连接
    bool connectServer();

    // 地址是否准备就绪
    bool addressReady = false;

    // 地址结构指针
    sockaddr_in* addr;

    // 连接套接字
    SOCKET connectionSocket;
};

