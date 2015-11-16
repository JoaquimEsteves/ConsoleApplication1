#ifndef __CAR__
#define __CAR__

#define PI 3.14159265
#define CARSPEED 0.0015

#include "DynamicObject.h"
#include "GameManager.h"
#include "Vector3.h"
#include "Entity.h"
#include "GameObject.h"
#include "GL\glut.h"
#include <math.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include <vector>
#include <map>

//extern GameManager *gm;
extern Camera * _currentCamera;
extern std::list<DynamicObject *> _interactable_game_objects;
class Car : public DynamicObject {
	double _maxSpeed = 50;
	double _acceleration = 10;
	double _frictionVal = 1;
	double _specialSpeed = 0;
	double _turnAngle = 0;
	//double _rotation = 0;
	Vector3 _direction;
	bool _forceStart = false;
public:

	inline Car() {
		setPosition(0, -6.5, 0);
		_direction.set(1, 0, 0);
		setSize(.5, .375, 0.1875);

	}
	inline virtual ~Car() {}
	double getMaxSpeed() { return _maxSpeed; }
	double getAcceleration() { return _acceleration; }
	double getTurnAngle() { return _turnAngle; }
	void setSpecialSpeed(double d) { _specialSpeed = d; }
	double getSpecialSpeed() { return _specialSpeed; }
	bool getForceStart() { return _forceStart; }
	void setForceStart(bool b) { _forceStart = b; }
	Vector3 getDirection() { return _direction; }
	void setDirection(Vector3 direction) { _direction = direction; }

	void turnLeft() {
		_turnAngle = _turnAngle + 0.030;
		setDirectionSpeed();
	}
	void turnRight() {
		_turnAngle = _turnAngle - 0.030;
		setDirectionSpeed();
	}

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

	void drawWheel(double x, double y, double z, double Angle) {
		glPushMatrix();
			glTranslated(x, y, .13);

			glRotated(90, 1, 0, 0);
			glScaled(.15,.15, .15);
			//glutSolidTorus(0.075, 0.15, 6, 6);
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);
			for (int i = 0; i < 6; ++i) {
				glVertex3f(sin(i / 6.0 * 2 * PI),
					cos(i / 6.0 * 2 * PI),0);
			}
			glEnd();
			if (z > 0) {
				glBegin(GL_POLYGON);
				for (int i = 0; i < 6; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 0; i < 2; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 1; i < 3; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 2; i < 4; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 3;i < 5; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 4; i < 6; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 5; i < 7; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
			}
			else {
				glBegin(GL_POLYGON);
				for (int i = 0; i < 6; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 0; i < 2; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 1; i < 3; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 2; i < 4; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 3; i < 5; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 4; i < 6; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
				glBegin(GL_POLYGON);
				for (int i = 5; i < 7; ++i) {
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), -1);
					glVertex3f(sin(i / 6.0 * 2 * PI),
						cos(i / 6.0 * 2 * PI), 0);
				}
				glEnd();
			}


