// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <iostream>

using namespace std;

// Global Variable Section
// List all of your global variables, stuctures and other definition here
// Window display size
GLsizei winWidth = 600, winHeight = 400;
int map;
int help;
int objects;

// Initialize method
void init(void)
{
	// Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString(GL_VERSION);
	fprintf(stderr, "Your OpenGL version is %s\n", Vstr);

	// White color window
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Projection on World Coordinates 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight / 2, (GLdouble)winHeight / 2);

}

GLubyte fish[] = {
	0x00, 0x60, 0x01, 0x00,
	0x00, 0x90, 0x01, 0x00,
	0x03, 0xf8, 0x02, 0x80,
	0x1c, 0x37, 0xe4, 0x40,
	0x20, 0x40, 0x90, 0x40,
	0xc0, 0x40, 0x78, 0x80,
	0x41, 0x37, 0x84, 0x80,
	0x1c, 0x1a, 0x04, 0x80,
	0x03, 0xe2, 0x02, 0x40,
	0x00, 0x11, 0x01, 0x40,
	0x00, 0x0f, 0x00, 0xe0,
};

void helpCode()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to Red or change for your choice
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.5f, 0.7f);
	//glBitmap(20.0, 20.0, 0.0, 0.0, -920.0, -405.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glBitmap(20.0, 20.0, 0.0, 0.0, -40.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'K');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glBitmap(20.0, 20.0, 0.0, 0.0, -160.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'D');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glBitmap(20.0, 20.0, 0.0, 0.0, -100.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'G');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'D');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glBitmap(20.0, 20.0, 0.0, 0.0, -120.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glBitmap(20.0, 20.0, 0.0, 0.0, -100.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'D');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	


	// Execute OpenGL functions
	glFlush();
}

