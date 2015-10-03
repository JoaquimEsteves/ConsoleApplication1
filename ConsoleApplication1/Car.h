#ifndef __CAR__
#define __CAR__

#include "DynamicObject.h"
#include "GL\glut.h"

class Car : public DynamicObject {
	Vector3 *carStruct;
	bool draw_wired = false;

public:
	inline void toggleWireSolid() { 
		if (draw_wired == true)
			draw_wired = false;
		else
			draw_wired = true;
	}
	inline Car(){}
	inline virtual ~Car(){}
	inline void draw() {
		if (draw_wired)
			drawWired();
		else
			drawSolid();
	}
	inline void drawWired() {
		glColor3d(0, 0, 0); //wheels could be torus

		glPushMatrix();
			glTranslated(0.3, 2.3 + 4, 0);
			glutWireSphere(0.2, 50, 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.3, 1.7 + 4, 0);
			glutWireSphere(0.2, 50, 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-0.3, 2.3 + 4, 0);
			glutWireSphere(0.2, 50, 50);
		glPopMatrix();

		glPushMatrix();
			glTranslated(-0.3, 1.7 + 4, 0);
			glutWireSphere(0.2, 50, 50);
		glPopMatrix();

		glColor3d(1, 0, 0);//car

		glPushMatrix();
			glTranslated(1.0, 1.0, 0);
			glScaled(2, 1.5, 0.0);
			glutWireCube(0.5);
		glPopMatrix();
	}
	inline void drawSolid() {
		glColor3d(0, 0, 0); //wheels could be torus

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
	}
	//void drawWheelRight();
	//void drawWheelLeft();
	//void drawAllWheels();
	/*inline void drawCarStructure() {
		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3f(-0.4, -0.7, 0.0);
			glVertex3f(0.4, -0.7, 0.0);
			glVertex3f(0.4, 0.7, 0.0);
			glVertex3f(-0.4, 0.7, 0.0);
			glEnd();
		glPopMatrix();
	}*/
};
#endif
