#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"
#include "GL\glut.h"

class Orange : public Obstacle {
	int numberRings = 20;
public:
	inline Orange() {}
	inline virtual ~Orange() {}
	inline void draw() {
		//orange
		glColor3d(1.0, 0.5, 0);

		glPushMatrix();
		glTranslated(-3, 7.5, 0);
		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();

		glPushMatrix();
		glTranslated(7, 7.0, 0);
		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-8.5, -1.5, 0);
		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();
	}
};
#endif
