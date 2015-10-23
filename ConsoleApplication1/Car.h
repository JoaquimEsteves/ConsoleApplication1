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
	double _maxSpeed = 50;
	double _acceleration = 10;
	double _frictionVal = 1;
	double _specialSpeed = 0;
	double _turnAngle = 0;
	//double _rotation = 0;
	Vector3 _direction;

public:

	inline Car(){
		setPosition(0, 4, 0);
		_direction.set(1, 0, 0);

	}
	inline virtual ~Car()			{}
	double getMaxSpeed()			{ return _maxSpeed; }
	double getAcceleration()		{ return _acceleration; }
	double getTurnAngle()			{ return _turnAngle;  }
	void setSpecialSpeed(double d)	{ _specialSpeed = d; }
	double getSpecialSpeed()		{ return _specialSpeed; }
	Vector3 getDirection()			{ return _direction; }

	void turnLeft() {
		_turnAngle =  _turnAngle + 0.065;
		setDirectionSpeed();
	}
	void turnRight() {
		_turnAngle = _turnAngle - 0.065;
		setDirectionSpeed();
	}

	/*void  setDirectionSpeed() {
		double x = _direction.getX()*cos(turnAngle) ;
		double y = _direction.getX()*sin(turnAngle);
		double z = 0;
		_direction.set(x / sqrt(x*x + y*y + z*z), y / sqrt(x*x + y*y + z*z), z / sqrt(x*x + y*y + z*z));
	}*/

	//HELLO
	void  setDirectionSpeed() {
		double x, y;
		if (_direction.getX() < 0) {
			x = _direction.getX()*cos(PI + _turnAngle) /*- direction.getY()*sin(turnAngle)*/;
			y = _direction.getX()*sin(PI + _turnAngle) /*+ direction.getY()*cos(turnAngle)*/;
		}
		else {
			x = _direction.getX()*cos(_turnAngle) /*- direction.getY()*sin(turnAngle)*/;
			y = _direction.getX()*sin(_turnAngle) /*+ direction.getY()*cos(turnAngle)*/;
		}
		double z = 0;
		_direction.set(x / sqrt(x*x + y*y + z*z), y / sqrt(x*x + y*y + z*z), z / sqrt(x*x + y*y + z*z));
	}
	//GOODBYE


	void friction() {
		if (_specialSpeed == 0)
			return;
		if (_specialSpeed > 0)
			_specialSpeed -= _frictionVal;
		if (_specialSpeed < 0)
			_specialSpeed += _frictionVal;
	}

	inline void draw() {
		glColor3d(1, 1, 1); //wheels could be torus
		//WHEELS ARE NOW TORUS BUT ROTATION IS NOT CORRECT HELP

		glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());



			glRotated(_turnAngle * 180 / PI, 0, 0, 1);
	

			glPushMatrix();
				glTranslated(0.25, 0.4, 0);
				glRotated(80 * 180 / PI, 1, 0, 0);
				glutSolidTorus(0.075, 0.15, 10, 10);
				//glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(0.25, -0.4, 0);
				
				glRotated(96 * 180 / PI, 1, 0, 0);
				
				glutSolidTorus(0.075, 0.15, 10, 10);

				//glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-0.25, 0.35, 0);
				glRotated(80 * 180 / PI, 1, 0, 0);
				glutSolidTorus(0.075, 0.15, 10, 10);
				//glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(-0.25, -0.35, 0);
				glRotated(80 * 180 / PI, 1, 0, 0);
				glutSolidTorus(0.075, 0.15, 10, 10);
				//glutSolidSphere(0.2, 50, 50);
			glPopMatrix();

			glColor3d(1, 0, 0);//car

			glPushMatrix();
				glTranslated(0, 0, .10);
				glScaled(2, 1.5, 0.75);
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
		setPosition(getPosition() + getDirection() * _specialSpeed * CARSPEED * delta_t);
	}
};
#endif
