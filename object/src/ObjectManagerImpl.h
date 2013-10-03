#ifndef OBJECT_MANAGER_IMPL_H_
#define OBJECT_MANAGER_IMPL_H_

#include <vector>
#include "SingleAllocator.h"

#include "../include/ObjectManager.h"
#include "../include/Object.h"

#include "ObjectImpl.h"


namespace cph {

class ObjectManagerImpl : public ObjectManager {

private:
	SingleAllocator<ObjectImpl> objectAlloc;

public:
	ObjectManagerImpl();
	virtual ~ObjectManagerImpl();

	virtual Object* createObject();
	virtual Object* at(int index) const;
	virtual int size() const;

	void destroyObject(ObjectImpl* object);

};

}

#endif