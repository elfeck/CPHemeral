#include <iostream>
#include <algorithm>
#include <cstring>

#include "ObjectManagerImpl.h"

#include "ObjectImpl.h"


using namespace cph;

ObjectImpl::ObjectImpl() :
	objectManager(0), components()
{

}

ObjectImpl::~ObjectImpl() {
	
}

void ObjectImpl::destroy() {
	objectManager->destroyObject(this);
}

void ObjectImpl::addComponent(Component* component) {
	components.insert(std::make_pair(component->getName(), component));
}

void ObjectImpl::removeComponent(Component* component) {
	components.erase(component->getName());
}

bool ObjectImpl::hasComponent(const char* name) const {
	return components.count(name) == 1;
}

Component* ObjectImpl::getComponent(const char* name) const {
	return components.at(name);
}

void ObjectImpl::setObjectManager(ObjectManagerImpl* objectManager) {
	this->objectManager = objectManager;
}