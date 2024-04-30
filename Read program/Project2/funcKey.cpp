#include "funcKey.h"

bool InstallHook()
{
    g_hook = SetWindowsHookEx(WH_KEYBOARD, KeybardProc,GetModuleHandle(L"key"),0);
	if (g_hook == NULL)
	{
		return false;
	}
	return true;
}

bool UninstallHook()
{
	return UnhookWindowsHookEx(g_hook);
}

LRESULT KeybardProc(int ncode, WPARAM wParam, LPARAM LParam)
{
	if (ncode < 0 || ncode == HC_NOREMOVE)
		return CallNextHookEx(g_hook, ncode, wParam, LParam);
}
