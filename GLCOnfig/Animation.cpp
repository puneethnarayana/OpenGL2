// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <iostream>
#define _USE_MATH_DEFINES // for C++
#include <cmath>

using namespace std;

// Global Variable Section
// List all of your global variables, stuctures and other definition here
// Window display size
GLsizei WIDTH = 1500, HEIGHT = 1000;
int SLEEPMS = 1000;
int xpos=0, ypos=0, xpos2, ypos2, AMP = 100, TS=1, F0 = 4;
double M_PI = 3.14;



// Initialize method
void init(void)
{
	// Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString(GL_VERSION);
	fprintf(stderr, "Your OpenGL version is %s\n", Vstr);
	// Set background color to black 
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Maximize depth display
	glClearDepth(1.0f);
	// Enable depth testing for z-culling
	glEnable(GL_DEPTH_TEST);
	// Set the type of depth-test
	glDepthFunc(GL_LEQUAL);
	// Provide smooth shading
	glShadeModel(GL_SMOOTH);


}

// Controls the x and y positions using damped sin wave
void rotateHex(void)
{
	Sleep(SLEEPMS);
	// xpos
	xpos += 1;
	ypos = fabs(AMP*sin(2 * M_PI*F0*TS*xpos)*exp(0.0*TS));

	// Resent if get out of window position
	if (xpos > WIDTH)
	{
		xpos = 1;
	}
	// xpos2
	xpos2 += 1;
	ypos2 = fabs(AMP*sin(2 * M_PI*F0*TS*xpos2)*exp(0.0*TS));

	// Reset if get out of window position
	if (xpos2 > WIDTH)
	{
		xpos2 = 1;
	}
	glutPostRedisplay();
}


void displayFcn() {
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to Red or change for your cglColor3f(0.0, 1.0, 0.0);
	// Your graphics code here  

	// Create a rectangle to move about
	glRectf(xpos, ypos, xpos + 10, ypos + 10);

	// Set  color to Blue
	glColor3f(0.0, 0.0, 1.0);
	// Create a rectangle to move about
	glRectf(xpos2, ypos2, xpos2 + 10, ypos2 + 10);
	// Call the SwapBuffers
	glutSwapBuffers();
	// Execute OpenGL functions
	glFlush();

	
	}

// Left mouse starts the animation
// Right mouse stops the animation
void mouseFcn(GLint button, GLint action, GLint x, GLint y)
{

	switch (button) {
	case GLUT_LEFT_BUTTON:           //  Start the animation.
		if (action == GLUT_DOWN)
			glutIdleFunc(rotateHex);
		break;
	case GLUT_RIGHT_BUTTON:            //  Stop the animation.
		if (action == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}
// Clicking ‘1’ starts the animation
// Clicking ‘2’ stops the animation

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '1':   /*  1 key starts the animation  */
		glutIdleFunc(rotateHex);
		break;
	case '2': /*  2 key stops the animation  */
		glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

// Windows redraw function
void winReshapeFcn(GLsizei width, GLsizei height) {
	// Compute aspect ratio of the new window
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport 
	// Allows for resizing without major display issues
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Enable perspective projection with fovy, aspect, zNear and zFar
	// This is the camera view and objects align with view frustrum 
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// Main function
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Set initial Window position
	glutInitWindowPosition(100, 100);
	// Set Window Size
	glutInitWindowSize(WIDTH, HEIGHT);
	// Set Window Title
	glutCreateWindow("Animation");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	// Mouse and Keboard functions calls
	glutMouseFunc(mouseFcn);
	glutKeyboardFunc(keyboard);
	glutMainLoop();


}