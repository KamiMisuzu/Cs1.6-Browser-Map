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
    // ���캯������ʼ�����������
    NetworkDispatcher(int addressType, int type, int protocol);

    // �����������ͷ���Դ
    ~NetworkDispatcher();

    // ���õ�ַ�����÷�������ַ�Ͷ˿�
    bool setAddress(unsigned short addr_family, const char* address, int addr_port);

    // ���з�����������������
    bool runServer();

    // �������ݣ������ӵĿͻ��˷�������
    int sendData(const char* buf);

    // ����״̬
    bool connection_Status = false;

private:
    // ���ӷ����������������������
    bool connectServer();

    // ��ַ�Ƿ�׼������
    bool addressReady = false;

    // ��ַ�ṹָ��
    sockaddr_in* addr;

    // �����׽���
    SOCKET connectionSocket;
};

