#ifndef LOGIC_ALLOCATOR_H_
#define LOGIC_ALLOCATOR_H_


namespace cph {

struct LogicComponent;

struct LogicAllocator {

	virtual LogicComponent* createComponent() = 0;

};

}

#endif