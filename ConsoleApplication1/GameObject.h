#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
#include "Vector3.h"
class GameObject : public Entity
{

public:
	inline GameObject() {}
	inline virtual ~GameObject() {}
	void draw();
};


#endif
