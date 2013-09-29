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

void ObjectImpl::release() {
	objectManager->releaseObject(this);
}

void ObjectImpl::addComponent(Component* component) {
	for(std::vector<Component*>::size_type i = 0; i < components.size(); i++) {
		if(strcmp(components.at(i)->getName(), component->getName()) == 0) return;
	}
	components.push_back(component);
}

void ObjectImpl::removeComponent(Component* component) {
	components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

Component* ObjectImpl::getComponent(const char* name) const {
	for(std::vector<Component*>::size_type i = 0; i < components.size(); i++) {
		if(strcmp(components.at(i)->getName(), name) == 0) return components.at(i);
	}
	return 0;
}

void ObjectImpl::setObjectManager(ObjectManagerImpl* objectManager) {
	this->objectManager = objectManager;
}