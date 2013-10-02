#include <algorithm>

#include "ObjectManagerImpl.h"


using namespace cph;

ObjectManagerImpl::ObjectManagerImpl() :
	objectAlloc(), systems()
{

}

ObjectManagerImpl::~ObjectManagerImpl() {

}

Object* ObjectManagerImpl::createObject() {
	ObjectImpl* obj = objectAlloc.allocate();
	obj->setObjectManager(this);
	return obj;
}

void ObjectManagerImpl::addSystem(ObjectSystem* system) {
	systems.push_back(system);
}

void ObjectManagerImpl::removeSystem(ObjectSystem* system) {
	systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
}

void ObjectManagerImpl::destroyObject(ObjectImpl* object) {
	objectAlloc.release(object);
}

