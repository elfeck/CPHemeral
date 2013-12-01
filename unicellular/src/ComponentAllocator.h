#ifndef COMPONENT_ALLOCATOR
#define COMPONENT_ALLOCATOR

#include "RenderingAllocator.h"
#include "LogicAllocator.h"


namespace cph {

class ComponentAllocator {

private:
	RenderingAllocator* renderAlloc;
	LogicAllocator* logicAlloc;


public:
	ComponentAllocator();
	~ComponentAllocator();

	void setRenderAlloc(RenderingAllocator* alloc);
	void setLogicAlloc(LogicAllocator* alloc);

	RenderingAllocator* getRenderingAllocator();
	LogicAllocator* getLogicAllocator();

};

}

#endif