#include <Windows.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

void display();
void reshape(int width, int height);

int main(int argc, char ** argv) 
{
	glutInit(&argc, argv);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow("hello!");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutMainLoop();
}
