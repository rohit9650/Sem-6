#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int X1, Y1, a, b;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+X1, y+Y1);
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

void midPointEllipseAlgo(){

	int x = 0;
	int y = b;
	int SQa = a^2;
	int SQb = b^2;
	double decision = SQb - (SQa * b) + (0.25 * SQa);
	double d2;
	plot(x, y);

	while (SQa*(y-0.5) > SQb*(x+1)){
	
		if (decision < 0){
		
			decision += SQb*(2*x + 3);
		}
		else{
			decision += SQb*(2*x + 3) + SQa*(-2*y + 2);
			y--;
		}
		x++;
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
	}
	
	d2 = SQb*((x + 0.5)*(x + 0.5)) + SQa*((y-1)*(y-1)) - SQa * SQb;
	
	while(y>0){
		if(d2<0){
			d2 += SQb*(2*x + 2) + SQa*(-2*y + 3);
			x++;
		}
		else{
			d2 += SQa*(-2*y + 3);
		}	
		y--;
		plot(x,y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);	
	}
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointEllipseAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{	
	cout << "Enter major axis length : "; cin>> a;
	cout << "Enter minor axis length : "; cin>> b;
	cout << "\nX1-coordinate : "; cin >> X1;
	cout << "\nY1-coordinate : "; cin >> Y1;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Ellipse Drawing Alogrithm Mid-Point");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}

