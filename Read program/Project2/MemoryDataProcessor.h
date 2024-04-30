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
    // 构造函数：传入内存偏移量存储类的指针
    MemoryDataProcessor(MemoryOffsetStorage* mos);

    // 设置当前模块名称
    bool setCurrentmoduleName(string* moduleName);

    // 获取固定地址：根据名称获取给定名称的固定地址
    int Getfixedaddress(const char* name);

    // 递归读取整型数据
    int RecursiveReadInt(vector<int> panding, int devia, int pos);

    // 递归读取浮点型数据
    float RecursiveReadFloat(int&& devia, int&& pos);

    // 读取浮点型数据（4字节）
    float ReadMemoryFloat_4(int&& ipAddress);

    // 读取整型数据（4字节）
    int ReadMemoryINT_4(int&& ipAddress);

    // 读取整型数据（8字节）
    int ReadMemoryINT_8(int&& ipAddress);

    // 读取字符型数据
    string ReadMemoryChar(int&& ipAddress, int&& lenght);

private:
    // 读取内存寻址
    int ReadMemoryAddressing(stack<int>* stk);

    // 当前读取字节长度，默认为4字节
    int currentReadByte = 4;

    // 当前模块地址，默认为-1
    int currentmoduleAddress = -1;

    // 当前模块名称
    string moduleName;

    // 内存偏移量存储类指针
    MemoryOffsetStorage* memoryDatasource = nullptr;

    // 进程句柄
    HANDLE hProcess = nullptr;
};
