
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

struct point{
	int x,y;
}P1,P2,P3,P4;

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

void bezier(point P1, point P2, point P3, point P4)
{
	double step = 0.01, t, x, y;
	
	for(t=0.0; t<=1.0; t += step){
		
		x = ((1-t)*(1-t)*(1-t))*P1.x + (3*t*(1-t)*(1-t))*P2.x + (3*t*t*(1-t))*P3.x + (t*t*t)*P4.x ;
		y = ((1-t)*(1-t)*(1-t))*P1.y + (3*t*(1-t)*(1-t))*P2.y + (3*t*t*(1-t))*P3.y + (t*t*t)*P4.y ;
		
		plot(x,y);
	}
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	
	bezier(P1,P2,P3,P4);

	glFlush ();
}

int main(int argc, char** argv)
{
	cout << "\n Point 1\n";
	cout << " Enter x co-ordinate : "; cin >> P1.x;
	cout << " Enter y co-ordinate : "; cin >> P1.y;
	
	cout << "\n Point 2\n";
	cout << " Enter x co-ordinate : "; cin >> P2.x;
	cout << " Enter y co-ordinate : "; cin >> P2.y;

	cout << "\n Point 3\n";
	cout << " Enter x co-ordinate : "; cin >> P3.x;
	cout << " Enter y co-ordinate : "; cin >> P3.y;

	cout << "\n Point 4\n";
	cout << " Enter x co-ordinate : "; cin >> P4.x;
	cout << " Enter y co-ordinate : "; cin >> P4.y;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Bezier Curve");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}
