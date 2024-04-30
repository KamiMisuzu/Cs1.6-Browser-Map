#pragma once
#include <iostream>
#include <stack>
#include <map>
#include <Windows.h>
#include <memory>
#include <Psapi.h>
#include <vector>
using namespace std;

// 内存偏移量存储类
class MemoryOffsetStorage
{
public:
    // 构造函数：通过传入的窗口类名初始化类，获取程序PID，获取控制句柄
    MemoryOffsetStorage(const wchar_t* windowClassName);

    // 构造函数：用于其他初始化
    MemoryOffsetStorage(int authority, bool bol, DWORD pid);

    // 初始化模块数据：通过保存在类中的句柄数据获取程序中的模块名与地址
    bool initModuledata();

    // 插入地址映射：向地址映射中插入数据
    bool insertAddressMap(const char* sign, vector<int>* offsetArr, int endoffset);

    // 插入待定数据
    //bool inserpendingData(const char* name, vector<int>&& data);

    // 获取地址映射：根据名称获取给定名称的地址映射
    stack<int>* getAddressMap(const char* name);

    // 获取结束偏移量：根据名称获取给定名称的结束偏移量
    int getEndOffset(const char* name);

    // 获取类处理对象
    HANDLE& getClassProcess();

    // 获取模块地址：根据名称获取给定名称的模块地址
    int getModuleAddress(string* name);

private:
    // 添加模块地址：保存模块名与模块地址
    bool addModuleAddress(string&& name, int address);

    // 添加结束偏移量：保存标识符与结束偏移量
    bool addEndOffset(string&& sign, int endoff);

private:
    // 地址映射
    map<string, stack<int>> addressMap;

    // 结束偏移量
    map<string, int> endOffset;

    // 待定数据
    // map<string, vector<int>> pendingData;

    // 进程句柄
    HANDLE hProcess;

    // 进程ID
    DWORD pid;

    // 模块地址映射
    map<string, int> moduleAddress;
};


inline string strSplit(string&& a, const char&& sign);