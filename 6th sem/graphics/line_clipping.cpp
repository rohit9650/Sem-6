#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
 
// Defining x_max, y_max and x_min, y_min for

const int x_max = 300;
const int y_max = 300;
const int x_min = 40;
const int y_min = 40;

double x1, y1, x2, y2;

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

void ddaAlgo(int X1, int Y1, int X2, int Y2)
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

// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    // initialized as being inside 
    int code = INSIDE;
 
    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;
 
    return code;
}

void lineClippingAlgo(){

    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
 
    // Initialize line as outside the rectangular window
    bool accept = false;
 
    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            double x, y;
 
            // At least one endpoint is outside the 
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
 
            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
 
            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout <<"Line accepted from " << x1 << ", "
             << y1 << " to "<< x2 << ", " << y2 << endl;
             
        // Here the user can add code to display the rectangle
        // along with the accepted (portion of) lines
	ddaAlgo(x_min,y_min,x_max,y_min); 
	ddaAlgo(x_max,y_min,x_max,y_max);      
	ddaAlgo(x_max,y_max,x_min,y_max);
	ddaAlgo(x_min,y_max,x_min,y_min); 
        ddaAlgo(x1,y1,x2,y2);
    }
    else
        cout << "Line rejected" << endl;
}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	lineClippingAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{	

	cout << "\nX1-coordinate : "; cin >> x1;
	cout << "\nY1-coordinate : "; cin >> y1;
	cout << "\nX2-coordinate : "; cin >> x2;
	cout << "\nY2-coordinate : "; cin >> y2;


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

