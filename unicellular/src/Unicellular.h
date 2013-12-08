#ifndef UNICELLULAR_H_
#define UNICELLULAR_H_

#include <string>
#include "CPHObject.h"
#include "ComponentAllocator.h"
#include "Keybindings.h"


namespace cph {

	ComponentAllocator& getComponentAllocator();
	Keybindings& getKeybindings();

	void setLog(ObjectManager* objectManager);

	int getDisplayWidth();
	int getDisplayHeight();
	std::string getAbsolutePath();

}


#endif