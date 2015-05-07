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
	GLsizei winWidth = 2000, winHeight = 1000;

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
	 gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight/ 2, (GLdouble)winHeight / 2);

	}

	// Generate the Graphics
	void displayFcn(void)
	{
		// Clear display window.
		glClear(GL_COLOR_BUFFER_BIT);
		// Set  graphic objects color to Red or change for your choice
	
		GLubyte bitShape[72] = {};

		double x0 = 500;
		double y0 = 400;
		
		/*EARTH PLOT*/
		int t_earth=0;

		double x_earth= 0;
		double y_earth = 0;
		while(y_earth >= 0)
		{
			x_earth = x0 + 30*t_earth;
			y_earth = y0 + 40*t_earth-0.5*(9.78)*t_earth*t_earth;
				
			GLfloat xplot = (-0.9+(x_earth/1000));
			GLfloat yplot = (-0.6+((y_earth/100)*0.2));
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_TRIANGLES);                      
		glVertex3f(xplot, yplot, 0.0f);              
		glVertex3f(xplot+0.01,yplot+0.02, 0.0f);              
		glVertex3f( xplot-0.01,yplot+0.02, 0.0f);             
		glEnd();  

			t_earth++;
		}

		/*MARS PLOT*/
		int t_mars=0;

		double x_mars= 0;
		double y_mars = 0;
		while(y_mars >= 0)
		{
			x_mars = x0 + 30*t_mars;
			y_mars = y0 + 40*t_mars-0.5*(3.72)*t_mars*t_mars;
				
			GLfloat xplot = (-0.9+(x_mars/1000));
			GLfloat yplot = (-0.6+((y_mars/100)*0.2));
		
		glColor3f(0.4256, 0.207, 0.101);
		glBegin(GL_QUADS);                      
        glVertex3f(xplot, yplot, 0.0f);              
        glVertex3f(xplot+0.03, yplot-0.06, 0.0f);              
        glVertex3f(xplot+0.01,yplot+0.01, 0.0f);            
        glVertex3f(xplot+0.01,yplot, 0.0f);              
		glEnd();  

			t_mars++;
		}

		/*MERCURY PLOT*/
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);                      
		glVertex3f( -0.4, 0.2, 0.0f);              
		glVertex3f(-0.41,0.18, 0.0f);              
		glVertex3f( -0.39,0.18, 0.0f);             
		glEnd();  
		int t_mercury=0;

		double x_mercury = 0;
		double y_mercury = 0;
		while(y_mercury >= 0)
		{
			x_mercury = x0 + 30*t_mercury;
			y_mercury = y0 + 40*t_mercury-0.5*(2.78)*t_mercury*t_mercury;
			//cout<<"X is "<<x_new<<"Y is "<<y_new<<endl;

			glColor3f(0.0, 0.0, 1.0);
		
			GLfloat xplot = (-0.9+(x_mercury/1000));
			GLfloat yplot = (-0.6+((y_mercury/100)*0.2));

		glBegin(GL_TRIANGLES);                      
		glVertex3f(xplot, yplot, 0.0f);              
		glVertex3f(xplot-0.01,yplot-0.02, 0.0f);              
		glVertex3f( xplot+0.01,yplot-0.02, 0.0f);             
		glEnd();  

				t_mercury++;
		}

		/*JUPITER PLOT*/
		glColor3f(0.85, 0.0, 0.0);
	

		int t_jupiter=0;

		double x_jupiter= 0;
		double y_jupiter = 0;
		while(y_jupiter >= 0)
		{
			x_jupiter = x0 + 30*t_jupiter;
			y_jupiter = y0 + 40*t_jupiter-0.5*(22.88)*t_jupiter*t_jupiter;
			//cout<<"X is "<<x_new<<"Y is "<<y_new<<endl;

		
			GLfloat xplot = (-0.9+(x_jupiter/1000));
			GLfloat yplot = (-0.6+((y_jupiter/100)*0.2));

		glColor3f(0.85, 0.0, 0.0);
		glRectf(xplot, yplot,xplot+0.025,yplot+0.025);

				t_jupiter++;
		}
		

		
		  glBegin(GL_LINES);
			 
		 //X Axis
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-1.0f, -0.6f);
		 glVertex2f(1.0f, -0.6f);

		 //Y Axis
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.9f, 1.0f);
		 glVertex2f(-0.9f, -1.0f);

		  //Y Axis
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.7f, -0.6f);
		 glVertex2f(-0.7f, -0.61f);

		 	 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.5f, -0.6f);
		 glVertex2f(-0.5f, -0.61f);

		 	 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.3f, -0.6f);
		 glVertex2f(-0.3f, -0.61f);

		  glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.1f, -0.6f);
		 glVertex2f(-0.1f, -0.61f);

		  glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(0.1f, -0.6f);
		 glVertex2f(0.1f, -0.61f);

		  glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(0.3f, -0.6f);
		 glVertex2f(0.3f, -0.61f);

		  glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(0.5f, -0.6f);
		 glVertex2f(0.5f, -0.61f);

		  glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(0.7f, -0.6f);
		 glVertex2f(0.7f, -0.61f);

		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(0.9f, -0.6f);
		 glVertex2f(0.9f, -0.61f);
		 
		 //X Axis - Grid Line 1
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, -0.8f);
		 glVertex2f(0.75f, -0.8f);

		 	  //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, -0.4f);
		 glVertex2f(0.75f, -0.4f);

		  	  //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, -0.2f);
		 glVertex2f(0.75f, -0.2f);

		  	  //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, 0.0f);
		 glVertex2f(0.75f, 0.0f);

		  	  //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, 0.2f);
		 glVertex2f(0.75f, 0.2f);

		  	  //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, 0.4f);
		 glVertex2f(0.75f, 0.4f);

		   //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, 0.6f);
		 glVertex2f(0.75f, 0.6f);

		   //X Axis - Grid Line 2
		 glColor3f(0.0, 0.0, 0.0);
		 glVertex2f(-0.91f, 0.8f);
		 glVertex2f(0.75f, 0.8f);

		 glEnd();

		  //glBitmap(24.0, 24.0, 0.0, 0.0, 0.0, 300.0, 0);
		// glBitmap(24.0, 24.0, 0.0, 0.0, 30.0, 80.0, bitShape3);
		
		
		 glRasterPos2i(0, 0);
		   glBitmap(20.0, 20.0, 0.0, 0.0, -920.0, -405.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -20.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -20.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -30.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -30.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -30.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -30.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -30.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 glBitmap(0.0, 0.0, 0.0, 0.0, -30.0, 100.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '7');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		  glBitmap(0.0, 0.0, 0.0, 0.0, 200.0, -720.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 
		  glBitmap(0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		  glBitmap(0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		  glBitmap(0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '8');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		
		 glBitmap(0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 
		 glBitmap(0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 
		 glBitmap(0.0, 0.0, 0.0, 0.0, 160.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 
		 glBitmap(0.0, 0.0, 0.0, 0.0, 150.0, 0.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

		 
		 glBitmap(0.0, 0.0, 0.0, 0.0, 100.0, 620.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'H');

		 glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_TRIANGLES);                      
		glVertex3f(0.8f, 0.6f, 0.0f);              
		glVertex3f(0.81f,0.62, 0.0f);              
		glVertex3f( 0.79f,0.62, 0.0f);             
		glEnd();  

		 glBitmap(0.0, 0.0, 0.0, 0.0, -60.0, -45.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'J');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'P');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		 		
		glColor3f(0.85, 0.0, 0.0);
		glRectf(0.79f, 0.5f,0.815f,0.525f);

		glBitmap(0.0, 0.0, 0.0, 0.0, -65.0, -45.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
	
		glColor3f(0.4256, 0.207, 0.101);
		glBegin(GL_QUADS);                      
        glVertex3f(0.79f, 0.45f, 0.0f);              
        glVertex3f(0.82f, 0.39f, 0.0f);              
        glVertex3f(0.80f,0.46f, 0.0f);            
        glVertex3f(0.80f,0.45f, 0.0f);              
		glEnd();  

		glBitmap(0.0, 0.0, 0.0, 0.0, -65.0, -45.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'M');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'U');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');
	
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLES);                      
		glVertex3f(0.81, 0.35, 0.0f);              
		glVertex3f(0.80,0.33, 0.0f);              
		glVertex3f( 0.82,0.33, 0.0f);             
		glEnd();  

		glBitmap(0.0, 0.0, 0.0, 0.0, -65.0, -450.0, 0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'X');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');

		 
		glBitmap(0.0, 0.0, 0.0, 0.0, -1850.0, 500.0, 0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'Y');
		glBitmap(0.0, 0.0, 0.0, 0.0, -10.0, -30.0, 0);
		 //glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
		 glBitmap(0.0, 0.0, 0.0, 0.0, -10.0, -20.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');
		 glBitmap(0.0, 0.0, 0.0, 0.0, -10.0, -20.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'I');
		 glBitmap(0.0, 0.0, 0.0, 0.0, -10.0, -20.0, 0);
		 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');


 // Execute OpenGL functions
 glFlush(); 
 
} 

	// Windows redraw function
	void winReshapeFcn(GLint newWidth, GLint newHeight)
	{
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, (GLdouble)winHeight/ 2, (GLdouble)winHeight / 2);
	 glClear(GL_COLOR_BUFFER_BIT);
	}

	double slope(double x1, double x2,double y1, double y2){
		return ((y2-y1)/(x2-x1));
	}

	double yintercept(double y1,double m,double x1){
		return (y1-(m*x1));
	}

	double gety(double x)
	{
	return (slope(6,3,4,-10)*x+yintercept(4,slope(6,3,4,-10),6));
	}


	// Main function
	void main(int argc, char** argv)
	{
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set initial Window position
	 glutInitWindowPosition(0, 0);
	 // Set Window Size
	 glutInitWindowSize(winWidth, winHeight);
	 
	
	 /*Maths Task 1*/
	  /*
	 double slo = slope(6,3,4,-10);
	 cout<<"The two points are: (6,4) and (3,-10)"<<endl<<endl;
	 cout<<"Slope is:"<< slo<<endl;
	 cout<<"Y-intercept is:"<<yintercept(4,slope(6,3,4,-10),6)<<endl;
	 cout<<"The Line in Slope intercept form: y="<<slo<<"x"<<yintercept(4,slope(6,3,4,-10),6)<<endl;
	 cout<<"additional point, x=10, y="<<gety(10)<<endl;*/

	 /*Maths Task 2*/
	 /*
	double x1 = 10;
	double y1 = -20;
	double z1 = 40;
	double x2 = 30;
	double y2 = 3;
	double z2 = 18;
	double x3 = -5;
	double y3 = -10;
	double z3 = 25;
	double x4 = -10;
	double y4 = 12;
	double z4 = -19;

	double A = y1 * (z2-z3) + y2 * (z3-z1) + y3 * (z1-z2);
	double B = z1 * (x2-x3) + z2 * (x3-x1) + z3 * (x1-x2);
	double C = x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2);
	double D = (-x1 * (y2*z3 - y3*z2)) -( x2 * (y3*z1 - y1*z3)) -(x3*(y1*z2 - y2*z1));

	cout<< "Plane coeffecients are:"<<A<<"x+"<<B<<"y+"<<C<<"z"<<D<<endl;

	 cout<< "Position of P4: "<< (A*x4 + B*y4 +C*z4 + D) <<endl;*/
	 
	 glutCreateWindow("Planetary Gravity");
	 // Initialize
	 init();
	 // Display function call
	glutDisplayFunc(displayFcn);
	 // Window reshape call
	 glutReshapeFunc(winReshapeFcn);

	 //trajectory(2.78);
	 glutMainLoop();

	} 