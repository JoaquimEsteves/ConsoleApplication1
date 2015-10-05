#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__

#include "GameObject.h"
#include "Vector3.h"

class DynamicObject : public GameObject {
	Vector3 * _speed;
public:
	inline DynamicObject() {}
	inline virtual ~DynamicObject() {}
	//void update(double delta_t); //em x e Y, em vez de delta_t
	void setSpeed(const Vector3 & speed);
	void setSpeed(double x, double y, double z);
	Vector3 * getSpeed();
};
#endif
