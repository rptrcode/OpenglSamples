#include "winctrls.h"


ATOM RegWnd(HINSTANCE hinst);
LRESULT CALLBACK WndProcedure(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevhinst, LPCTSTR lpcmdline, int ncmdshow)
{
	WNDCLASSEX wndclsex; //window class
	HINSTANCE hInst;

	MSG msg;
	hInst = hInstance;

	wndclsex.cbSize = sizeof(WNDCLASSEX);  //size of the structure
	wndclsex.style = CS_HREDRAW | CS_VREDRAW; //class styles - redraw if any changes in Width and Height of client area
	wndclsex.lpfnWndProc = WndProcedure; //ptr to windowprocedure - fn that processes window messages
	wndclsex.cbClsExtra = 0; // extra bytes following windowclass struct
	wndclsex.cbWndExtra = 0; //extra bytes following window instance
	wndclsex.hIcon = LoadIcon(NULL, IDI_APPLICATION); //handle to icon resource
	wndclsex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclsex.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wndclsex.lpszClassName = "basic app";
	wndclsex.lpszMenuName = NULL;
	wndclsex.hInstance = hInst;
	wndclsex.hIconSm = LoadIcon(NULL, IDI_APPLICATION); //handle to icon resource

	return RegisterClassEx(&wndclsex);
}

LRESULT CALLBACK WndProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparm)
{
	switch(msg)
	{
	case WM_CREATE: 
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hwnd, msg, wparam, lparm);
	}

	return 0;
}