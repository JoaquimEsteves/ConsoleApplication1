#pragma once
#include "StaticObject.h"

class Road : StaticObject {
public:
	inline Road() {}
	inline ~Road() {}
	inline void draw() {
		glPushMatrix();
			glColor3f(0, 0.0, 1);
			glScaled(2,2,2);
			glutSolidCube(1);
		glPopMatrix();
	}
};

