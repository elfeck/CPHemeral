#include <iostream>
#include <algorithm>
#include <cstring>

#include "ObjectManagerImpl.h"
#include "ObjectImpl.h"


using namespace cph;

ObjectImpl::ObjectImpl(std::uint32_t id) :
	objId(id), objectManager(0), components()
{

}

ObjectImpl::~ObjectImpl() {
	
}

void ObjectImpl::destroy() {
	objectManager->destroyObject(this);
}

void ObjectImpl::addComponent(Component* component) {
	components.insert(std::make_pair(component->getSysId(), component));
	ObjectManagerImpl::getDebugLog() << "[Obj   : [object= " << objId << "] added [component= " << component->getUniqueId()
		<< ", system= " << component->getSysId() << "]" << std::endl;
}

void ObjectImpl::removeComponent(Component* component) {	
	ObjectManagerImpl::getDebugLog() << "[Obj   : [object= " << objId << "] removed [component= " << component->getUniqueId()
		<< ", system= " << component->getSysId() << "]" << std::endl;
	components.erase(component->getSysId());
}

bool ObjectImpl::hasComponent(std::uint8_t sysId) const {
	return components.count(sysId) == 1;
}

Component* ObjectImpl::getComponent(std::uint8_t sysId) const {
	return components.at(sysId);
}

void ObjectImpl::setObjectManager(ObjectManagerImpl* objectManager) {
	this->objectManager = objectManager;
}

std::uint32_t ObjectImpl::getObjId() const {
	return objId;
}