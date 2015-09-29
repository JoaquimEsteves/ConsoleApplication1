#ifndef __ORTHOGONALCAMERA__
#define __ORTHOGONALCAMERA__

#include "Camera.h"

class OrthogonalCamera : public Camera {
	double _left;
	double _right;
	double _bottom;
	double _top;

public:
	//No sets and gets asked for, none given
	OrthogonalCamera(double fovy, double aspect, double near, double far);
	virtual ~OrthogonalCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
#endif
