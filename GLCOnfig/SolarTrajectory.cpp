#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <iostream>

using namespace std;

GLfloat xRot, yRot, zRot, x = -1.0, y, z;

GLfloat SpeedX = 0.25;
GLfloat year = 0.0; //degrees
GLfloat day = 0.0;
GLfloat EarthOrbitRadius = 1.0;
GLfloat MoonOrbitRadius = 0.1;
GLfloat daySpeed = 2.0 * SpeedX;
GLfloat DaysPerYear = 360;
GLfloat yearSpeed = DaysPerYear / 360.0 * daySpeed * SpeedX;


#define pi 3.14159265358979323846

#define SSize 0.2*1.5
#define MSize 0.016*1.5
#define VSize 0.03*1.5
#define ESize 0.035*1.5
#define MarsSize 0.037*1.5
#define JSize 0.09*1.5
#define NeptuneSize 0.04


typedef struct Planet
{
	GLfloat DaysPerYear, OrbitR, Size;
	GLfloat Clx, Cly, Clz;
	GLfloat yearSpeed, day, year;

} Planet;

Planet Mercury = { 88, 0.3, MSize,
0.8, 0.8, 0.0 
, 0.0, 0.0, 0.0 };
Planet Venus = { 224, 0.4, VSize,
0.0, 0.0, 0.0 
, 0.0, 0.0, 0.0 };
Planet Earth = { 365, 0.7, ESize,
0.0, 1.0, 0.0
, 0.0, 0.0, 0.0 };
Planet Mars = { 686, 0.9, MarsSize,
0.8, 0.2, 0.2,  
0.0, 0.0, 0.0 };
Planet Jupiter = { 3960, 1.3, JSize,
0.8, 0.3, 0.3,
0.0, 0.0, 0.0
};
Planet Neptune = { 30000, 2.3, NeptuneSize,
0.2, 0.2, 0.9,   //color 
0.0, 0.0, 0.0 };


void SpeedGen()
{
	Mercury.yearSpeed = Mercury.DaysPerYear / 360.0 * daySpeed*12.0 * SpeedX;
	Venus.yearSpeed = Venus.DaysPerYear / 360.0 * daySpeed *2.0* SpeedX;
	Earth.yearSpeed = Earth.DaysPerYear / 360.0 * daySpeed * SpeedX;
	Mars.yearSpeed = Mars.DaysPerYear / 360.0 * daySpeed *0.5* SpeedX;
	Jupiter.yearSpeed = Mars.DaysPerYear / 360.0 * daySpeed *0.4* SpeedX;
	Neptune.yearSpeed = Neptune.DaysPerYear / 360.0 * daySpeed *0.009* SpeedX;

}


void PlacePlanet(Planet x)
{
	glRotatef(x.year, 0.2, 1.0, 0.1);
	glTranslatef(x.OrbitR, 0.0, 0.0);
	glRotatef(-(x.year), 0.2, 1.0, 0.1);
	glPushMatrix();
	glRotatef(x.day, 0.25, 1.0, 0.0);
	glColor3f(x.Clx, x.Cly, x.Clz);
	glutWireSphere(x.Size, 20, 20);  //Draw earth
	//Draw earth rotation axis

	glPopMatrix();
}

void Display()
{	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Model view matrix mode
	glMatrixMode(GL_MODELVIEW);

	// Reset the model-view matrix
	// This is done each time you need to clear the matrix operations
	// This is similar to glPopMatrix()
	

	//RenderScene();
	glPushMatrix();
gluLookAt(0.0, 0.0, -3.0,
		0.0, 0.0, 5.0,
		0.0, -8.0, 0.0);

	glColor3f(0.92f, 0.53f, 0.18f);
	glutSolidSphere(SSize, 50, 50);
	glPushMatrix();
	glPushMatrix();
	PlacePlanet(Mercury);
	glPopMatrix();
	glPushMatrix();
	PlacePlanet(Venus);
	glPopMatrix();
	glPushMatrix();
	PlacePlanet(Earth);
	glPopMatrix();
	glPushMatrix();
	PlacePlanet(Mars);
	glPopMatrix();
	glPushMatrix();
	PlacePlanet(Jupiter);
	glPopMatrix();
	glPushMatrix();
	PlacePlanet(Neptune);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

glPopMatrix();

	glFlush();
	glutSwapBuffers();

}

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

void Idle()
{

	
	Mercury.day += daySpeed;
	Mercury.year += Mercury.yearSpeed;

	Venus.day += daySpeed;
	Venus.year += Venus.yearSpeed;

	Mars.day += daySpeed;
	Mars.year += Mars.yearSpeed;

	Earth.day += daySpeed;
	Earth.year += Earth.yearSpeed;

	Jupiter.day += daySpeed;
	Jupiter.year += Jupiter.yearSpeed;

	Neptune.day += daySpeed;
	Neptune.year += Neptune.yearSpeed;

	Display();

}
void Init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString(GL_VERSION);
	//fprintf(stderr, "Your OpenGL version is %s\n", Vstr);
	glClearDepth(50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void mouseFcn(GLint button, GLint action, GLint x, GLint y)
{

	switch (button) {
	case GLUT_LEFT_BUTTON:           //  Start the animation.
		if (action == GLUT_DOWN)
			glutIdleFunc(Idle);
		break;
	case GLUT_RIGHT_BUTTON:            //  Stop the animation.
		if (action == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '1':   /*  p key starts the animation  */
		glutIdleFunc(Idle);
		break;
	case '2': /*  2 key stops the animation  */
		glutIdleFunc(NULL);
		break;
	case 'q': 		
		daySpeed = 0; 
		break;
	case 'w': 
		daySpeed = 2.0 * SpeedX; 
		break;
	case 'j': 
		Jupiter.yearSpeed = 0;
		break;
	case 'm': 
		Mercury.yearSpeed = 0;
		break;
	case 'n': 
		Neptune.yearSpeed = 0;
		break;
	case 'b': 
		Mars.yearSpeed = 0;
		break;
	case 'e':
		Earth.yearSpeed = 0;
		break;
	case 'v': 
		Earth.yearSpeed = 0;
		break;
	case 'r': 
		SpeedGen();
		break;
	default:
		break;
	}
}

void main(int argc, char **argv)
{
	// Initialize GLUT
	printf("Instructions:\n");
	printf("To Start the Animation:\t Press 1 on keyboard or Left Click \n");
	printf("To Start the Animation:\t Press 2 on keyboard or Right Click \n");
	printf("To Stop the Rotation:\t Press q Restart:\t Press w\n");
	printf("To Stop Jupiter's revolution: \t Press j \n");
	printf("To Stop Mars's revolution: \t Press b\n");
	printf("To Stop Earth's revolution: \t Press e \n");
	printf("To Stop Venus's revolution: \t Press v\n");
	printf("To Stop Neptune's revolution: \t Press n\n");
	printf("To Stop Mercury's revolution: \t Press m \n");
	printf("To Restart Any planet's revolution: \t Press r \n");
	SpeedGen();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // double buffering for Animation
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(800, 100);

	glutCreateWindow("Solar System");
	//Functions
	Init();
	//
	glutDisplayFunc(Display);
	glutReshapeFunc(winReshapeFcn);
	//glutIdleFunc(Idle);
	glutKeyboardFunc(keyboard);
	//glutTimerFunc(10, timer, 0);
	glutMouseFunc(mouseFcn);

	
	glutMainLoop();

}