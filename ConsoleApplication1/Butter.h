#ifndef __BUTTER__
#define __BUTTER__

#include "Obstacle.h"
#include "GL\glut.h"

class Butter : public Obstacle {

public:
	inline Butter() {}
	inline virtual ~Butter() {}
	inline void draw() {
		//butter
		glColor3d(1.0, 1.5, 0);

		glPushMatrix();
		glTranslated(-6, 2, 0);
		glScaled(1.5, 1, 0.0);
		glutSolidCube(1.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated(4, 7.7, 0);
		glScaled(1.5, 1, 0.0);
		glutSolidCube(1.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, 0, 0);
		glScaled(1.5, 1, 0.0);
		glutSolidCube(1.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated(7, -7, 0);
		glScaled(1.5, 1, 0.0);
		glutSolidCube(1.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-4, -1, 0);
		glScaled(1.5, 1, 0.0);
		glutSolidCube(1.5);
		glPopMatrix();
	}
};
#endif
