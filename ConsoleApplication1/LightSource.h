#ifndef __LIGHTSOURCE__
#define __LIGHTSOURCE__

#include "GameManager.h"
#include "Vector3.h"
#include "GL\glut.h"
class LightSource
{
	double _ambient[4];
	double _diffuse[4];
	double _specular[4];
	Vector3 *_position;
	Vector3 *_direction;

	//GameManager _1; //Was in xml with no sets or gets

	double	_cut_off;
	double	_exponent;
	GLenum _num;
	bool	_state;
public:
	LightSource(GLenum number) {}
	~LightSource() {}
	bool getState();
	void setState(bool state); //SETS RETURNING STUFF; WHAT?!
	GLenum getNum();
	/* WAS IN THE XML. WHAT THE HELL IS A VECTOR 4?
	Vector4* getPosition();	//NO SUCH ATTRIBTE
	void setPosition(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void setDirection(GLdouble x, GLdouble y, GLdouble z);*/
	void setCutOff(double cut_off);
	void setExponent(double exponent);
	//void setAmbient(GLdouble x, GLdouble y, GLdouble z, GLdouble w); NO SUCH ATTRIBUTES AGAIN
	//void setDiffuse(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	//void setSpecular(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	void draw();
};


#endif
