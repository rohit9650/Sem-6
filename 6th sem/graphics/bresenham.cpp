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

void bresenhamAlgo()
{
	int dx = X2-X1;
	int dy = Y2-Y1;
	
	int d = 2*dy - dx;
	
	int incE = 2*dy;
	int incNE = 2*(dy-dx);
	
	int X = X1;
	int Y = Y1;
	
	plot(X,Y);
	
	while(X<X2){
		
		if(d<0){
			d += incE;
		}
		else{
			d += incNE;
			Y++ ;
		}
		X++;
		plot(X,Y);
	}
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	bresenhamAlgo();

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
	glutCreateWindow ("Line Drawing Alogrithm Bresenhams");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}

