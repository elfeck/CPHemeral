#include <algorithm>

#include "ObjectManagerImpl.h"


using namespace cph;

Logger ObjectManagerImpl::debugLog("[ ObjManag ]");

WriteonlyLogger& ObjectManagerImpl::getDebugLog() {
	return debugLog;
}

ObjectManagerImpl::ObjectManagerImpl() :
	objectAlloc(), objectQueue()
{

}

ObjectManagerImpl::~ObjectManagerImpl() {

}

Object* ObjectManagerImpl::createObject() {
	ObjectImpl* obj = objectAlloc.allocate();
	obj->setObjectManager(this);
	debugLog.pre() << "Created [Object= " << obj->getObjId() << "]" << std::endl;
	return obj;
}

ObjectQueue* ObjectManagerImpl::tempGetObjectsWith(std::uint8_t sysId) {
	objectQueue.clear();
	for(SingleIdAllocator<ObjectImpl>::iterator it = objectAlloc.begin(); it != objectAlloc.end(); ++it) {
		if(it->hasComponent(sysId)) objectQueue.push(*it);
	}
	return &objectQueue;
}

void ObjectManagerImpl::setLog(Log* log, const char* target) {
	if(log != 0) {
		if(log->getTarget() == "debug") debugLog.setLogPtr(log);
	} else if(target != 0) {
		if(strcmp(target, "debug") == 0) debugLog.setLogPtr(0);
	}
}

void ObjectManagerImpl::destroyObject(ObjectImpl* object) {
	debugLog.pre() << "Destroyed [Object= " << object->getObjId() << "]" << std::endl;
	objectAlloc.release(object);
}

