
#ifndef __CANDLE__
#define __CANDLE__

#include "StaticObject.h"
#include "Vector3.h"
#include "GL/glut.h"
#include <iostream>
#include <cmath>


class Candle : public StaticObject
{
public:
	inline Candle(double x, double y, double z) {
		setPosition(x, y, z);
	}
	inline virtual ~Candle() {}
	void draw(bool light_on) {
			glPushMatrix();
			glTranslated(getPosition().getX(), getPosition().getY(), getPosition().getZ());

			/*glRotatef(atan(-direction.getY() / direction.getX()) * 180 / PI, 0, 0, 1);
			if (getPosition().getX() < 0) glRotatef(180, 0, 0, 1);
			*/
			glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			defineMaterial(0.66, 0.66, 0.66, 1.00,	//Ambient
				0.66, 0.66, 0.66, 1.00,	//Diffuse
				1.00, 1.00, 1.00, 1.00,	//Specular
				0.00, 0.00, 0.00, 1.00,	//Emission
				77);					//SHININESS

			glPushMatrix(),
			//glutSolidCube(1);
				glBegin(GL_POLYGON);
			glVertex3f(-0.5, 0.5, 0);
			glVertex3f(0.5, 0.5, 0);
			glVertex3f(0.5, -0.5, 0);
			glVertex3f(-0.5, -0.5, 0);
			glEnd();
			//Upper case
			glBegin(GL_POLYGON);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glEnd();
			//left side
			glBegin(GL_POLYGON);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, 0);
			glVertex3f(-0.5, -0.5, 0);
			glEnd();
			//right side
			glBegin(GL_POLYGON);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, 0.5, 0);
			glVertex3f(0.5, 0.5, 0);
			glEnd();
			//back
			glBegin(GL_POLYGON);
			glVertex3f(0.5, 0.5, 0);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, -0.5, 0.5);
			glVertex3f(0.5, -0.5, 0);
			glEnd();
			//front
			glBegin(GL_POLYGON);
			glVertex3f(-0.5, 0.5, 0);
			glVertex3f(-0.5, 0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0.5);
			glVertex3f(-0.5, -0.5, 0);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			if (light_on)
				defineMaterial(1.00, 1.00, 0.00, 1.00,	//Ambient
					1.00, 1.00, 0.00, 1.00,	//Diffuse
					1.00, 1.00, 1.00, 1.00,	//Specular
					1.00, 1.00, 0.00, 1.00,	//Emission
					77);					//SHININESS
			else
				defineMaterial(1.00, 1.00, 0.00, 1.00,	//Ambient
					1.00, 1.00, 0.00, 1.00,	//Diffuse
					1.00, 1.00, 1.00, 1.00,	//Specular
					0.00, 0.00, 0.00, 1.00,	//Emission
					77);					//SHININESS
				
			glTranslated(0, 0, 1);
			glutSolidSphere(0.5, 10, 10);
			glPopMatrix();
			glPopMatrix();
		}
};


#endif
