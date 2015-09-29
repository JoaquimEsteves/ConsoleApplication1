#ifndef __PERSPECTIVECAMERA__
#define __PERSPECTIVECAMERA__

#include "Camera.h"

class PerspectiveCamera : public Camera {
	double _fovy;
	double _aspect;
public:
	//No sets and gets asked for, none given
	PerspectiveCamera(double fovy, double aspect, double zNear, double zFar);
	virtual ~PerspectiveCamera();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
#endif