			//glutSolidSphere(0.2, 50, 50);
		glPopMatrix();
	}

	void drawStructure(double x, double y, double z) {
		glPushMatrix();
		glTranslated(x, y, z);
		glScaled(2, 1.5, 0.75);
		// glutSolidCube(0.5);
		//Lower case
		glBegin(GL_POLYGON);
		glVertex3f(-.25, .25, 0);
		glVertex3f(.25, .25, 0);
		glVertex3f(.25, -.25, 0);
		glVertex3f(-.25, -.25, 0);
		glEnd();
		//Upper case
		glBegin(GL_POLYGON);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-.25, .25, .25);
		glVertex3f(.25, .25, .25);
		glVertex3f(.25, -.25, .25);
		glVertex3f(-.25, -.25, .25);
		glEnd();
		//left side
		glBegin(GL_POLYGON);
		glNormal3f(0, -1, 0);
		glVertex3f(-.25, -.25, .25);
		glVertex3f(.25, -.25, .25);
		glVertex3f(.25, -.25, 0);
		glVertex3f(-.25, -.25, 0);
		glEnd();
		//right side
		glBegin(GL_POLYGON);
		glNormal3f(0, 1, 0);
		glVertex3f(.25, .25, .25);
		glVertex3f(-.25, .25, .25);
		glVertex3f(-.25, .25, 0);
		glVertex3f(.25, .25, 0);
		glEnd();
		//back
		glBegin(GL_POLYGON);
		glNormal3f(1, 0, 0);
		glVertex3f(.25, .25, 0);
		glVertex3f(.25, .25, .25);
		glVertex3f(.25, -.25, .25);
		glVertex3f(.25, -.25, 0);
		glEnd();
		//front
		glBegin(GL_POLYGON);
		glNormal3f(-1, 0, 0);
		glVertex3f(-.25, .25, 0);
		glVertex3f(-.25, .25, .25);
		glVertex3f(-.25, -.25, .25);
		glVertex3f(-.25, -.25, 0);
		glEnd();
		//MONSTERS
		//metade de cima do carro
		//CIMA_Lower_case

		glBegin(GL_POLYGON);

		glVertex3f(.15, -.25, .25);
		glVertex3f(.15, .25, .25);
		glVertex3f(-.25, .25, .25);
		glVertex3f(-.25, -.25, .25);
		glEnd();

		//tejadilho
		glBegin(GL_POLYGON);

		glVertex3f(.10, -.20, .50);
		glVertex3f(.10, .20, .50);
		glVertex3f(-.20, .20, .50);
		glVertex3f(-.20, -.20, .50);
		glEnd();

		//trap_left
		glBegin(GL_POLYGON);
		
		glVertex3f(.15, .25, .25);
		glVertex3f(-.25, .25, .25);
		glVertex3f(.10, .20, .50);
		glVertex3f(-.20, -.20, .50);
		glEnd();

		//trap_right
		glBegin(GL_POLYGON);
		
		glVertex3f(.15, -.25, .25);
		glVertex3f(-.25, -.25, .25);
		glVertex3f(.10, -.20, .50);
		glVertex3f(-.20, -.20, .50);
		glEnd();

		//trap_front
		glBegin(GL_POLYGON);
		
		glVertex3f(.15, -.25, .25);
		glVertex3f(.15, .25, .25);
		glVertex3f(.10, -.20, .50);
		glVertex3f(.10, .20, .50);
		glEnd();

		//trap_back
		glBegin(GL_POLYGON);
		
		glVertex3f(-.25, -.25, .25);
		glVertex3f(-.25, .25, .25);
		glVertex3f(-.20, -.20, .50);
		glVertex3f(-.20, .20, .50);
		glEnd();
		//MONSTERS BEGONE
		glPopMatrix();
	}

	inline void draw() {
		//METER AQUI AS LUZES
		//glColor3d(0, 0, 0); //wheels could be torus
							//WHEELS ARE NOW TORUS BUT ROTATION IS NOT CORRECT HELP
		glPushMatrix();
			defineMaterial(0.00, 0.00, 0.00, 1.00,	//Ambient
				0.06f, 0.06f, 0.06f, 1.0f,	//Diffuse
				0.0f, 0.0f, 0.0f, 1.0f,	//Specular
				0.00, 0.00, 0.00, 1.00,	//Emission
				1);					//SHININESS
			glColor3f(0.01, 0.01, 0.01);
			
		
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());
			glRotated(_turnAngle * 180 / PI, 0, 0, 1);
			drawWheel(0.25, 0.3, -1, 90);
			drawWheel(0.25, -0.3, 1, 90);

			drawWheel(-0.25, 0.27, -1, 90);

			drawWheel(-0.25, -0.27, 1, 90);

			defineMaterial(1.0f, 0.0f, 0.0f, 1.0f,	//Ambient
				1.0f, 0.0f, 0.0f, 1.0f,	//Diffuse
				1.0f, 0.0f, 0.0f, 1.0f,	//Specular
				0.00, 0.00, 0.00, 1.00,	//Emission
				128);					//SHININESS
			glColor3f(1.0, 0, 0);

			drawStructure(0, 0, .1);
		glPopMatrix();

	}

	void update(double delta_t) {
		//A maneira OO de fazer isto seria por esta verificacao no GameObject e depois chama o update com
		// DynamicObject::update(delta_t), ver o resultado ou fazer ate' um try catch.
		//O problema é que o retorno de nested functions e' manhoso, o return da funcao update pai
		//em pouco altera a funcao filho.
		//Como tal, ha' repeticao de codigo, mas e mais eficiente, e menos obtuso.
		if (delta_t == 0) return;
		if (getPosition().getX() >= 9.5 || getPosition().getX() <= -10 ||
			getPosition().getY() >= 9.5 || getPosition().getY() <= -9.5) {
			setPosition(0, -6.5, 0);
		}
		friction();
		setPosition(getPosition() + getDirection() * _specialSpeed * CARSPEED);
	}
};
#endif
