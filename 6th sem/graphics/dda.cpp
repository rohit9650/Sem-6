#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int X1, Y1, X2, Y2;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int abs(int n){
	return ( n>0 ? n : n*(-1));
}

void ddaAlgo()
{
	int dx = X2-X1;
	int dy = Y2-Y1;
	float X = X1;
	float Y = Y1;
	
	int steps = abs(dx) > abs(dy) ? dx : dy;
	
	float incX = dx/(float)(steps);
	float incY = dy/(float)(steps);
	
	for(int i=1; i<=steps; i++){
		plot(X,Y);
		X += incX ;
		Y += incY ;
	}
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	ddaAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{	

	cout << "X1-coordinate : "; cin >> X1;
	cout << "\nY1-coordinate : "; cin >> Y1;
	cout << "\nX2-coordinate : "; cin >> X2;
	cout << "\nY2-coordinate : "; cin >> Y2;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Line Drawing Alogrithm DDA");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}

