#ifndef __STATICOBJECT__
#define __STATICOBJECT__

#include "GameObject.h"

class StaticObject : public GameObject {

public:
	inline StaticObject() {}
	inline ~StaticObject() {}
};
#endif