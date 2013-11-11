#ifndef UNICELLULAR_H_
#define UNICELLULAR_H_

#include "ComponentAllocator.h"
#include "ObjectManager.h"

namespace cph {

	ComponentAllocator& getComponentAllocator();
	void setLog(ObjectManager* objectManager);

}


#endif