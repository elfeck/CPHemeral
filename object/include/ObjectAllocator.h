#ifndef OBJECT_ALLOCATOR_H_
#define OBJECT_ALLOCATOR_H_


namespace cph {

struct Object;

struct ObjectAllocator {

	virtual Object* createObject() = 0;

};

}


#endif