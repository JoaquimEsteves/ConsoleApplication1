#pragma once
#include "StaticObject.h"

class Road : StaticObject {
public:
	inline Road() {}
	inline ~Road() {}
	inline void draw() {
		glColor3d(0.5, 0.35, 0.05);
		for (int i = -8; i < 8; i++) { //exterior horizontal
			glPushMatrix();
				glTranslated(i, 8, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(i, -8, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();
		}
		//
		for (int i = -5; i < 5; i++) { // interior horizontal
			glPushMatrix();
				glTranslated(i, 5, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(i, -5, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();
		}

		for (int i = -7; i < 8; i++) { //exterior vertical
			glPushMatrix();
				glTranslated(-9, i, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(8, i, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();
		}

		for (int i = -4; i < 5; i++) { //interior vertical
			glPushMatrix();
				glTranslated(-6, i, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();

			glPushMatrix();
				glTranslated(5, i, 0);
				glutSolidTorus(0.05, 0.1, 10, 50);
			glPopMatrix();
		}
	}
};

