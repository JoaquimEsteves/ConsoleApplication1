#ifndef __BUTTER__
#define __BUTTER__
#define BUTTERSPEED 10
#include "Obstacle.h"
#include "Car.h"
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
		//glColor3d(1.0, 1.5, 0);
		defineMaterial(0.1, 0.15, 0, 1.00,	//Ambient
			0.1, 0.15, 0, 1.00,	//Diffuse
			0.1, 0.15, 0, 1.00,	//Specular
			0.1, 0.15, 0, 1.00,	//Emission
			77);					//SHININESS
		glColor3f(1.0, 1.5, 0);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		glScaled(1.5, 1, 1);
		glutSolidCube(1.5);
		glPopMatrix();

	}


	//MONSTERS

	//END MONSTERS

	void update(double delta_t, Car * myCar, int forward) {
		//printf("%f ooh boi my delta t\n", delta_t);
		if (myCar->HasColision(this)) {
			myCar->setForceStart(true);
			setSpeed(myCar->getDirection()*forward*0.005);

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
		setPosition(getPosition() + getSpeed() * BUTTERSPEED);
	}
};
#endif
