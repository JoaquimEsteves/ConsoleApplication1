#ifndef __CAR__
#define __CAR__

#define PI 3.14159265
#define CARSPEED 0.0005

#include "DynamicObject.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "GL\glut.h"
#include <math.h>

class Car : public DynamicObject {
	double maxSpeed;
	double specialSpeed = 0;
	double turnAngle = 0;
	double rotation = 0;
	Vector3 _direction;

public:

	inline Car(){
		//_direction.set(1, 1, 0);

	}
	inline virtual ~Car(){}
	double getTurnAngle() { return turnAngle;  }
	void setSpecialSpeed(double d) { specialSpeed = d; }
	Vector3 getDirection() { return _direction; }

	void turnLeft() {
		turnAngle =  turnAngle + 5;
	}
	void turnRight() {
		turnAngle = turnAngle - 5;
	}

	inline void draw() {
		glColor3d(0, 0, 0); //wheels could be torus

		glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
			glRotated(turnAngle, 0, 0, 1);
			glTranslated(-getPosition().getX(), -getPosition().getY(), -getPosition().getZ());

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
	void  setDirectionSpeed() { 
		double x = _direction.getX()*cos(turnAngle)- _direction.getY()*sin(turnAngle);
		double y = _direction.getX()*sin(turnAngle) - _direction.getY()*cos(turnAngle);
		double z = 0;
		_direction.set(x, y, z);
	}

	void update_trivial(double delta_t) {
		//In case of emergency
		setPosition(getPosition() + getSpeed() * delta_t);
	}

	void update(double delta_t) {
		setPosition(getPosition() +  getSpeed() * CARSPEED * delta_t);
		/*setPosition( oldPosition.getX() +  cos(turnAngle) + getSpeed().getX() * delta_t,
			oldPosition.getY() * sin(turnAngle) + getSpeed().getX() * delta_t,
			oldPosition.getZ()) ;*/
	}
};
#endif
