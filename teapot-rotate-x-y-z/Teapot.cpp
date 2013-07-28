#include <Windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

float angle = 0.0f;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,15.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);

	glPushMatrix();
	glRotatef(angle, 0.0f,1.0f,0.0f);
	glColor3f(0.0f,0.0f,1.0f);
	glutWireTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,3.0f,0.0f);
	glRotatef(angle, 1.0f,0.0f,0.0f);
	glColor3f(1.0f,0.0f,1.0f);
	glutWireTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f,-3.0f,0.0f);
	glRotatef(angle, 0.0f,0.0f,1.0f);
	glRotatef(90, 1.0f,0.0f,0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutWireTeapot(1);
	glPopMatrix();

	angle += 0.5f;
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	if(height == 0)
		height = 1;

	float ratio = width * 1.0/height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0f,ratio,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);
}