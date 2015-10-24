#ifndef __ORANGE__
#define __ORANGE__

#include "Obstacle.h"                             
#include "GL\glut.h"
#include <time.h> 
#include <stdlib.h>
  

class Orange : public Obstacle {
	int numberRings = 20;
	int _maxSpeed = 10;
public:
	/*
	initial positions set as:
	-3,7.5,0
	7, 7, 0
	-8.5, -1.5, 0
	*/
	inline  Orange() {
	}
	inline  Orange(double x, double y, double z) {
		setPosition(x, y, z);
		setRadius(1);
		setSize(1, 1, 1);
		double randonm_speed = (rand() % _maxSpeed) + 1;
		if ((int)randonm_speed % 2 == 0) {
			randonm_speed *= 0.00001;
			setSpeed(randonm_speed, 0, 0);
		}
		else{
			randonm_speed *= 0.0001;
			setSpeed(0, randonm_speed, 0);
		}
	}

	inline virtual ~Orange() {}
	inline void draw() {
		//orange
		glColor3d(1.0, 0.5, 0);

		glPushMatrix();
		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

		glutSolidSphere(1, numberRings, numberRings);
		glPopMatrix();

	}
	void update(double delta_t) {
		setPosition(getPosition() + getSpeed() * delta_t);
	}
};
#endif
