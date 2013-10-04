#ifndef OBJECT_QUEUE_IMPL
#define OBJECT_QUEUE_IMPL

#include <vector>

#include "../include/ObjectQueue.h"
#include "../include/Object.h"


namespace cph {

class ObjectQueueImpl : public ObjectQueue {

private:
	std::vector<const Object*> objects;

public:
	ObjectQueueImpl();
	~ObjectQueueImpl();

	virtual const Object* pop();
	virtual bool hasElements() const;

	void push(const Object* object);
	void clear();

};

}

#endif