#ifndef __ROADSIDE__
#define __ROADSIDE__

#include "StaticObject.h"

class Roadside : public StaticObject {

public:
	Roadside();
	virtual ~Roadside();
	void draw();
};
#endif
