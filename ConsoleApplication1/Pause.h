#ifndef __PAUSE__
#define __PAUSE__

#include "StaticObject.h"
#include "Vector3.h"
#include "GL/glut.h"


class Pause : public StaticObject {

public:
	inline Pause() {
		//setTexture(Texture::loadBMP_custom("paused.bmp"), 147);

	}
	inline ~Pause() {}
	void draw(int camera, double x, double y, double z) {
		defineMaterial(0.1, 0.1, 0.1, 1.00,	//Ambient
			0.1, 0.1, 0.1, 1.00,	//Diffuse
			0.1, 0.1, 0.1, 1.00,	//Specular
			0, 0, 0, 0.5,	//Emission
			77);					//SHININESS
		glColor3f(0, 0, 0);
		glPushMatrix();
		

		if (camera == 2) {
			glTranslated(x, y, z); //1.5?
			glScaled(2, 2, 2);
			glutSolidCube(1); 
			glPopMatrix();
			return;
		}
		if (camera == 1) glRotated(30, 1, 0, 0);
		glScaled(10, 4, 4);
		glutSolidCube(1); 
		glPopMatrix();
	}
};
#endif
