#ifndef OBJECT_QUEUE_H_
#define OBJECT_QUEUE_H_


namespace cph {

struct Object;

struct ObjectQueue {

	virtual bool hasElements() const = 0;
	virtual const Object* pop() = 0;

};

}

#endif