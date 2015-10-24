#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
#include "Vector3.h"
class GameObject : public Entity
{
	double _radius;
	Vector3 _size;
public:
	inline GameObject() {}
	inline virtual ~GameObject() {}
	void draw();
	void setSize(double x, double y, double z) { _size.set(x, y, z); }
	void setSize(Vector3 s) { _size = s; }
	Vector3 getSize() { return _size; }
	double getRadius() { return _radius; }
	void setRadius(double radius) { _radius = radius; }
};


#endif
