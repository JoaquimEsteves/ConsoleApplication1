#ifndef __PERSPECTIVECAMERA__
#define __PERSPECTIVECAMERA__

#include "Camera.h"
#include "GL\glut.h"
#include "Car.h"

//GameManager gives me these.
extern int y;
extern int z;


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
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar) :Camera(zNear, zFar) {
		_fovy = fovy;
		_aspect = aspect;
	}
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar, Car * c) :Camera(zNear, zFar) {
		_fovy = fovy;
		_aspect = aspect;
		/*FOLLOW THAT CAR*/
		_myCar = c;
	}
	virtual ~PerspectiveCamera();
	void update(GLsizei width, GLsizei height) {
		_aspect = (double)width / height;
		_ratio = (_xmax - _xmin) / (_ymax - _ymin);
		if (_ratio < _aspect) {
			glScalef(_ratio / _aspect, 1, 1);
			return;
		}
		glScalef(1, _aspect / _ratio, 1);
	}
	void computeProjectionMatrix() {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(_fovy, _aspect, getNear(), getFar());
	}
	void computeVisualizationMatrix() {
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			Vector3 To(getAt().getX() + getUp().getX(), getAt().getY() + getUp().getZ(), getAt().getZ() - getUp().getY());
			gluLookAt(getAt().getX(), getAt().getY(), getAt().getZ(),					
				To.getX(), To.getY(), To.getZ(),								
					getUp().getX(), getUp().getY(), getUp().getZ());				
		
	}
};
#endif
