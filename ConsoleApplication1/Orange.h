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
			glLoadIdentity();

			glTranslatef(-0.2, -0.35, 0.0);
			glScalef(0.1, 0.1, 0.1);
			glColor3f(1.0, 0.0, 0.0);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			
			// built-in (glut library) function , draw you a Torus.
			glutSolidTorus(innerRaidus, outterRaidus, sides, rings);
		glPopMatrix();
	
		// sawp buffers called because we are using double buffering. NOT SURE IF WE ARE ANYMORE
		// glutSwapBuffers();
	}
};
#endif
