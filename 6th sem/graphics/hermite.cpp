
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

struct point{
	int x,y;
}P1,P2;

double r1,r2;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}



void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //specifies clear values for the color buffer, here it's white
	glColor3f(0.0f, 0.0f, 0.0f); //specifies the current values
	glPointSize(4.0); //specifies diameter of the rasterized points
	glMatrixMode(GL_PROJECTION); //specifies which matrix is the current matrix
	glLoadIdentity();  //replaces the current matrix with the identity matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void hermite(point P1, point P2, double r1, double r2)
{	
	double step = 0.01, x, y;
	
	for(double t=0.0; t<=1.0; t+=step){
		
		x = (2*t*t*t - 3*t*t + 1)*P1.x + (3*t*t - 2*t*t*t)*P2.x + (t*t*t - 2*t*t + t)*r1 + (t*t*t - t*t)*r2 ;
		y = (2*t*t*t - 3*t*t + 1)*P1.y + (3*t*t - 2*t*t*t)*P2.y + (t*t*t - 2*t*t + t)*r1 + (t*t*t - t*t)*r2 ;
		
		plot(x,y);
	}
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	hermite(P1,P2,r1,r2);
	
	glFlush ();
}

int main(int argc, char** argv)
{	
	cout << " point 1 : \n";
	cout << " Enter x co-ordinate : "; cin >> P1.x;
	cout << " Enter y co-ordinate : "; cin >> P1.y;
	cout << " Enter tangent slope at this point : "; cin >> r1;
	
	cout << " point 2 : \n";
	cout << " Enter x co-ordinate : "; cin >> P2.x;
	cout << " Enter y co-ordinate : "; cin >> P2.y;
	cout << " Enter tangent slope at this point : "; cin >> r2;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Hermite Curve");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}
