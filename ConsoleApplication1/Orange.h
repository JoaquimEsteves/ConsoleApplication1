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
	//bool _visible = true;
	//ACTIVAR DEPTH BUFFER
public:
	
	inline  Orange() {
	}
	inline  Orange(double x, double y, double z) {
		setPosition(x, y, z);
		setSize(.5,.5,.5);
		_counter = rand() % 20 + 1;
	}

	inline virtual ~Orange() {}
	void setLost(int i)								{ _lost = i;}
	int getLost()									{ return _lost; }
	double getCounter()								{ return _counter; }
	void setCounter(double c)						{ _counter = c; }
	double getTurnAngle()							{ return _turnAngle; }
	void setTurnAngle(double turnAngle)				{ _turnAngle = turnAngle; }
	//void setVisible(bool b)							{ _visible = b; }
	//bool getVisible(bool b)							{ return _visible; }
	inline void draw() {
		//if (_visible) {
			//orange
			glPushMatrix();
				glColor3d(1.0, 0.5, 0);
				glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

				glRotated(_turnAngle * 180 / PI, 1, 0, 0);
				//if turnangle > 180...
				glPushMatrix();
					glColor3d(0, 1, 0);
					glTranslated(rand() % 1 + 0, rand() % 1 + 0, .5);
					glScaled(.1, .5, .25);
					glutSolidCube(1);
				glPopMatrix();
				glColor3d(1.0, 0.5, 0);
				glutSolidSphere(.5, numberRings, numberRings);
			glPopMatrix();
		//}
	}

	void update(double delta_t,Car * myCar) {
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
		setTurnAngle(getTurnAngle()+ 0.05);
		setPosition(getPosition() + getSpeed() * delta_t);
	}
};
#endif
