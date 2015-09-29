#ifndef __ENTITY__
#define __ENTITY__

#include "Vector3.h"

class Entity
{
	Vector3 _position;
public:
	inline Entity() {}
	inline ~Entity() {}
	Vector3 * getPosition(void);
	Vector3 * setPosition(double x, double y, double z); /*UM SET A DEVOLVER CENAS?*/
	Vector3 * setPosition(const Vector3 &);
};

#endif