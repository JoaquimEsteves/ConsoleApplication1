#ifndef __BUTTER__
#define __BUTTER__

#include "Obstacle.h"
#include "GL\glut.h"

class Butter : public Obstacle {
	Vector3 _scale;

public:
	/*
	initial positions set as:
		-6, 2, 0
		4, 7.7, 0
		0, 0, 0
		7, -7, 0
		-4, -1, 0
	*/
	inline Butter(double x, double y, double z) {
		setPosition(x, y, z);
		_scale = new Vector3(1.5, 1, 1);
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
};
#endif
