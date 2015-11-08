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
		GLfloat Se) {
		GLfloat Ka[] = { Ka_r, Ka_g, Ka_b, Ka_w };
		GLfloat Kd[] = { Kd_r, Kd_g, Kd_b, Kd_w };
		GLfloat Ks[] = { Ks_r, Ks_g, Ks_b, Ks_w };
		GLfloat Ke[] = { Ke_r, Ke_g, Ke_b, Ke_w };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ka);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Kd);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Ks);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Ke);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &Se);

		glDisable(GL_TEXTURE_2D);
	}
	void defineMaterial(GLfloat Ka_r, GLfloat Ka_g, GLfloat Ka_b, GLfloat Ka_w,
		GLfloat Kd_r, GLfloat Kd_g, GLfloat Kd_b, GLfloat Kd_w,
		GLfloat Ks_r, GLfloat Ks_g, GLfloat Ks_b, GLfloat Ks_w,
		GLfloat Ke_r, GLfloat Ke_g, GLfloat Ke_b, GLfloat Ke_w,
		GLfloat se, GLuint texture) {
		defineMaterial(Ka_r, Ka_g, Ka_b, Ka_w,
			Kd_r, Kd_g, Kd_b, Kd_w,
			Ks_r, Ks_g, Ks_b, Ks_w,
			Ke_r, Ke_g, Ke_b, Ke_w,
			se);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

	}
};


#endif
