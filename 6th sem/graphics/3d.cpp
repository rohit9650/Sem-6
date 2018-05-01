
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include<math.h>

#define PI 3.14159265

using namespace std;

struct point{
	double x, y, z, h;
}*p;

int npoints;

int scaleX[4][4] = 	{ {5, 0, 0, 0},
			  {0, 1, 0, 0},
			  {0, 0, 1, 1},
			  {0, 0, 0, 1},	
			};
			
int scaleY[4][4] = 	{ {1, 0, 0, 0},
			  {0, 5, 0, 0},
			  {0, 0, 1, 1},
			  {0, 0, 0, 1},	
			};
			
int scaleZ[4][4] = 	{ {1, 0, 0, 0},
			  {0, 1, 0, 0},
			  {0, 0, 5, 1},
			  {0, 0, 0, 1},	
			};
			
float scaleAll[4][4] = 	{ {1, 0, 0, 0},
			  {0, 1, 0, 0},
			  {0, 0, 1, 1},
			  {0, 0, 0, 0.25},	
			};
			
int reflectionXY[4][4] = { {1, 0, 0, 0},
			   {0, 1, 0, 0},
			   {0, 0, -1, 1},
			   {0, 0, 0, 1},	
			 };
			 
int reflectionYZ[4][4] = { {-1, 0, 0, 0},
			   {0, 1, 0, 0},
			   {0, 0, 1, 1},
			   {0, 0, 0, 1},	
			 };
			 
int reflectionXZ[4][4] = { {1, 0, 0, 0},
			   {0, -1, 0, 0},
			   {0, 0, 1, 1},
			   {0, 0, 0, 1},	
			 };			 			 			
			
double angle = 60.0;

double rotationX[4][4] =  { 	{1, 0, 0, 0},
			  	{0, cos ( angle * PI / 180.0), sin ( angle * PI / 180.0), 0},
			 	{0, -sin ( angle * PI / 180.0), cos ( angle * PI / 180.0), 0},
			  	{0, 0, 0, 1},	
			    };	

double rotationY[4][4] =  { 	{cos ( angle * PI / 180.0), 0, -sin ( angle * PI / 180.0), 0},
			  	{0, 			    1, 			0, 	   0},
			 	{sin ( angle * PI / 180.0), 0, cos ( angle * PI / 180.0),  0},
			  	{0, 			    0, 			0, 	   1},	
			    };				    

double rotationZ[4][4] =  { 	{cos ( angle * PI / 180.0), sin ( angle * PI / 180.0), 0, 0},
			  	{-sin ( angle * PI / 180.0), cos ( angle * PI / 180.0), 0, 0},
			 	{0, 0, 1, 0},
			  	{0, 0, 0, 1},	
			    };				    										

void plotObject(point *p)
{
	glBegin(GL_POLYGON);
	
	for(int i=0; i<npoints; i++)	
		glVertex2i(p[i].x, p[i].y);
	
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

point * transformation3d(point *p)
{
	point *res = new point[npoints];
	
	double (*M)[4] = rotationZ;           // double for rotation (also un-somment below section) and float for overall scaling
	
	
	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	for(int i=0; i<npoints; i++){
		
		res[i].x = p[i].x * M[0][0] + p[i].y * M[1][0] + p[i].z * M[2][0] + p[i].h * M[3][0] ;
		res[i].y = p[i].x * M[0][1] + p[i].y * M[1][1] + p[i].z * M[2][1] + p[i].h * M[3][1] ;
		res[i].z = p[i].x * M[0][2] + p[i].y * M[1][2] + p[i].z * M[2][2] + p[i].h * M[3][2] ;
		res[i].h = p[i].x * M[0][3] + p[i].y * M[1][3] + p[i].z * M[2][3] + p[i].h * M[3][3] ;
		
	}
	
	return res;
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);
	
	plotObject(p);
	
	point *res = transformation3d(p);
	
	plotObject(res);

	glFlush ();
}

int main(int argc, char** argv)
{	
	cout << "\n Enter the number of points : "; cin >> npoints;
	
	p = new point[npoints];
	
	for(int i=0; i<npoints; i++){
		cout << "\n Enter the co-ordinate (x,y,z) of point "<< (i+1) << " : "; cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].h = 1;
	}
	
	for(int i=0; i<npoints; i++){
	 cout <<" "<< p[i].x <<" "<< p[i].y <<" "<< p[i].z;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("3D tranformation");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();
	return 0;
}
