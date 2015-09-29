#ifndef __RIVER__
#define __RIVER__

#include "StaticObject.h"

class River: public StaticObject {

public:
	River();
	virtual ~River();
	void draw();
};
#endif
