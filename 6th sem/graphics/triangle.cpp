#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int X1, Y1, X2, Y2, X3, Y3;

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

void ddaAlgo(int x1, int y1, int x2, int y2)
{
	int dx = x2-x1;
	int dy = y2-y1;
	float X = x1;
	float Y = y1;
	
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	
	float incX = dx/(float)(steps);
	float incY = dy/(float)(steps);
	
	for(int i=1; i<=steps; i++){
		plot(X,Y);
		X += incX ;
		Y += incY ;
	}
}
void triangleDrawing(){
	ddaAlgo(X1,Y1,X2,Y2);
	ddaAlgo(X2,Y2,X3,Y3);
	ddaAlgo(X3,Y3,X1,Y1);
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	
	triangleDrawing();

	glFlush ();
}

int main(int argc, char** argv)
{	

	cout << "X1-coordinate : "; cin >> X1;
	cout << "\nY1-coordinate : "; cin >> Y1;
	cout << "\nX2-coordinate : "; cin >> X2;
	cout << "\nY2-coordinate : "; cin >> Y2;
	cout << "\nX3-coordinate : "; cin >> X3;
	cout << "\nY3-coordinate : "; cin >> Y3;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Triangle Drawing ");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}

