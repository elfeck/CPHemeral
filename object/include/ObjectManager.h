#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#ifdef OBJECT_EXPORTS
#define CPH_OBJECT_DLL _declspec(dllexport)
#else
#define CPH_OBJECT_DLL _declspec(dllimport)
#endif

#include "ObjectSystem.h"
#include "Object.h"


namespace cph {

struct ObjectManager {

	virtual void addSystem(ObjectSystem* system) = 0;
	virtual void removeSystem(ObjectSystem* system) = 0;

	virtual Object* registerObject() = 0;

};

extern "C" {
	CPH_OBJECT_DLL ObjectManager* createObjectManager(int size = 1024);
	CPH_OBJECT_DLL void deleteObjectManager(ObjectManager* objectManager);
}

}

#endif