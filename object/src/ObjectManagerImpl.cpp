#include <algorithm>

#include "ObjectManagerImpl.h"


using namespace cph;

ObjectManagerImpl::ObjectManagerImpl() :
	objectAlloc()
{

}

ObjectManagerImpl::~ObjectManagerImpl() {

}

Object* ObjectManagerImpl::createObject() {
	ObjectImpl* obj = objectAlloc.allocate();
	obj->setObjectManager(this);
	return obj;
}

Object* ObjectManagerImpl::at(int index) const {
	return objectAlloc.at(index);
}

int ObjectManagerImpl::size() const {
	return objectAlloc.size();
}

void ObjectManagerImpl::destroyObject(ObjectImpl* object) {
	objectAlloc.release(object);
}

