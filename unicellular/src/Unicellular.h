#ifndef UNICELLULAR_H_
#define UNICELLULAR_H_

#include "ComponentAllocator.h"
#include "ObjectManager.h"
#include <string>


namespace cph {

	ComponentAllocator& getComponentAllocator();
	void setLog(ObjectManager* objectManager);

	std::string getAbsolutePath();

}


#endif