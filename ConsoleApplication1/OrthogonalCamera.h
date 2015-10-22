#ifndef __ORTHOGONALCAMERA__
#define __ORTHOGONALCAMERA__

#include "Camera.h"
#include "GL\glut.h"

class OrthogonalCamera : public Camera {
	double _left;
	double _right;
	double _bottom;
	double _top;
	/* Used only in update, so NO GETTERS OR SETTERS*/
	float _aspect;
	float _ratio;
	/*No need for zNear or zFar thanks to good ol' gluOrtho2D, they are initialized as -1 and 1 respectively*/
	

public:
	//No sets and gets asked for, none given
	OrthogonalCamera(double l, double r, double b,double t, double near, double far) :Camera(near, far) {
		_left = l;
		_right = r;
		_bottom = b;
		_top = t;
	}
	virtual ~OrthogonalCamera() {}
	void update(GLsizei width, GLsizei height) {
		_ratio = (_right - _left) / (_top - _bottom);
		_aspect = (float) width / height;
		if (_ratio < _aspect) {
			float temp = ((_top - _bottom) * _aspect - (_right - _left)) / 2;
			gluOrtho2D(_left - temp, _right + temp, _bottom, _top/*, getNear(), getFar()*/);
			return;
		}
		float temp = ((_right - _left) / _aspect - (_top - _bottom)) / 2;
		gluOrtho2D(_left, _right, _bottom - temp, _top + temp/*, getNear(), getFar()*/);

	}
	void computeProjectionMatrix() {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	}
	void computeVisualizationMatrix() {
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
};
#endif
