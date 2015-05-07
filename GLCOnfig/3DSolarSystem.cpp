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
GLsizei winWidth = 1500, winHeight = 1000;
typedef struct
{
	float x;
	float y;
}CIRCLE;

CIRCLE circle;

float rot = 0; int map;


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

void createcircle(float k, float r, float h) {
	glBegin(GL_LINES);
	for (int i = 0; i < 180; i++)
	{
		circle.x = r * cos(i) - h;
		circle.y = r * sin(i) + k;
		glVertex3f(circle.x + k, circle.y - h, 0);

		circle.x = r * cos(i + 0.1) - h;
		circle.y = r * sin(i + 0.1) + k;
		glVertex3f(circle.x + k, circle.y - h, 0);
	}
	glEnd();
}

const float RAD = 3.14159 / 180;

void drawEllipse(float xradius, float yradius)
{
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < 360; i++)
	{
		//convert degrees into radians
		float InRad = i*RAD;
		glVertex2f(cos(InRad)*xradius, sin(InRad)*yradius);
	}

	glEnd();
}

void displayfcn1(void)
{
	
	// Clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Model view matrix mode
	glMatrixMode(GL_MODELVIEW);
	// Reset the model-view matrix
	// This is done each time you need to clear the matrix operations
	// This is similar to glPopMatrix()
	glLoadIdentity();
	// Set color to green
	glColor3f(0.0f, 1.0f, 0.0f);
	// Since we are in ModelView we need to move to World coordinates
	// Move x to right by 1.5, y down by -1.5 and z out by -7 
	glTranslatef(1.5f, 1.5f, -4.0f);
	//glTranslatef(-1.5f, 1.5f, 7.0f);
	// Scale x,y and z by 50%
	glScalef(0.5f, 0.5f, 0.5f);
	// Add a wireSpere mesh with 1.5 radius and 15x15 gridline
	glutWireSphere(1.5, 15, 15);
	
	// Double buffering
	glutSwapBuffers();

}


