#ifndef OBJECT_MANAGER_IMPL_H_
#define OBJECT_MANAGER_IMPL_H_

#include <vector>
#include "SingleIdAllocator.h"

#include "../include/ObjectManager.h"
#include "../include/Object.h"

#include "ObjectImpl.h"
#include "ObjectQueueImpl.h"


namespace cph {

class ObjectManagerImpl : public ObjectManager {

private:
	SingleIdAllocator<ObjectImpl> objectAlloc;
	ObjectQueueImpl objectQueue;


public:
	ObjectManagerImpl();
	virtual ~ObjectManagerImpl();

	virtual Object* createObject();
	virtual ObjectQueue* tempGetObjectsWith(std::uint8_t sysId);

	void destroyObject(ObjectImpl* object);

};

}

#endif