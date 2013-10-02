#ifndef OBJECT_MANAGER_IMPL_H_
#define OBJECT_MANAGER_IMPL_H_

#include <vector>
#include "UniqueAllocator.h"

#include "../include/ObjectManager.h"
#include "../include/Object.h"

#include "ObjectImpl.h"


namespace cph {

class ObjectManagerImpl : public ObjectManager {

private:
	UniqueAllocator<ObjectImpl> objectAlloc;
	std::vector<ObjectSystem*> systems;

public:
	ObjectManagerImpl();
	virtual ~ObjectManagerImpl();

	virtual void addSystem(ObjectSystem* system);
	virtual void removeSystem(ObjectSystem* system);

	virtual Object* createObject();
	void destroyObject(ObjectImpl* object);

};

}

#endif