#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"
#include "GL\glut.h"

class Orange : public Obstacle {
	int numberRings = 20;
public:
	/*
	initial positions set as:
		-3,7.5,0
		7, 7, 0
		-8.5, -1.5, 0
	*/
	inline  Orange() {}
	inline  Orange(double x, double y, double z) {
		setPosition(x, y, z);
	}
	inline virtual ~Orange() {}
	inline void draw() {
		//orange
		glColor3d(1.0, 0.5, 0);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();

	}
};
#endif
