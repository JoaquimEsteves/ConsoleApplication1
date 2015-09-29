#ifndef __CAMERA__
#define __CAMERA__

#include "Entity.h"
#include "Vector3.h"

class Camera : public Entity {
	double _near;
	double _far;
	Vector3 * _up;
	Vector3 * _center;
	Vector3 * _at;
	Vector3 * _1; //??????

public:
	Camera(double near, double far);
	virtual ~Camera();
	double getNear();
	double getFar();
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
#endif