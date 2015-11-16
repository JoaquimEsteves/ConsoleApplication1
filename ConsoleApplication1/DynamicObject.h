#ifndef __DYNAMICOBJECT__
#define __DYNAMICOBJECT__

#include "GameObject.h"
#include "Vector3.h"
#include <math.h>


class DynamicObject : public GameObject {
	Vector3 _speed;
	double distance;

public:
	inline DynamicObject() { setSpeed(0, 0, 0); }
	inline virtual ~DynamicObject() {}
	//void update(double delta_t); //em x e Y, em vez de delta_t
	void setSpeed(const Vector3 & speed) { _speed = speed; }
	void setSpeed(double x, double y, double z) { _speed.set(x, y, z); }
	Vector3  getSpeed() { return _speed; }
	void update(double delta_t) {
		if (delta_t == 0) return;
	}

	bool HasColision(GameObject *a) {
		if ((getPosition().getX() + getSize().getX()) > (a->getPosition().getX() - a->getSize().getX()) &&
			(getPosition().getX() - getSize().getX()) < (a->getPosition().getX() + a->getSize().getX()) &&

			(getPosition().getY() + getSize().getY()) > (a->getPosition().getY() - a->getSize().getY()) &&
			(getPosition().getY() - getSize().getY()) < (a->getPosition().getY() + a->getSize().getY()) &&

			(getPosition().getZ() + getSize().getZ()) > (a->getPosition().getZ() - a->getSize().getZ()) &&
			(getPosition().getZ() - getSize().getZ()) < (a->getPosition().getZ() + a->getSize().getZ()))
		{
			return 1;
		}
		return 0;
		/* distance = sqrt(exp2(getPosition().getX() - (a->getPosition().getX())) +
				 exp2(getPosition().getY() - (a->getPosition().getY())));
		if (distance < (getRadius() + a->getRadius())){
			return 1;
		}
		return 0;*/
	}
};
#endif

