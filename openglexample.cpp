#include <windows.h>
#include "winapp.h"
#include "mainwindow.h"

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

INT WINAPI WinMain(HINSTANCE hinst, HINSTANCE hprev, LPSTR lpcmdline, int cmdshow)
{
	MSG msg;
	LPCTSTR clsname = "myappclass";
	LPCTSTR wndname = "myapp";
	BOOL quit=false;

	WindowsApp WinApp(hinst, clsname, MainWndProc);
	WinApp.Register();

	WWindow wnd;
	wnd.Create(hinst, clsname, wndname);
	wnd.EnableOpenGL();
	wnd.Show();

	while(!quit)
	{
		if( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
				quit = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			wnd.Display();
		}
	}

	wnd.DisableOpenGL();
	return 0;
}

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch(msg)
	{
	case WM_CREATE:
		return 0;
		
	case WM_CLOSE:
		PostQuitMessage( 0 );
		return 0;
		
	case WM_DESTROY:
		return 0;

	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}