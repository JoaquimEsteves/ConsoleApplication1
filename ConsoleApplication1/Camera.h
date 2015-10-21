#ifndef __CAMERA__
#define __CAMERA__

#include "Entity.h"
#include "Vector3.h"

class Camera : public Entity {
	double _near;
	double _far;
	Vector3  _up;
	//Vector3  _center;
	Vector3  _at;
	//Vector3 * _1; //??????

public:
	Camera(double near, double far) {
		_near = near;
		_far = far;
		_at.set(0, 10, 120); //FIX THESE VALUES
		_up.set(0, 10, 4); //FIX THESE VALUES
	}
	virtual ~Camera();
	double getNear()	{ return _near; }
	double getFar()		{ return _far; }
	Vector3 getUp()		{ return _up; }
	Vector3 getAt()		{ return _at; }
	void update();
	void computeProjectionMatrix();
	void computeVisualizationMatrix();
};
#endif