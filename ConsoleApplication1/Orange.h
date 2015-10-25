#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"                             
#include "GL\glut.h"
#include <time.h>
  

class Orange : public Obstacle {
	int numberRings = 20;
	int _maxSpeed = 10;
	double _turnAngle = 0;
public:
	
	inline  Orange() {
	}
	inline  Orange(double x, double y, double z) {
		setPosition(x, y, z);
		setSize(1,1,1);
		
	}

	inline virtual ~Orange() {}

	double getTurnAngle() { return _turnAngle; }
	void setTurnAngle(double turnAngle) { _turnAngle = turnAngle; }

	inline void draw1() {
		//orange
		glColor3d(1.0, 0.5, 0);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

		glRotated(_turnAngle * 180 / PI, 1, 0, 0);

		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();

	}
	inline void draw2() {
		//orange
		glColor3d(1.0, 0.5, 0);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

		glRotated(_turnAngle * 180 / PI, 0, 1, 0);

		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();

	}

	void update(double delta_t) {
		setTurnAngle(getTurnAngle()+ 0.05);
		setPosition(getPosition() + getSpeed() * delta_t);
	}
};
#endif
