
#include <stdio.h>
#include <iostream>
#include<math.h>
#include <GL/glut.h>

# define PI 3.14159265

using namespace std;

struct point{
	int x, y, h;            // for  rotation make dataType double
}*p;

int npoints;

int scaleX[3][3] = {  	{10,0,0},
			{0,1,0},
			{0,0,1},
		   };
		
int scaleY[3][3] = {    {1,0,0},
			{0,10,0},
			{0,0,1},
		   };

int scaleXY[3][3] = { 	{10,0,0},
		      	{0,10,0},
		      	{0,0,1},
		    };	
		    
int translateX[3][3] = {  	{1,0,0},
			{0,1,0},
			{50,0,1},
		   };
		
int translateY[3][3] = {    {1,0,0},
			{0,1,0},
			{0,50,1},
		   };

int translateXY[3][3] = { 	{1,0,0},
		      	{0,1,0},
		      	{50,50,1},
		    };			    
		    
int reflectionX[3][3] =  {  	{1,0,0},
				{0,-1,0},
				{0,0,1},
		   	};
		   	
int reflectionY[3][3] =  {  	{-1,0,0},
				{0,1,0},
				{0,0,1},
		   	};		   			    	

double param = 60.0;
		
double rotationAntiCLock[3][3] = {	{ cos (param * PI / 180.0) , sin (param * PI / 180.0) , 0.0},
			     		{ -sin (param * PI / 180.0) , cos (param * PI / 180.0) , 0.0},
			    		{ 0.0 , 0.0 , 1.0 },
				 };				

void plotObject(point *p)
{
	glBegin(GL_POLYGON);
	
	for(int i=0; i<npoints; i++){
		glVertex2i(p[i].x, p[i].y);
	}	
	
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

point* transformation2d(point *p)
{	
	point *res = new point[npoints];
	
	int (*M)[3] = scaleX;		//double for rotation uncomment below for rotation
	
	/* rotation matrix
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<M[i][j]<<" ";
		}cout<<"\n";
	}
	*/
	
	for(int i=0; i<npoints; i++){
		
		res[i].x = p[i].x * M[0][0] + p[i].y * M[1][0] + p[i].h * M[2][0] ;
		res[i].y = p[i].x * M[0][1] + p[i].y * M[1][1] + p[i].h * M[2][1] ;
		res[i].h = p[i].x * M[0][2] + p[i].y * M[1][2] + p[i].h * M[2][2] ;
	}
	
	return res;
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	plotObject(p);
	
	point *res = transformation2d(p);
	
	plotObject(res);
	
	glFlush ();
}

int main(int argc, char** argv)
{
	cout << "\n Enter the number of points : "; cin >> npoints;
	
	p = new point[npoints];
	
	for(int i=0; i<npoints; i++){
		cout << "\n Enter the co-ordinate (x,y) of point "<< (i+1) << " : "; cin >> p[i].x >> p[i].y;
		p[i].h = 1;
	}
	

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
