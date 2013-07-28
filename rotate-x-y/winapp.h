#pragma once
#include <windows.h>

class WindowsApp
{
public:
	WindowsApp(HINSTANCE hinstance, LPCTSTR clsname, WNDPROC wndproc, LPCSTR menuname = NULL);
	void Register();
protected:
	WNDCLASS _wndcls;
};
