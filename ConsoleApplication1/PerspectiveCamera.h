#ifndef __PERSPECTIVECAMERA__
#define __PERSPECTIVECAMERA__

#include "Camera.h"
#include "GL\glut.h"
#include "Car.h"

//GameManager gives me these.



class PerspectiveCamera : public Camera {
	double _fovy;
	double _aspect;
	double _ratio;

	float _xmin = -100;
	float _xmax = 100;
	float _ymin = 0;
	float _ymax = 200;

	Car * _myCar;
public:
	//No sets and gets asked for, none given
	PerspectiveCamera() :Camera(0, 200) { _myCar = NULL; }
	/*Standart perspective*/
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) :Camera(zNear, zFar) {
		_fovy = fovy;
		_aspect = aspect;
		//setAt(0, 100000, 0);
		setUp(0, 0, 1);
		getCenter().set(0, -2, 0);
	}
	/*Camera that follows the car*/
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Car * c) :Camera(zNear, zFar) {
		_fovy = fovy;
		_aspect = aspect;
		/*FOLLOW THAT CAR*/
		_myCar = c;
		setAt(c->getPosition().getX(), c->getPosition().getY() - 20, c->getPosition().getZ() + 20);
		setUp(0, 2, 5); //slightly tipped back camera
		getCenter().set(_myCar->getPosition());
	}
	virtual ~PerspectiveCamera() {}
	void update(GLsizei width, GLsizei height) {
		//glutInitWindowSize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		//My vein attempts at fixing reshapes...
		//glViewport(0, 0, width, height);
		_aspect = (float)width / height;
		_ratio = (_xmax - _xmin) / (_ymax - _ymin);
		if (_ratio < _aspect)
			glScalef(_ratio / _aspect, 1, 1);
		else 
			glScalef(1, _aspect / _ratio, 1);
	}
	void computeProjectionMatrix() {
		//vec 3 up = get up, vec3 at and vec3 center are also gets
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(_fovy, _aspect, getNear(), getFar());
		//chama logo aqui o look at
	}
	void computeVisualizationMatrix() {
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			//Vector3 To(getAt().getX() + getUp().getX(), getAt().getY() + getUp().getZ(), getAt().getZ() - getUp().getY());
			gluLookAt(getAt().getX(), getAt().getY(), getAt().getZ(),					
				getCenter().getX(), getCenter().getY(), getCenter().getZ(),
					getUp().getX(), getUp().getY(), getUp().getZ());				
		
	}
};
#endif
