#ifndef __CANDLE__
#define __CANDLE__

#include "StaticObject.h"
#include "Vector3.h"
#include "GL/glut.h"
#include <iostream>
#include <cmath>
//extern GameManager *gm;


class Candle : public StaticObject
{
public:
	inline Candle(double x, double y, double z) {
		setPosition(x, y, z);
	}
	//inline virtual ~StreetLight();
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
			glutSolidCube(1);
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
			glutSolidSphere(0.5, 8, 8);
			glPopMatrix();
			glPopMatrix();
		}
};


#endif
