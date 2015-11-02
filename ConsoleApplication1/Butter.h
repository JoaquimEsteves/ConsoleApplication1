#ifndef __BUTTER__
#define __BUTTER__
#define BUTTERSPEED 10
#include "Obstacle.h"
#include "GL\glut.h"
#include <stdio.h>
class Butter : public Obstacle {
	Vector3 _scale;

public:

	inline Butter(double x, double y, double z) {
		setPosition(x, y, z);
		setSize(1.125, 0.75, 0.75);
	}
	inline virtual ~Butter() {}
	inline void draw() {
		//butter
		glColor3d(1.0, 1.5, 0);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glScaled(1.5, 1, 1);
		glutSolidCube(1.5);
		glPopMatrix();

	}
	void update(double delta_t) {
		//printf("%f ooh boi my delta t\n", delta_t);
		setPosition(getPosition() + getSpeed() * BUTTERSPEED);
	}
};
#endif
