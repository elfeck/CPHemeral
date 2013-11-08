#ifndef OBJECT_MANAGER_H_
#define OBJECT_MANAGER_H_

#ifdef OBJECT_EXPORTS
#define CPH_OBJECT_DLL _declspec(dllexport)
#else
#define CPH_OBJECT_DLL _declspec(dllimport)
#endif

#include <cstdint>
#include "ObjectAllocator.h"


namespace cph {

struct Object;
struct ObjectQueue;
class Log;

struct ObjectManager : public ObjectAllocator {

	virtual Object* createObject() = 0;
	virtual ObjectQueue* tempGetObjectsWith(std::uint8_t sysId) = 0;
	virtual void setLog(Log* log, const char* target = 0) = 0;

	virtual ~ObjectManager() = 0;

};

extern "C" {
	CPH_OBJECT_DLL ObjectManager* createObjectManager();
	CPH_OBJECT_DLL void deleteObjectManager(ObjectManager* objectManager);
}

}

#endif