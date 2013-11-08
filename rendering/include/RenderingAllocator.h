#ifndef RENDERING_ALLOCATOR_H_
#define RENDERING_ALLOCATOR_H_


namespace cph {

struct RenderingComponent;

struct RenderingAllocator {

	virtual RenderingComponent* createComponent() = 0;

};

}


#endif