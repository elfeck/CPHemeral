#ifndef OBJECT_MANAGER_IMPL_H_
#define OBJECT_MANAGER_IMPL_H_

#include <vector>
#include "SingleIdAllocator.h"
#include "../include/ObjectManager.h"
#include "../include/Object.h"
#include "Logger.h"
#include "ObjectImpl.h"
#include "ObjectQueueImpl.h"


namespace cph {

class ObjectManagerImpl : public ObjectManager {

private:
	SingleIdAllocator<ObjectImpl> objectAlloc;
	ObjectQueueImpl objectQueue;

	static Logger debugLog;

public:
	ObjectManagerImpl();
	virtual ~ObjectManagerImpl();

	virtual Object* createObject();
	virtual ObjectQueue* tempGetObjectsWith(std::uint8_t sysId);
	virtual void setLog(Log* log, const char* target);

	void destroyObject(ObjectImpl* object);

	static WriteonlyLogger& getDebugLog();

};

}

#endif