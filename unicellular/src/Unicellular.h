#ifndef UNICELLULAR_H_
#define UNICELLULAR_H_

#include "ComponentAllocator.h"
#include "ObjectManager.h"
#include "Input.h"
#include <string>


namespace cph {

	ComponentAllocator& getComponentAllocator();
	Input* getInput();

	void setLog(ObjectManager* objectManager);

	int getDisplayWidth();
	int getDisplayHeight();
	std::string getAbsolutePath();

}


#endif