#ifndef OBJECT_SYSTEM_H_
#define OBJECT_SYSTEM_H_

#include "ObjectManager.h"


namespace cph {

struct ObjectSystem {

	virtual void execute(ObjectManager* objectManager, long delta) = 0;

};

}

#endif