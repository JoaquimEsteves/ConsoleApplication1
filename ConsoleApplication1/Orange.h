#ifndef __ORANGE__
#define __ORANGE__


#include "Obstacle.h"     
#include "Car.h"
#include "GL\glut.h"
#include <time.h>
#include <math.h>

class Orange : public Obstacle {
	int numberRings = 20;
	int _maxSpeed = 10;
	int _lost = 0;
	double _turnAngle = 0;
	double _counter = 0;
	GLfloat stem_amb[4] = { 0.0215f,0.1745f,0.0215f,1.0f };
	GLfloat stem_diff[4] = { 0.07568f,0.61424f,0.07568f,1.0f };
	GLfloat stem_spec[4] = { 0.f,0.0f,0.0f,1.0f };
	GLfloat stem_shine = 1.0f;
	//bool _visible = true;
	//ACTIVAR DEPTH BUFFER
public:

	inline  Orange() {
	}
	inline  Orange(double x, double y, double z) {
		setPosition(x, y, z);
		setSize(.5, .5, .5);
		_counter = rand() % 20 + 1;
	}
	void stemMaterial() {
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, stem_amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, stem_diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, stem_spec);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, stem_shine);
	}
	inline virtual ~Orange() {}
	void setLost(int i) { _lost = i; }
	int getLost() { return _lost; }
	double getCounter() { return _counter; }
	void setCounter(double c) { _counter = c; }
	double getTurnAngle() { return _turnAngle; }
	void setTurnAngle(double turnAngle) { _turnAngle = turnAngle; }
	//void setVisible(bool b)							{ _visible = b; }
	//bool getVisible(bool b)							{ return _visible; }
	inline void draw() {
		//if (_visible) {
		//orange
		glPushMatrix();
		//glColor3d(1.0, 0.5, 0);

		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

		glRotated(_turnAngle * 180 / PI, 1, 0, 0);
		//if turnangle > 180...
		glPushMatrix();
			stemMaterial();
			glColor3d(0, 1, 0);
			glTranslated(rand() % 1 + 0, rand() % 1 + 0, .5);
			glScaled(.1, .5, .25);
			glutSolidCube(1);
		glPopMatrix();
			defineMaterial(0.1, 0.05, 0, 1.00,	//Ambient
			0.1, 0.05, 0, 1.00,	//Diffuse
			0.1, 0.05, 0, 1.00,	//Specular
			0.00, 0.00, 0.00, 1.00,	//Emission
			77);					//SHININESS
			glColor3f(1.0, 0.5, 0);
			glutSolidSphere(.5, numberRings, numberRings);
		glPopMatrix();
		//}
	}


	void update(double delta_t, Car * myCar) {
		if (myCar->HasColision(this)) {
			//fazer update à posicao do carro APENAS
			//NADA DE CRIAR DELETAR COISAS
			myCar->setPosition(0, -6.5, 0);
		}
		if (getPosition().getX() >= 9.5 || getPosition().getX() <= -10 ||
			getPosition().getY() >= 9.5 || getPosition().getY() <= -9.5) {
			setPosition(0, 0, 100);
			setSpeed(0, 0, 0);
			setCounter(delta_t + rand() % 20 + 2);
			setLost(-1);
		}
		setTurnAngle(getTurnAngle() + 0.05);
		setPosition(getPosition() + getSpeed() * delta_t);
	}
};
#endif
