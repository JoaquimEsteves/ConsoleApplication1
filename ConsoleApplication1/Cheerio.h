#pragma once
#ifndef __CHEERIO__
#define __CHEERIO__
#define CHEERIOSPEED 10
#include "Obstacle.h"
#include "Car.h"
#include "GL\glut.h"

class Cheerio : public Obstacle {
	double _torusScale[4] = { 0.05, 0.1, 10, 10 };
	Vector3 _initialPosition;

public:

	inline Cheerio(double x, double y, double z) {
		setPosition(x, y, z);
		_initialPosition.set(x, y, z);
		setSize(0.1, 0.1, 0.1);
	}
	inline Cheerio(Vector3 pos) {
		setPosition(pos);
		_initialPosition.set(pos);
		setSize(0.1, 0.1, 0.1);
	}
	inline virtual ~Cheerio() {}
	Vector3 getInitialPosition() { return _initialPosition; }
	inline void draw() {
		//butter
		//glColor3d(0.5, 0.35, 0.05);
		defineMaterial(0.05, 0.035, 0.005, 1.00,	//Ambient
			0.05, 0.035, 0.005, 1.00,	//Diffuse
			0.05, 0.035, 0.005, 1.00,	//Specular
			0.05, 0.035, 0.005, 1.00,	//Emission
			77);					//SHININESS
		glColor3f(0.5, 0.35, 0.05);

		glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
			glutSolidTorus(_torusScale[0], _torusScale[1], _torusScale[2], _torusScale[3]);
		glPopMatrix();
	}
	void update(double delta_t, Car *myCar, int forward) {

		if (myCar->HasColision(this)) {
			myCar->setForceStart(true);
			setSpeed(myCar->getDirection()*forward*0.01);
			myCar->setSpecialSpeed(0);
		}
		if (getPosition().getX() >= 9.5 || getPosition().getX() <= -10 ||
			getPosition().getY() >= 9.5 || getPosition().getY() <= -9.5) {
			setPosition(0, 0, 100);
			setSpeed(0, 0, 0);
		}
		if (getSpeed().getX() != 0 || getSpeed().getY() != 0) {
			setSpeed(getSpeed()*0.9);

		}


		setPosition(getPosition() + getSpeed() * CHEERIOSPEED);
	}
};
#endif
