#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "StaticObject.h"
#include "Vector3.h"
#include "GL/glut.h"

class Background : public StaticObject
{
public:
	inline Background() {
	}
	inline virtual ~Background() {}
	inline void draw() {
		for (int i = -10; i < 10; i++) {
			for (int j = -9; j < 10; j++) {
				if ((i + j) % 2) defineMaterialBlue();
				else defineMaterialWhite();

				glPushMatrix();
				glTranslated(i, j, 0);
				glScaled(1, 1, 0);
				//glutSolidCube(1);
				drawCube();
				glPopMatrix();

			}
		}
	}
	void defineMaterialBlue() {
		defineMaterial(0.074902, 0.0847059, 0.1847059, 1.00,	//Ambient
			0.074902, 0.0847059, 0.1847059, 1.00,	//Diffuse
			0.074902, 0.0847059, 0.1847059, 1.00,	//Specular
			0,0,0, 1.00,	//Emission
			77);					//SHININESS
		glColor3f(0.74902, 0.847059, 1.847059);
	}

	void defineMaterialWhite() {
		defineMaterial(0.1, 0.1, 0.1, 1.00,	//Ambient
			0.1, 0.1, 0.1, 1.00,	//Diffuse
			0.1, 0.1, 0.1, 1.00,	//Specular
			0,0,0, 1.00,	//Emission
			77);					//SHININESS
		glColor3f(1,1,1);
	}
	void drawCube() {
		glBegin(GL_POLYGON);
		glVertex3f(-1, 1, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, -1, 0);
		glVertex3f(-1, -1, 0);
		glEnd();
		//Upper case
		glBegin(GL_POLYGON);
		glVertex3f(-1, 1, 1);
		glVertex3f(1, 1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(-1, -1, 1);
		glEnd();
		//left side
		glBegin(GL_POLYGON);
		glVertex3f(-1, -1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(1, -1, 0);
		glVertex3f(-1, -1, 0);
		glEnd();
		//right side
		glBegin(GL_POLYGON);
		glVertex3f(1, 1, 1);
		glVertex3f(-1, 1, 1);
		glVertex3f(-1, 1, 0);
		glVertex3f(1, 1, 0);
		glEnd();
		//back
		glBegin(GL_POLYGON);
		glVertex3f(1, 1, 0);
		glVertex3f(1, 1, 1);
		glVertex3f(1, -1, 1);
		glVertex3f(1, -1, 0);
		glEnd();
		//front
		glBegin(GL_POLYGON);
		glVertex3f(-1, 1, 0);
		glVertex3f(-1, 1, 1);
		glVertex3f(-1, -1, 1);
		glVertex3f(-1, -1, 0);
		glEnd();
	}
};

#endif
