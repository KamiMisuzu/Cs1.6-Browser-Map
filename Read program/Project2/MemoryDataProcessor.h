#pragma once
#include "MemoryOffsetStorage.h"
#include <stdbool.h>
#include <Windows.h>
#include <stdlib.h> 
#include <psapi.h>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

class MemoryDataProcessor
{
public:
    // ���캯���������ڴ�ƫ�����洢���ָ��
    MemoryDataProcessor(MemoryOffsetStorage* mos);

    // ���õ�ǰģ������
    bool setCurrentmoduleName(string* moduleName);

    // ��ȡ�̶���ַ���������ƻ�ȡ�������ƵĹ̶���ַ
    int Getfixedaddress(const char* name);

    // �ݹ��ȡ��������
    int RecursiveReadInt(vector<int> panding, int devia, int pos);

    // �ݹ��ȡ����������
    float RecursiveReadFloat(int&& devia, int&& pos);

    // ��ȡ���������ݣ�4�ֽڣ�
    float ReadMemoryFloat_4(int&& ipAddress);

    // ��ȡ�������ݣ�4�ֽڣ�
    int ReadMemoryINT_4(int&& ipAddress);

    // ��ȡ�������ݣ�8�ֽڣ�
    int ReadMemoryINT_8(int&& ipAddress);

    // ��ȡ�ַ�������
    string ReadMemoryChar(int&& ipAddress, int&& lenght);

private:
    // ��ȡ�ڴ�Ѱַ
    int ReadMemoryAddressing(stack<int>* stk);

    // ��ǰ��ȡ�ֽڳ��ȣ�Ĭ��Ϊ4�ֽ�
    int currentReadByte = 4;

    // ��ǰģ���ַ��Ĭ��Ϊ-1
    int currentmoduleAddress = -1;

    // ��ǰģ������
    string moduleName;

    // �ڴ�ƫ�����洢��ָ��
    MemoryOffsetStorage* memoryDatasource = nullptr;

    // ���̾��
    HANDLE hProcess = nullptr;
};
