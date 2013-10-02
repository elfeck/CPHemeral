#include "../include/ObjectManager.h"
#include "ObjectManagerImpl.h"


cph::ObjectManager* cph::createObjectManager() {
	return new cph::ObjectManagerImpl();
}

void cph::deleteObjectManager(cph::ObjectManager* objectManager) {
	delete objectManager;
}

cph::ObjectManager::~ObjectManager() {

}


