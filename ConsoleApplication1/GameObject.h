#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
#include "Vector3.h"
class GameObject : public Entity
{
	double _radius;
public:
	inline GameObject() {}
	inline virtual ~GameObject() {}
	void draw();
	double getRadius() { return _radius; }
	void setRadius(double radius) { _radius = radius; }
};


#endif
