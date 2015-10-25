#pragma once
#ifndef __CHEERIO__
#define __CHEERIO__

#include "Obstacle.h"
#include "GL\glut.h"

class Cheerio : public Obstacle {
	double _torusScale[4] = { 0.05, 0.1, 10, 10 };

public:
	
	inline Cheerio(double x, double y, double z) {
		setPosition(x, y, z);
		setSize(0.1, 0.1, 0.1);
	}
	inline virtual ~Cheerio() {}

	inline void draw() {
		//butter
		glColor3d(0.5, 0.35, 0.05);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glutSolidTorus(_torusScale[0], _torusScale[1], _torusScale[2], _torusScale[3]);
		glPopMatrix();

	}
	void update(double delta_t) {
		setPosition(getPosition() + getSpeed() * delta_t);
	}
};
#endif
