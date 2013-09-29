#include <algorithm>

#include "ObjectManagerImpl.h"


using namespace cph;

ObjectManagerImpl::ObjectManagerImpl(int size) :
	size(size), objectPool(1, size), systems()
{
	objectPool.preAllocate(1);
}

ObjectManagerImpl::~ObjectManagerImpl() {

}

Object* ObjectManagerImpl::createObject() {
	ObjectImpl* obj = objectPool.allocate();
	obj->setObjectManager(this);
	return obj;
}

void ObjectManagerImpl::addSystem(ObjectSystem* system) {
	systems.push_back(system);
}

void ObjectManagerImpl::removeSystem(ObjectSystem* system) {
	systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
}

void ObjectManagerImpl::releaseObject(ObjectImpl* object) {
	objectPool.release(object);
}

