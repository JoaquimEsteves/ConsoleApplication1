#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
#include "GL\glut.h"

class Car : public DynamicObject {

	double accelaration;
	double maxSpeed;

public:

	inline Car(){
		setPosition(0, 0, 0);
	}
	inline virtual ~Car(){}

	inline void draw() {
		glColor3d(0, 0, 0); //wheels could be torus
		
		glPushMatrix();


		glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ ());


		glPushMatrix();
			glTranslated(0.3, 2.3 + 4, 0);
			glutSolidSphere(0.2, 50, 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.3, 1.7 + 4, 0);
			glutSolidSphere(0.2, 50, 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-0.3, 2.3 + 4, 0);
			glutSolidSphere(0.2, 50, 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-0.3, 1.7 + 4, 0);
			glutSolidSphere(0.2, 50, 50);
		glPopMatrix();

		glColor3d(1, 0, 0);//car

		glPushMatrix();
			glTranslated(0.0, 2 + 4, 0);
			glScaled(2, 1.5, 0.0);
			glutSolidCube(0.5);
		glPopMatrix();

		glPopMatrix();

	}
	void update(double delta_t) {
		//Vector3 oldPosition(getPosition().getX(), getPosition().getY(), getPosition().getZ());
		setPosition(getPosition().getX() + getSpeed().getX() * delta_t,
			getPosition().getY() + getSpeed().getY() * delta_t,
				getPosition().getZ());
	}
};
#endif
