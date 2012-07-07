#include "mainwindow.h"
#include <gl\GL.h>

WWindow::WWindow()
{
	_hwnd = NULL;
	theta=0.0f;
}

WWindow::~WWindow()
{
}

HWND WWindow::Create(HINSTANCE hinst, LPCTSTR clsname, LPCTSTR wndname, HWND parent, DWORD dstyle, 
	DWORD dxstyle, int x, int y, int w, int h)
{
	_hwnd = CreateWindow( "GLSample", "OpenGL Sample", dstyle, x, y, w, h, parent, NULL, hinst, NULL );
	int errx = GetLastError();
	if (_hwnd != NULL)
		return _hwnd;
	return NULL;
}

WWindow::operator HWND()
{
	return _hwnd;
}

BOOL WWindow::Show(int dcmdshow)
{
	if (ShowWindow(_hwnd, dcmdshow) && UpdateWindow(_hwnd))
		return TRUE;
	else
		return FALSE;
}


void WWindow::EnableOpenGL()
{
	PIXELFORMATDESCRIPTOR pfd;
	int format;
	
	// get the device context (DC)
	hDC = GetDC( _hwnd );

	ZeroMemory( &pfd, sizeof( pfd ) );
	pfd.nSize = sizeof( pfd );
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	
	format = ChoosePixelFormat( hDC, &pfd );
	SetPixelFormat( hDC, format, &pfd);
	
	hRC = wglCreateContext(hDC );
	wglMakeCurrent( hDC, hRC );
	
}

void WWindow::DisableOpenGL()
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(_hwnd, hDC);

}
BOOL WWindow::Display()
{
			glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
			glClear( GL_COLOR_BUFFER_BIT );
			
			glPushMatrix();
			glRotatef( theta, 0.0f, 0.0f, 1.0f );
			
			glBegin( GL_TRIANGLES );
			glColor3f( 1.0f, 0.0f, 0.0f ); 
			glVertex2f( 0.0f, 0.0f );
			glColor3f( 0.0f, 1.0f, 0.0f ); 
			glVertex2f( 1.0f, 0.0f );
			glColor3f( 0.0f, 0.0f, 1.0f ); 
			glVertex2f( 0.5f, 1.0f );
			glEnd();
			glPopMatrix();
			
			SwapBuffers(hDC);
			
			theta += 1.0f;


	return TRUE;
}
