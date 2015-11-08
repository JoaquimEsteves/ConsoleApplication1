#ifndef __LIGHTSOURCE__	
#define __LIGHTSOURCE__

#include "GameManager.h"
#include "Vector3.h"
#include "GL\glut.h"
class LightSource
{
	GLfloat  _ambient[4];
	GLfloat  _diffuse[4];
	GLfloat  _specular[4];
	Vector3 _position;
	Vector3 _direction;

	double	_cut_off;
	double	_exponent;
	GLenum _num;
	bool	_state;
public:
	LightSource(GLenum number) {
		_num = number; _state = false; 
		_cut_off = 180;
		_direction.set(0, 0, 0);
	}
	~LightSource() {}
	bool getState() {
		return _state;
	}
	bool setState(bool state) {
		_state = state;
		if (state) {
			glEnable(GL_LIGHT0 + _num);
		}
		else {
			glDisable(GL_LIGHT0 + _num);
		}
		return _state;
	} 
	GLenum getNum() {
		return _num;
	}

	Vector3 getPosition() {
		return _position;
	}	
	void setPosition(GLdouble x, GLdouble y, GLdouble z) {
		_position.set(x, y, z);
	}
	void setDirection(GLdouble x, GLdouble y, GLdouble z) {
		_direction.set(x, y, z);
	}
	void setCutOff(double cut_off) {
		_cut_off = cut_off;
	}
	void setExponent(double exponent) { 
		_exponent = exponent; 
	}
	void setAmbient(GLfloat  x, GLfloat  y, GLfloat  z, GLfloat  w) {
		_ambient[0] = x;
		_ambient[1] = y;
		_ambient[2] = z;
		_ambient[3] = w;
	}
	void setDiffuse(GLfloat  x, GLfloat  y, GLfloat  z, GLfloat  w) {
		_diffuse[0] = x;
		_diffuse[1] = y;
		_diffuse[2] = z;
		_diffuse[3] = w;
	}
	void setSpecular(GLfloat  x, GLfloat  y, GLfloat  z, GLfloat  w) {
		_specular[0] = x;
		_specular[1] = y;
		_specular[2] = z;
		_specular[3] = w;
	}
	void draw() {
		GLfloat light_position[] = { (GLfloat)_position.getX(), (GLfloat)_position.getY(), (GLfloat)_position.getZ()};
		glLightfv(GL_LIGHT0 + _num, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0 + _num, GL_AMBIENT, _ambient);
		glLightfv(GL_LIGHT0 + _num, GL_DIFFUSE, _diffuse);
		glLightfv(GL_LIGHT0 + _num, GL_SPECULAR, _specular);
		glLightf(GL_LIGHT0 + _num, GL_SPOT_CUTOFF, _cut_off);
		GLfloat direction[] = { (GLfloat)_direction.getX(), (GLfloat)_direction.getY(), (GLfloat)_direction.getZ() };
		glLightfv(GL_LIGHT0 + _num, GL_SPOT_DIRECTION, direction);
		glLightf(GL_LIGHT0 + _num, GL_SPOT_EXPONENT, _exponent);
		return;
	}
};

#endif
