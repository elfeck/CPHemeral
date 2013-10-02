#ifndef RENDERING_SYSTEM_IMPL_H_
#define RENDERING_SYSTEM_IMPL_H_

#include "UniqueAllocator.h"

#include "../include/RenderingSystem.h"
#include "VertexImpl.h"
#include "RenderingComponentImpl.h"


namespace cph {

class RenderingSystemImpl : public RenderingSystem {

private:
	UniqueAllocator<RenderingComponentImpl> componentAlloc;
	UniqueAllocator<VertexImpl> vertexAlloc;
	UniqueAllocator<UniformImpl> uniformAlloc;

public:
	RenderingSystemImpl();
	~RenderingSystemImpl();

	virtual RenderingComponent* createComponent();
	virtual void execute(long delta);

	VertexImpl* allocVertex();
	UniformImpl* allocUniform();

	void releaseComponent(RenderingComponentImpl* component);
	void releaseVertex(VertexImpl* vertex);
	void releaseUniform(UniformImpl* uniform);

};

}

#endif