#ifndef OBJECT_MANAGER_IMPL_H_
#define OBJECT_MANAGER_IMPL_H_

#include <vector>
#include "IntPool.h"

#include "../include/ObjectManager.h"
#include "../include/Object.h"

#include "ObjectImpl.h"


namespace cph {

class ObjectManagerImpl : public ObjectManager {

private:
	const int size;
	ObjectImpl* objectArray;
	IntPool objectPool;

	std::vector<ObjectSystem*> systems;

public:
	ObjectManagerImpl(int size);
	~ObjectManagerImpl();

	virtual void addSystem(ObjectSystem* system);
	virtual void removeSystem(ObjectSystem* system);

	virtual Object* registerObject();

	void releaseId(int id);

};

}

#endif