void displayfcn() {
	// Clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Model view matrix mode
	glMatrixMode(GL_MODELVIEW);

	// Reset the model-view matrix
	// This is done each time you need to clear the matrix operations
	// This is similar to glPopMatrix()
	glLoadIdentity();

	// Set color to green
	glColor3f(0.0f, 1.0f, 0.0f);
	// Since we are in ModelView we need to move to World coordinates
	// Move x to right by 1.5, y down by -1.5 and z out by -7 
	glTranslatef(-1.1f, -1.8f, -7.0f);
	// Scale x,y and z by 50%
	glScalef(0.25f, 0.25f, 0.25f);
	// Add a wireSpere mesh with 1.5 radius and 15x15 gridline
	glutWireSphere(1.5, 15, 15);

	// Set color to black
	glColor3f(0.0f, 0.0f, 0.0f);
	// Since we are in ModelView we need to move to World coordinates
	// Move x to right by 1.5, y down by -1.5 and z out by -7 
	glTranslatef(12.8f, 15.5f, -7.0f);
	// Scale x,y and z by 50%
	glScalef(0.95f, 0.95f, 0.95f);
	// Add a wireSpere mesh with 1.5 radius and 15x15 gridline
	glutWireSphere(1.5, 15, 15);

	// Set color to Orangy
	glColor3f(0.92f, 0.53f, 0.18f);
	glLoadIdentity();
	// Move x to right by 1.5, y up by 1.5 and z out
	glTranslatef(0.0f, 0.0f, -7.5f);
	glScalef(0.5f, 0.5f, 0.5f);
	// Add a SolidSphere mesh
	glutSolidSphere(1.5, 15, 15);
	glColor3f(0.0f, 0.0f, 1.0f);

	// Set color to Red
	glColor3f(0.8f, 0.30f, 0.30f);
	glLoadIdentity();
	// Move x to right by 1.5, y up by 1.5 and z out
	glTranslatef(-3.2f, -2.1f, -7.5f);
	glScalef(0.3f, 0.3f, 0.3f);
	// Add a SolidSphere mesh
	glutSolidSphere(1.5, 45, 45);
	glColor3f(0.0f, 0.0f, 1.0f);

	// Set color to Grey-Green
	glColor3f(0.65f, 0.8f, 0.70f);
	glLoadIdentity();
	// Move x to right by 1.5, y up by 1.5 and z out
	glTranslatef(0.97f, 0.95f, -7.5f);
	glScalef(0.08f, 0.08f, 0.08f);
	// Add a SolidSphere mesh
	glutSolidSphere(1.5, 15, 15);
	

	// Set color to Grey
	glColor3f(0.525f, 0.525f, 0.518f);
	glLoadIdentity();
	// Move x to right by 1.5, y up by 1.5 and z out
	glTranslatef(-0.7f, -1.5f, -7.5f);
	glScalef(0.08f, 0.08f, 0.08f);
	// Add a SolidSphere mesh
	glutSolidSphere(1.5, 15, 15);
	



	// Add a Cyan wire teapot
	glColor3f(0.6f, 0.7f, 0.85f);
	glLoadIdentity();
	// Translate to center
	glTranslatef(2.5f, -1.0f, -6.0f);
	glScalef(0.3f, 0.3f, 0.3f);
	// Rotate 45 degree steps across z,y and x.
	glRotatef(45.0f, 0, 0, 1.0);
	//glRotatef(45.0f, 0, 1.0, 0.0);
	glRotatef(45.0f, 1.0, 0.0, 0.0);
	glutSolidTeapot(0.5);

	


	// Reset Matrix and then translate and scale a Cube
	glLoadIdentity();
	glTranslatef(-2.5f, -0.0f, -6.0f);
	glScalef(0.25f, 0.25f, 0.25f);
	glRotatef(45.0f, 1.0f, 0.0f, 0.0f);


	// Cube - 6 sides different colors
	glBegin(GL_QUADS);
	// Top Green 
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom Orange
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Front Red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	//Back Yellow
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//Left Blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right Cyan
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();



	glLoadIdentity();
	glTranslatef(0, 0, -20);

	//THE SUN
	glColor3f(1, 0.5, 0.005);
	createcircle(0, 2, 0);

	//THE MERCURY
	//glColor3f(0.4, 0.85, 0.97);
	//createcircle(2.54053, 0.38252, 0);

	//THE EARTH
	//glColor3f(0.08, 0.56, 0.002);
	//createcircle(0, 1, 6.56297);

	//THE MARS
	//glColor3f(1, 0.0, 0.0);
	//createcircle(0, 0.53264, 10);

	//THE VENUS
	//glColor3f(0, 0, 0);
	//createcircle(4.747, 0.94886, 0);

	//THE MARS ellipse
	glColor3f(1, 0.0, 0.0);
	drawEllipse(20.0f, 11.6f);

	//Earth Ellipse
	glColor3f(0.08, 0.56, 0.002);
	drawEllipse(13.12594343f, 7.613047188f);

	//Venus Ellipse
	glColor3f(0, 0, 0);
	drawEllipse(9.493994881f, 5.506517031f);

	//Mercury Ellipse
	glColor3f(0.4, 0.85, 0.97);
	drawEllipse(5.081052701f, 2.947010566f);



	glColor3f(1, 0.5, 0.005);
	glRasterPos3f(2.5f, 0.0f,0.0f);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');

	glColor3f(1, 0.0, 0.0);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, -430.0, -380.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');

	glColor3f(0.08, 0.56, 0.002);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, -330.0, -260.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');

	glColor3f(0, 0, 0);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, +210.0, +200.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'V');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');

	glColor3f(0.65f, 0.8f, 0.70f);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, 120.0, 100.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');

	
	glColor3f(0.525f, 0.525f, 0.518f);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, -80.0, -280.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'O');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');

	glColor3f(0.6f, 0.7f, 0.85f);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, 360.0, -280.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'G');
	glBitmap(20.0, 20.0, 0.0, 0.0, -30.0, -20.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'K');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');

	glColor3f(0.75f, 0.75f, 0.75f);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, -380.0, -60.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	//glLoadIdentity();
	glLoadIdentity();
	glColor3f(0.75f, 0.75f, 0.75f);
	glTranslatef(-2.5f, -0.0f, -6.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.95f, -0.1f, 0.0);
	glVertex3f(-0.75f, 0.2f, 0);
	glVertex3f(-0.25f, 0.2f, 0);
	glVertex3f(-0.45f, -0.1f, 0);
	glEnd();

	glLoadIdentity();
	glTranslatef(-1.3f, -0.0f, -6.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.95f, -0.1f, 0.0);
	glVertex3f(-0.75f, 0.2f, 0);
	glVertex3f(-0.25f, 0.2f, 0);
	glVertex3f(-0.45f, -0.1f, 0);
	glEnd();


	glRasterPos2i(0, -300);
	glBitmap(20.0, 20.0, 0.0, 0.0, 0.0, -280.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'L');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');

	// Double buffering
	glutSwapBuffers();
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
	glutInitDisplayMode(GLUT_DOUBLE);
	// Set the window's initial width & height 
	glutInitWindowSize(winWidth, winHeight);
	// Position the window's initial top-left corner
	glutInitWindowPosition(50, 50);
	// Create window with the given title 
	char title[] = "Three Dimensional Solar System";
	glutCreateWindow(title);
	// Display Function
	glutDisplayFunc(displayfcn);
	// Reshape function
	glutReshapeFunc(winReshapeFcn);
	// Initialize
	init();
	// Process Loop
	glutMainLoop();

}