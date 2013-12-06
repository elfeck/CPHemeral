#ifndef UNICELLULAR_H_
#define UNICELLULAR_H_

#include "ComponentAllocator.h"
#include "ObjectManager.h"
#include "Keybindings.h"
#include <string>


namespace cph {

	ComponentAllocator& getComponentAllocator();
	Keybindings& getKeybindings();

	void setLog(ObjectManager* objectManager);

	int getDisplayWidth();
	int getDisplayHeight();
	std::string getAbsolutePath();

}


#endif