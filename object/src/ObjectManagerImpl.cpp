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

ObjectQueue* ObjectManagerImpl::tempGetObjectsWith(std::uint64_t sysIds) {
	std::vector<uint8_t> ids;
	uint8_t id = 0; 
	for(int i = 0; i < 8; i++) {
		id = static_cast<uint8_t>((sysIds >> i * 8) & 0xff);
		if(id != 0) ids.push_back(id);
	}
	objectQueue.clear();
	bool hasAllIds = true;
	for(SingleIdAllocator<ObjectImpl>::iterator it = objectAlloc.begin(); it != objectAlloc.end(); ++it) {
		hasAllIds = true;
		for(std::vector<uint64_t>::size_type i = 0; i < ids.size(); i++) {
			hasAllIds = hasAllIds && it->hasComponent(ids.at(i));
		}
		if(hasAllIds) objectQueue.push(*it);
	}
	return &objectQueue;
}


void ObjectManagerImpl::destroyObject(ObjectImpl* object) {
	objectAlloc.release(object);
}

