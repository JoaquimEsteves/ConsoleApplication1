#ifndef __CAR__
#define __CAR__

#define PI 3.14159265
#define CARSPEED 0.0001

#include "DynamicObject.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "GL\glut.h"
#include <math.h>
#include <stdio.h>
class Car : public DynamicObject {
	double maxSpeed = 50;
	double specialSpeed = 0;
	double turnAngle = 0;
	double rotation = 0;
	Vector3 _direction;

public:

	inline Car(){
		setPosition(0, 4, 0);
		_direction.set(1, 0, 0);

	}
	inline virtual ~Car()			{}
	double getMaxSpeed()			{ return maxSpeed; }
	double getTurnAngle()			{ return turnAngle;  }
	void setSpecialSpeed(double d)	{ specialSpeed = d; }
	double getSpecialSpeed()		{ return specialSpeed; }
	Vector3 getDirection()			{ return _direction; }

	void turnLeft() {
		turnAngle =  turnAngle + 0.1;
		setDirectionSpeed();
	}
	void turnRight() {
		turnAngle = turnAngle - 0.1;
		setDirectionSpeed();
	}

	void  setDirectionSpeed() {
		double x = _direction.getX()*cos(turnAngle) /*- _direction.getY()*sin(turnAngle)*/;
		double y = _direction.getX()*sin(turnAngle) /*+ _direction.getY()*cos(turnAngle)*/;
		double z = 0;
		_direction.set(x / sqrt(x*x + y*y + z*z), y / sqrt(x*x + y*y + z*z), z / sqrt(x*x + y*y + z*z));
	}

	void friction() {
		if (specialSpeed == 0)
			return;
		if (specialSpeed > 0)
			specialSpeed -= 1;
		if (specialSpeed < 0)
			specialSpeed += 1;
	}

	inline void draw() {
		glColor3d(0, 0, 0); //wheels could be torus

		glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());



			glRotated(turnAngle * 180 / PI, 0, 0, 1);
	

			glPushMatrix();
				glTranslated(0.3, 0.3, 0);
				glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(0.3, -0.3, 0);
				glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-0.3, 0.3, 0);
				glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-0.3, -0.3, 0);
				glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glColor3d(1, 0, 0);//car

			glPushMatrix();
				glScaled(2, 1.5, 0.0);
				glutSolidCube(0.5);
			glPopMatrix();

		glPopMatrix();
		
	}

	void update_trivial(double delta_t) {
		//In case of emergency
		setPosition(getPosition() + getSpeed() * delta_t);
	}

	void update(double delta_t) {
		//using printf because visual studios does not like cout
		//printf("%d %d %d \n",(_direction * specialSpeed * CARSPEED * delta_t).getX() , (_direction * specialSpeed * CARSPEED * delta_t).getY() , (_direction * specialSpeed * CARSPEED * delta_t).getZ());
		friction();
		setPosition(getPosition() + getDirection() * specialSpeed * CARSPEED * delta_t);
	}
};
#endif
