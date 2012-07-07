#include "winapp.h"

WindowsApp::WindowsApp(HINSTANCE hinstance, LPCTSTR clsname, WNDPROC wndproc, LPCSTR menuname)
{
	ZeroMemory(&_wndcls, sizeof(_wndcls));
	_wndcls.style = CS_OWNDC;
	_wndcls.lpfnWndProc = wndproc;
	_wndcls.cbClsExtra = 0;
	_wndcls.cbWndExtra = 0;
	_wndcls.hInstance = hinstance;
	_wndcls.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	_wndcls.hCursor = LoadCursor( NULL, IDC_ARROW );
	_wndcls.hbrBackground = (HBRUSH)GetStockObject( WHITE_BRUSH );
	_wndcls.lpszMenuName = NULL;
	_wndcls.lpszClassName = "GLSample";
}

void WindowsApp::Register()
{
	RegisterClass(&_wndcls);
	int errx = GetLastError();
}