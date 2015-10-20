#ifndef __CHEERIO__
#define __CHEERIO__

#include "Obstacle.h"
#include "GL\glut.h"

class Cheerio : public Obstacle {
	double _torusScale[4] = { 0.05, 0.1, 10, 10 };

public:
	/*
	initial positions set as:
	-6, 2, 0
	4, 7.7, 0
	0, 0, 0
	7, -7, 0
	-4, -1, 0
	*/
	inline Cheerio(double x, double y, double z) {
		setPosition(x, y, z);
	}
	inline virtual ~Cheerio() {}
	inline void draw() {
		//butter
		//glColor3d(1.0, 1.5, 0);

		glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
			glutSolidTorus(_torusScale[0], _torusScale[1], _torusScale[2], _torusScale[3]);
		glPopMatrix();

	}
};
#endif
