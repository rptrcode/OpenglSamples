#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Windows.h>
class WWindow 
{
public:
	WWindow();
	virtual ~WWindow();

	HWND Create(HINSTANCE hinst, LPCTSTR clsname, LPCTSTR wndname, HWND parent=NULL, DWORD dstyle = WS_OVERLAPPEDWINDOW, DWORD dxstyle = 0L, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int w = CW_USEDEFAULT, int h = CW_USEDEFAULT);
	BOOL Show(int dcmdshow = SW_SHOWNORMAL);
	operator HWND();
	BOOL Display();
	void EnableOpenGL();
	void DisableOpenGL();

protected:
	HWND _hwnd;
	HINSTANCE mhInst;

public:
	HINSTANCE GetInstance();

private:
	HDC hDC;
	HGLRC hRC;
	float theta;
};

#endif