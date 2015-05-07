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
#define M_PI 3.14159265358979323846
using namespace std;

// Global Variable Section
// List all of your global variables, stuctures and other definition here
// Window display size
GLsizei winWidth = 800, winHeight = 600;
int map;

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

GLfloat randomFloat() {
	return (GLfloat)rand() / RAND_MAX;
}


// Generate the Graphics
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);
	// Set  graphic objects color to of your choice
	
	//Green Triangle
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -0.1f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glEnd();

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.0f, -0.34f, 0.0);
	//glScalef(0.5f, 0.3f, 1.0f);
	glRotatef(-180.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -0.1f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(-0.3f, 0.0f, 0.0);
	glScalef(1.5f, 1.3f, 1.0f);
	glRotatef(145.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -0.1f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glEnd();

	glColor3f(1.0, 0.0, 0.340);
	glTranslatef(-0.3f, 0.0f, 0.0);
	glScalef(1.5f, 1.3f, 1.0f);
	glRotatef(145.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -0.1f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glEnd();

	glColor3f(1.0, 0.450, 0.550);
	glTranslatef(-0.3f, 0.0f, 0.0);
	glScalef(1.5f, 1.3f, 1.0f);
	glRotatef(145.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -0.1f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glEnd();
	glPopMatrix();

	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(0.33f, -0.67f, 0.0f);
	glVertex3f(0.46f, -0.67f, 0.0f);
	glVertex3f(0.33, -0.43f, 0.0f);
	glVertex3f(0.45f, -0.485f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	//Ground Line
	glColor3f(0.4256, 0.207, 0.101);
	glVertex2f(-1.0f, -0.67f);
	glVertex2f(1.0f, -0.67f);
	glEnd();

	//The Ground 
	glColor3f(0.85, 0.64, 0.52);
	glRectf(-1.0f, -0.67f, 1.0f, -1.0f);

	//The Cactus 1
	glPushMatrix();
	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();

	//The Cactus 2
	glTranslatef(-0.20f, -0.35f, 0.0);
	glScalef(0.5f, 0.5f, 1.0f);
	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();

	//The Cactus 3
	glColor3f(0.08, 0.56, 0.002);
	glTranslatef(0.60f, 0.10f, 0.0);
	glScalef(1.2f, 1.2f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();

	//The Cactus 4
	glColor3f(0.08, 0.56, 0.002);
	glTranslatef(0.60f, 0.10f, 0.0);
	glScalef(1.2f, 2.0f, 1.0f);
	glColor3f(0.08, 0.56, 0.002);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();
	
	//The Cactus 5
	glColor3f(0.08, 0.56, 0.002);
	glColor3f(0.08, 0.56, 0.002);
	glTranslatef(0.80f, 0.10f, 0.0);
	glScalef(1.2f, 1.2f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();

	//The Cactus 5
	glColor3f(0.08, 0.56, 0.002);
	glColor3f(0.08, 0.56, 0.002);
	glTranslatef(-0.80f, 0.8f, 0.0);
	glScalef(0.8f, 2.2f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-0.60f, -0.67f, 0.0f);
	glVertex3f(-0.50f, -0.67f, 0.0f);
	glVertex3f(-0.60f, -0.23f, 0.0f);
	glVertex3f(-0.50f, -0.285f, 0.0f);
	glEnd();

	glPopMatrix();

	// Begin accumulating matrix operations  
	glPushMatrix();
	// Draw the Initial Rectangle  
	glColor3f(0.0, 0.0, 0.0);
	glRectf(-1.0f, 1.0f, -0.2f, 0.8f);

	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.2f, 0.0);
	glRectf(-1.0f, 1.0f, -0.2f, 0.8f);
	
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, -0.2f, 0.0);
	glRectf(-1.0f, 1.0f, -0.2f, 0.8f);
	
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-0.2f, -0.4f, 0.0);
	//glScalef(0.5f, 0.3f, 1.0f);
	glRotatef(-15.0f, 0.0f, 0.0f, 1.0f);
	glRectf(-1.0f, 1.0f, -0.2f, 0.8f);
	// Draw the third rectangle (rotated another 45 degree)
	glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
	//glScalef(0.5f, 0.5f, 1.0f);
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(-0.4f, -0.6f, 0.0);
	glRectf(-1.0f, 1.0f, -0.2f, 0.8f);
	// Reset geometric transformation matrix
	glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
	//glScalef(0.5f, 0.5f, 1.0f);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.4f, -0.6f, 0.0);
	glRectf(-1.0f, 1.0f, -0.2f, 0.8f);
	glPopMatrix();

	
	double vertex5[] = { 0, 0 };
	double vertex6[] = { 100, 100 };
	glColor3f(0.6, 0.7, 0.9);
	glRectdv(vertex5, vertex6);

	for (int i = 0; i < 20; i++) {
		glColor3f(randomFloat(), randomFloat(), randomFloat());
		glRasterPos3f(randomFloat(), randomFloat(), 0.0);
		glBitmap(27, 11, 0, 0, 0, 0, fish);
	}


	glColor3f(1, 0.0, 0.0);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, 200.0, -18.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');
	glBitmap(20.0, 20.0, 0.0, 0.0, -80.0, -20.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '8');
	glBitmap(20.0, 20.0, 0.0, 0.0, -700.0, -200.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'W');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glBitmap(20.0, 20.0, 0.0, 0.0, -100.0, -20.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'V');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
	glBitmap(20.0, 20.0, 0.0, 0.0, 300.0, 20.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'D');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');

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

	glutInitWindowSize(winWidth, winHeight);

	// Set Window Title
	glutInitWindowPosition(100, 100);
	map = glutCreateWindow("Unique Graphic");

	glutSetWindow(map);
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);

	glutMainLoop();
}