void objectCode()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to Red or change for your choice
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.10f, -0.10f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.10f, 0.0f);
	glEnd();

	//The SUB/Whale
	glColor3f(1, 0, 0);
	glRasterPos3f(0.2f, -0.30f, 0.0);
	glBitmap(27, 11, 0, 0, 0, 0, fish);


	/*Spaceship BOMBER*/
	glTranslatef(0.1f, 0.1f, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, -0.7, 0);
	glVertex3f(0.12, -0.9, 1);
	glVertex3f(0.13f, -0.73, 1);
	glVertex3f(0.5, -0.7, 1);
	glVertex3f(0.13f, -0.67, 1);
	glVertex3f(0.12, -0.5, 1);
	glEnd();

	/*ICBM*/
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.5, 0.2, 0);
	glVertex3f(-0.45, 0.15, 1);
	glVertex3f(-0.2f, 0.15, 1);
	glVertex3f(-0.2, 0.25, 1);
	glVertex3f(-0.45f, 0.25, 1);
	glVertex3f(-0.5, 0.2, 1);
		glEnd();


		/*B2 BOMBER*/

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.5, 0.4, 0);
		glVertex3f(0.7, 0.2, 1);
		glVertex3f(0.63f, 0.37, 1);
		glVertex3f(0.65, 0.4, 1);
		glVertex3f(0.63f, 0.43, 1);
		glVertex3f(0.7, 0.6, 1);

		glEnd();

		/*Artillery*/
		glPushMatrix();
		glColor3f(1, 0, 0);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glRectf(-0.50f, 0.2f, -0.4f, 0.4f);
		glPopMatrix();


	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.5f, 0.7f);
	//glBitmap(20.0, 20.0, 0.0, 0.0, -920.0, -405.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'J');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glBitmap(20.0, 20.0, 0.0, 0.0, -100.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
	glBitmap(20.0, 20.0, 0.0, 0.0, 100.0, -40.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glBitmap(20.0, 20.0, 0.0, 0.0, -380.0, -30.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glBitmap(20.0, 20.0, 0.0, 0.0, -40.0, -60.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glBitmap(20.0, 20.0, 0.0, 0.0, -100.0, -45.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'K');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '/');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glBitmap(20.0, 20.0, 0.0, 0.0, -200.0, -80.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');




	// Execute OpenGL functions
	glFlush();
}




void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Set  graphic objects color to Red or change for your choice 
	glColor3f(0.0, 0.0, 1.0);
	//The  
	glColor3f(0.85, 0.64, 0.52);
	glRectf(-1.0f, -0.35f, 1.0f, 0.35f);
	//The Sky 
	glColor3f(0.0, 0.5, 0.9);
	glRectf(-1.0f, 0.35f, 1.0f, 1.0f);
	//The Water 
	glColor3f(0.0, 0.2, 1.3);
	glRectf(-1.0f, -0.35f, 1.0f, -1.0f);

	//The SUB/Whale
	glColor3f(1, 0, 0);
	glRasterPos3f(0.8f, -0.60f, 0.0);
	glBitmap(27, 11, 0, 0, 0, 0, fish);

	//The War Ship
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.60f, -0.37f, 0.0f);
	glVertex3f(0.60f, -0.47f, 0.0f);
	glVertex3f(0.50f, -0.37f, 0.0f);
	glVertex3f(0.50f, -0.47f, 0.0f);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.40f, -0.37f, 0.0f);
	glVertex3f(0.40f, -0.47f, 0.0f);
	glVertex3f(0.30f, -0.37f, 0.0f);
	glVertex3f(0.30f, -0.47f, 0.0f);
	glEnd();

	
	/*Ground*/
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.08, 0.56, 0.002);
	glVertex3f(-1, -1, 0);
	glVertex3f(0, -1, 1);
	glVertex3f(-0.5f, -0.5f, 1);
	glVertex3f(-0.5f, 0, -1);
	glVertex3f(-0.8f, 0.1f, -1);
	glVertex3f(-1, 0.4f, 1);
	glEnd();

	/*Artillery*/
	glPushMatrix();
	glColor3f(1, 0, 0);
	glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
	glRectf(-0.70f, -0.6f, -0.6f, -0.4f);
	glPopMatrix();

	/*B2 BOMBER*/
	
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0);
	glVertex3f(0.7, -0.2, 1);
	glVertex3f(0.63f, -0.03, 1);
	glVertex3f(0.65, 0.0, 1);
	glVertex3f(0.63f, 0.03, 1);
	glVertex3f(0.7, 0.2, 1);

	glEnd();

	/*Spaceship BOMBER*/
	glTranslatef(0.1f, 0.1f, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.12, 0.3, 1);
	glVertex3f(0.13f, 0.47, 1);
	glVertex3f(0.5, 0.5, 1);
	glVertex3f(0.13f, 0.53, 1);
	glVertex3f(0.12, 0.7, 1);

	glEnd();
	
		/*ICBM*/
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.3, 0.7, 0);
	glVertex3f(0.35, 0.65, 1);
	glVertex3f(0.6f, 0.65, 1);
	glVertex3f(0.6, 0.75, 1);
	glVertex3f(0.35f, 0.75, 1);
	glVertex3f(0.3, 0.7, 1);

	glEnd();
	

	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-1.0f, -0.85f);
	//glBitmap(20.0, 20.0, 0.0, 0.0, -920.0, -405.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'J');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glBitmap(20.0, 20.0, 0.0, 0.0, -120.0, -40.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 's');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 't');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'e');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'n');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 't');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'u');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'r');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'y');
	

	// Execute OpenGL functions
	glFlush();
}



// Windows redraw function
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight / 2, (GLdouble)winHeight / 2);
	glClear(GL_COLOR_BUFFER_BIT);
}

// Main function
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set initial Window position
	glutInitWindowPosition(100, 100);
	// Set Window Size
	glutInitWindowSize(winWidth, winHeight);

	// Set Window Title

	glutInitWindowSize(winWidth, winHeight);

	// Set Window Title
	help = glutCreateWindow("Help Menu");
	objects = glutCreateWindow("Object List");
	glutInitWindowPosition(100, 100);
	map = glutCreateWindow("Game Map");

	glutSetWindow(map);
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	//glutIdleFunc(display);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);

	glutSetWindow(help);
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(helpCode);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);


	glutSetWindow(objects);
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(objectCode);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);


	glutMainLoop();
}