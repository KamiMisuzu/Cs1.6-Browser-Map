#pragma once
#include <Windows.h>

HHOOK g_hook;
bool InstallHook(); //��װ����
bool UninstallHook(); //ж�ع���
LRESULT CALLBACK KeybardProc(int ncode, WPARAM wParam, LPARAM LParam);