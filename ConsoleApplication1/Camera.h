#ifndef __CAMERA__
#define __CAMERA__

#include "Entity.h"
#include "Vector3.h"

class Camera : public Entity {
	double _near;
	double _far;
	Vector3  _up;
	Vector3  _center;
	Vector3  _at;
	//Vector3 * _1; //??????

public:
	Camera(double near, double far) {
		_near = near;
		_far = far;
		_at.set(0, -6, 13.5); //FIX THESE VALUES
		_up.set(0, 0 , 1); //FIX THESE VALUES
	}
	virtual ~Camera() {}
	double getNear()	{ return _near; }
	double getFar()		{ return _far; }
	Vector3 getUp()		{ return _up; }
	Vector3 getAt()		{ return _at; }
	Vector3 getCenter() { return _center; }
	void setCenter(Vector3 c) { _center = c; }
	void setCenter(double x, double y, double z) { _center.set(x, y, z); }
	void setAt(double x, double y, double z) { _at.set(x, y, z); }
	void setUp(double x, double y, double z) { _up.set(x, y, z); }
	virtual void update(GLsizei w, GLsizei h) = 0;
	virtual void computeProjectionMatrix() = 0;
	virtual void computeVisualizationMatrix() = 0;
};
#endif