#include <algorithm>

#include "ObjectManagerImpl.h"


using namespace cph;

ObjectManagerImpl::ObjectManagerImpl() :
	objectAlloc(), objectQueue()
{

}

ObjectManagerImpl::~ObjectManagerImpl() {

}

Object* ObjectManagerImpl::createObject() {
	ObjectImpl* obj = objectAlloc.allocate();
	obj->setObjectManager(this);
	return obj;
}

ObjectQueue* ObjectManagerImpl::tempGetObjectsWith(std::uint8_t sysId) {
	objectQueue.clear();
	for(SingleIdAllocator<ObjectImpl>::iterator it = objectAlloc.begin(); it != objectAlloc.end(); ++it) {
		if(it->hasComponent(sysId)) objectQueue.push(*it);
	}
	return &objectQueue;
}


void ObjectManagerImpl::destroyObject(ObjectImpl* object) {
	objectAlloc.release(object);
}

