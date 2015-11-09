#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
#include "Vector3.h"
#include "GL/glut.h"
class GameObject : public Entity
{
	double _radius;
	Vector3 _size;
public:
	inline GameObject() {}
	inline virtual ~GameObject() {}
	void draw();
	void setSize(double x, double y, double z) { _size.set(x, y, z); }
	void setSize(Vector3 s) { _size = s; }
	Vector3 getSize() { return _size; }
	double getRadius() { return _radius; }
	void setRadius(double radius) { _radius = radius; }
	void defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
		GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
		GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
		GLfloat Ke_r, GLfloat Ke_g, GLfloat Ke_b, GLfloat Ke_w,
		GLfloat Si) {
		GLfloat Ka[4] = { Ka_r, Ka_g, Ka_b, Ka_w };
		GLfloat Kd[4] = { Kd_r, Kd_g, Kd_b, Kd_w };
		GLfloat Ks[4] = { Ks_r, Ks_g, Ks_b, Ks_w };
		GLfloat Ke[4] = { Ke_r, Ke_g, Ke_b, Ke_w };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ka);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Kd);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Ks);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Ke);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &Si);

	}

};


#endif
