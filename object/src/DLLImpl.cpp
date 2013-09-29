#include "../include/ObjectManager.h"
#include "ObjectManagerImpl.h"


cph::ObjectManager* cph::createObjectManager(int size) {
	return new cph::ObjectManagerImpl(size);
}

void cph::deleteObjectManager(cph::ObjectManager* objectManager) {
	delete objectManager;
}

cph::ObjectManager::~ObjectManager() {

}


