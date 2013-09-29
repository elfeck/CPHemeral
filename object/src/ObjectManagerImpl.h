#ifndef OBJECT_MANAGER_IMPL_H_
#define OBJECT_MANAGER_IMPL_H_

#include <vector>
#include "MemPool.h"

#include "../include/ObjectManager.h"
#include "../include/Object.h"

#include "ObjectImpl.h"


namespace cph {

class ObjectManagerImpl : public ObjectManager {

private:
	const int size;
	MemPool<ObjectImpl> objectPool;

	std::vector<ObjectSystem*> systems;

public:
	ObjectManagerImpl(int size);
	virtual ~ObjectManagerImpl();

	virtual void addSystem(ObjectSystem* system);
	virtual void removeSystem(ObjectSystem* system);

	virtual Object* createObject();
	void releaseObject(ObjectImpl* object);

};

}

#endif