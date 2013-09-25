#include <algorithm>

#include "ObjectManagerImpl.h"


using namespace cph;

ObjectManagerImpl::ObjectManagerImpl(int size) :
	size(size), objectArray(new ObjectImpl[size]), objectPool(size), systems()
{
	for(int i = 0; i < size; i++) objectArray[i].setObjectManager(this);
}

ObjectManagerImpl::~ObjectManagerImpl() {
	delete[] objectArray;
}

Object* ObjectManagerImpl::registerObject() {
	if(objectPool.isEmpty()) return 0;
	int id = objectPool.aquire();
	objectArray[id].setId(id);
	return &objectArray[id];
}

void ObjectManagerImpl::addSystem(ObjectSystem* system) {
	systems.push_back(system);
}

void ObjectManagerImpl::removeSystem(ObjectSystem* system) {
	systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
}

void ObjectManagerImpl::releaseId(int id) {
	objectPool.release(id);
}

