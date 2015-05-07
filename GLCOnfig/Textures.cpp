// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>


/* Global variables */
char title[] = "Textures example";
// Window display size
GLsizei winWidth = 800, winHeight = 600;


#define stripeWidth 64
#define stripeHeight 64
static GLubyte stripeImage[stripeHeight][stripeWidth][4];

static GLuint texName;

void createImage(void)
{
	int i, j, c;

	for (i = 0; i < stripeHeight; i++) {
		for (j = 0; j < stripeWidth; j++) {
			// Use bit operations to set values to 0 or 255 in stripe pattern
			c = ((((i & 0x6) == 1) ^ ((j & 0x6)) == 0)) * 255; 	
			stripeImage[i][j][0] = (GLubyte)c;
			stripeImage[i][j][1] = (GLubyte)c;
			stripeImage[i][j][2] = (GLubyte)125;
			stripeImage[i][j][3] = (GLubyte)125;
		}
	}
}
/* Initialize OpenGL Graphics */
void init() {	

	// Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString(GL_VERSION);
	fprintf(stderr, "Your OpenGL version is %s\n", Vstr);

	// Set background color to black 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Maximize depth display
	glClearDepth(1.0f);
	// Enable depth testing for z-culling
	glEnable(GL_DEPTH_TEST);
	// Set the type of depth-test
	glDepthFunc(GL_LEQUAL);
	// Provide smooth shading
	glShadeModel(GL_SMOOTH);
	// Create the image
	// You can also load images but you need to write
	// or use an image loader
	createImage();
	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Bind the texture
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);

	// Set the repeat wrap flags and filter to adjust images 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
		GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, stripeWidth,
		stripeHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		stripeImage);
}

// Display function
void displayfcn() {
		
	// Clear color and depth buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texName);

	// Model view matrix mode
	glMatrixMode(GL_MODELVIEW);

	// Reset the model-view matrix
	// This is done each time you need to clear the matrix operations
	// This is similar to glPopMatrix()
	glLoadIdentity();

	// Set color to green
	glColor3f(0.0f, 1.0f, 0.0f);
	
	// Since we are in ModelView we need to move to World coordinates
	// Move  z out by -7	
	glTranslatef(0.0f, 0.0f, -5.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(30.0f, -1.0, 1.0, 1.0);
	
	// Create a Unit Cube
	glBegin(GL_QUADS);
	// Top 	
	glColor3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom 	
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0f, -1.0f, -1.0f);

	// Front 	
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0f, -1.0f, 1.0f);

	//Back 	
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0f, 1.0f, -1.0f);

	//Left 
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right	
	glTexCoord2f(0.0, 0.0); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0f, -1.0f, -1.0f);			
	glEnd();

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
	gluPerspective(-45.0f, aspect, 0.1f, 100.0f); //45.0f, aspect, 0.1f, 100.0f
}

/* Main function: GLUT runs as a console application starting at main() */
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	// Set the window's initial width & height
	glutInitWindowSize(winWidth, winHeight);
	// Position the window's initial top-left corner
	glutInitWindowPosition(50, 50);
	// Create window with the given title
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