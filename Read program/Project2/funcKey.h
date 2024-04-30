#pragma once
#include <Windows.h>

HHOOK g_hook;
bool InstallHook(); //安装钩子
bool UninstallHook(); //卸载钩子
LRESULT CALLBACK KeybardProc(int ncode, WPARAM wParam, LPARAM LParam);