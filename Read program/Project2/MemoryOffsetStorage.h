#pragma once
#include <iostream>
#include <stack>
#include <map>
#include <Windows.h>
#include <memory>
#include <Psapi.h>
#include <vector>
using namespace std;

// �ڴ�ƫ�����洢��
class MemoryOffsetStorage
{
public:
    // ���캯����ͨ������Ĵ���������ʼ���࣬��ȡ����PID����ȡ���ƾ��
    MemoryOffsetStorage(const wchar_t* windowClassName);

    // ���캯��������������ʼ��
    MemoryOffsetStorage(int authority, bool bol, DWORD pid);

    // ��ʼ��ģ�����ݣ�ͨ�����������еľ�����ݻ�ȡ�����е�ģ�������ַ
    bool initModuledata();

    // �����ַӳ�䣺���ַӳ���в�������
    bool insertAddressMap(const char* sign, vector<int>* offsetArr, int endoffset);

    // �����������
    //bool inserpendingData(const char* name, vector<int>&& data);

    // ��ȡ��ַӳ�䣺�������ƻ�ȡ�������Ƶĵ�ַӳ��
    stack<int>* getAddressMap(const char* name);

    // ��ȡ����ƫ�������������ƻ�ȡ�������ƵĽ���ƫ����
    int getEndOffset(const char* name);

    // ��ȡ�ദ�����
    HANDLE& getClassProcess();

    // ��ȡģ���ַ���������ƻ�ȡ�������Ƶ�ģ���ַ
    int getModuleAddress(string* name);

private:
    // ���ģ���ַ������ģ������ģ���ַ
    bool addModuleAddress(string&& name, int address);

    // ��ӽ���ƫ�����������ʶ�������ƫ����
    bool addEndOffset(string&& sign, int endoff);

private:
    // ��ַӳ��
    map<string, stack<int>> addressMap;

    // ����ƫ����
    map<string, int> endOffset;

    // ��������
    // map<string, vector<int>> pendingData;

    // ���̾��
    HANDLE hProcess;

    // ����ID
    DWORD pid;

    // ģ���ַӳ��
    map<string, int> moduleAddress;
};


inline string strSplit(string&& a, const char&& sign);