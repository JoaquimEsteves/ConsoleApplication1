#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include "Entity.h"
class GameObject : public Entity
{

public:
	inline GameObject() {}
	inline virtual ~GameObject() {}
	void draw();
	//virtual void update(double delta_t) = 0; //que raio é um in delta_t:double?
};


#endif
