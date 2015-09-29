#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"
#include "GL\glut.h"

class Orange : public Obstacle {
	GLdouble innerRaidus = 0.5;
	GLdouble outterRaidus = 1;
	GLint sides = 50;
	GLint rings = 50; 

public:
	inline Orange() {}
	inline virtual ~Orange() {}
	inline void draw() {
		glPushMatrix();
			glMatrixMode(GL_MODELVIEW);
			// clear the drawing buffer.
			glClear(GL_COLOR_BUFFER_BIT);
			// clear the identity matrix.
			glLoadIdentity();
			// traslate the draw by z = -4.0
			// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
			glTranslatef(-0.2,-0.4,0.0);
			// Red color used to draw.
			glColor3f(1.0, 0.0, 0.0);
			// changing in transformation matrix.
			// rotation about X axis
			glRotatef(90.0, 1.0, 0.0, 0.0);
			// rotation about Y axis
			glRotatef(90.0, 0.0, 1.0, 0.0);
			// rotation about Z axis
			//glRotatef(zRotated, 0.0, 0.0, 1.0);
			// scaling transfomation 
			glScalef(0.1, 0.1, 0.1);
			// built-in (glut library) function , draw you a Torus.
			glutSolidTorus(innerRaidus, outterRaidus, sides, rings);
			// Flush buffers to screen
		glPopMatrix();
	
		// sawp buffers called because we are using double buffering 
		// glutSwapBuffers();
		/*cenas reshape
		if (y == 0 || x == 0) return;  //Nothing is visible then, so return
									   //Set a new projection matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//Angle of view:40 degrees
		//Near clipping plane distance: 0.5
		//Far clipping plane distance: 20.0

		gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);

		glViewport(0, 0, x, y);*/
	}
};
#endif

//HELLO
/*glMatrixMode(GL_MODELVIEW);
// clear the drawing buffer.
glClear(GL_COLOR_BUFFER_BIT);
// clear the identity matrix.
glLoadIdentity();
// traslate the draw by z = -4.0
// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
glTranslatef(-0.2, -0.4, 0.0);
// Red color used to draw.
glColor3f(1.0, 0.0, 0.0);
// changing in transformation matrix.
// rotation about X axis
glRotatef(90.0, 1.0, 0.0, 0.0);
// rotation about Y axis
glRotatef(90.0, 0.0, 1.0, 0.0);
// rotation about Z axis
//glRotatef(zRotated, 0.0, 0.0, 1.0);
// scaling transfomation
glScaled(0.1, 0.1, 0.1);
// built-in (glut library) function , draw you a Torus.

glutSolidTorus(innerRaidus, outterRaidus, sides, rings);
// Flush buffers to screen
glPopMatrix();
glFlush();

// sawp buffers called because we are using double buffering
// glutSwapBuffers();
/*cenas reshape
if (y == 0 || x == 0) return;  //Nothing is visible then, so return
//Set a new projection matrix
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//Angle of view:40 degrees
//Near clipping plane distance: 0.5
//Far clipping plane distance: 20.0

gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);

glViewport(0, 0, x, y);*/
//GOODBYE