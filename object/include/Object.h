#ifndef OBJECT_H_
#define OBJECT_H_

#include "Component.h"


namespace cph {

struct Object {

	virtual void release() = 0;

	virtual void addComponent(Component* component) = 0;
	virtual void removeComponent(Component* component) = 0;

	virtual Component* getComponent(const char* name) const = 0;

};

}


#endif