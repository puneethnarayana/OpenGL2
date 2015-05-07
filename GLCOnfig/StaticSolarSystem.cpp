	// Include section
	#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#else
	#include <GL/glut.h>
	#endif
	#include <stdio.h>
#include <iostream>

typedef struct
{
float x;
float y;
}CIRCLE;

CIRCLE circle;

float rot = 0;

void createcircle (float k, float r, float h) {
    glBegin(GL_LINES);
    for (int i = 0; i < 180; i++)
    {
    circle.x = r * cos(i) - h;
    circle.y = r * sin(i) + k;
    glVertex3f(circle.x + k,circle.y - h,0);
    
    circle.x = r * cos(i + 0.1) - h;
    circle.y = r * sin(i + 0.1) + k;
    glVertex3f(circle.x + k,circle.y - h,0);
    }
    glEnd();
}

const float RAD = 3.14159/180;
 
void drawEllipse(float xradius, float yradius)
{
   glBegin(GL_LINE_LOOP);
 
   for (int i=0; i < 360; i++)
   {
      //convert degrees into radians
      float InRad = i*RAD;
      glVertex2f(cos(InRad)*xradius,sin(InRad)*yradius);
   }
 
   glEnd();
}
 
void display (void) {
    glClearColor (1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-20);
   
	//THE SUN
	glColor3f(1,0.5,0.005);
    createcircle(0,2,0);
   
	//THE MERCURY
	glColor3f(0.4,0.85,0.97);
    createcircle(2.54053,0.38252,0);

	//THE EARTH
	glColor3f(0.08,0.56, 0.002);
    createcircle(0,1,6.56297);

	//THE MARS
	glColor3f(1,0.0,0.0);
    createcircle(0,0.53264,10);

	//THE VENUS
	glColor3f(0,0,0);
    createcircle(4.747,0.94886,0);

	//THE MARS ellipse
	glColor3f(1,0.0,0.0);
	drawEllipse(20.0f,11.6f);

	//Earth Ellipse
	glColor3f(0.08,0.56, 0.002);
	drawEllipse(13.12594343f,7.613047188f);

	//Venus Ellipse
		glColor3f(0,0, 0);
	drawEllipse(9.493994881f,5.506517031f);

	//Mercury Ellipse
		glColor3f(0.4,0.85,0.97);
	drawEllipse(5.081052701f,2.947010566f);

	 
		 
	   glColor3f(1,0.5,0.005);
	   glRasterPos2i(0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');

	   glColor3f(1,0.0,0.0);
		 glRasterPos2i(0, 0);
	     glBitmap(20.0, 20.0, 0.0, 0.0, -430.0, -380.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');

		  glColor3f(0.08,0.56, 0.002);
		  	 glRasterPos2i(0, 0);
	     glBitmap(20.0, 20.0, 0.0, 0.0, -330.0, -260.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');

		    glColor3f(0,0, 0);
		  	 glRasterPos2i(0, 0);
	     glBitmap(20.0, 20.0, 0.0, 0.0, +210.0, +180.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'V');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');

		  glColor3f(0.4,0.85,0.97);
		    	 glRasterPos2i(0, 0);
	     glBitmap(20.0, 20.0, 0.0, 0.0, 120.0, 80.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
		  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		  	 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		  	 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');


    glutSwapBuffers();

}

void help(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();




	glColor3f(1, 0.5, 0.005);
	glRasterPos2i(0, 0);
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
	glBitmap(20.0, 20.0, 0.0, 0.0, +210.0, +180.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'V');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'N');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');

	glColor3f(0.4, 0.85, 0.97);
	glRasterPos2i(0, 0);
	glBitmap(20.0, 20.0, 0.0, 0.0, 120.0, 80.0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');


	glutSwapBuffers();

}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode (GL_MODELVIEW);
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1500, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Student HomeWork 3.1");

    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);

	glutInitWindowSize(500, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Objects");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);

	glutInitWindowSize(500, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Help");

	glutDisplayFunc(help);
	glutIdleFunc(help);
	glutReshapeFunc(reshape);

    glutMainLoop ();
    return 0;
}

