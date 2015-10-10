#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "GL\glut.h"
#include <math.h>

class Car : public DynamicObject {

	double accelaration;
	double maxSpeed;
	double turnAngle = 0;
	Vector3 _direction;

public:

	inline Car(){
		_direction.set(1, 1, 0);

	}
	inline virtual ~Car(){}
	double getTurnAngle() { return turnAngle;  }

	Vector3 getDirection() { return _direction; }

	void turnLeft() {
		turnAngle =  turnAngle -5;
		_direction.set(_direction.getX()/cos(turnAngle), _direction.getY(),0 );
	}
	void turnRight() {
		turnAngle = turnAngle +5;
		_direction.set(_direction.getX(), _direction.getY() / cos(turnAngle), 0);
	}

	inline void draw() {
		glColor3d(0, 0, 0); //wheels could be torus


		glPushMatrix();
			
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
			glRotated(turnAngle, 0, 0, 1);
			glTranslated(-getPosition().getX(), -getPosition().getY(), -getPosition().getZ());
			
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ ());


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

	void update(double delta_t) {
		//Vector3  oldPosition = getPosition();//(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		setDirectionSpeed();
		setPosition(getPosition().getX()  + _direction.getX()*getSpeed().getX() * delta_t,
			getPosition().getY() + _direction.getY()*getSpeed().getY() * delta_t,
				getPosition().getZ()) ;
	}
};
#endif
