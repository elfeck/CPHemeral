#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#ifdef OBJECT_EXPORTS
#define CPH_OBJECT_DLL _declspec(dllexport)
#else
#define CPH_OBJECT_DLL _declspec(dllimport)
#endif

#include "Object.h"
#include "ObjectQueue.h"


namespace cph {

struct ObjectManager {

	virtual Object* createObject() = 0;
	virtual ObjectQueue* tempGetObjectsWith(std::uint64_t sysIds) = 0;

	virtual ~ObjectManager() = 0;

};

extern "C" {
	CPH_OBJECT_DLL ObjectManager* createObjectManager();
	CPH_OBJECT_DLL void deleteObjectManager(ObjectManager* objectManager);
}

}

#endif