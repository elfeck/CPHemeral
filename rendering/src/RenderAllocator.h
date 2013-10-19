#ifndef RENDER_ALLOCATOR_H_
#define RENDER_ALLOCATOR_H_

#include "SingleIdAllocator.h"
#include "PrimitiveAllocator.h"
#include "RenderVertexImpl.h"
#include "RenderUniformImpl.h"
#include "RenderGeomImpl.h"


namespace cph {

class RenderAllocator {

private:
	PrimitiveAllocator prmiAlloc;
	SingleIdAllocator<RenderGeomImpl> geomAlloc;
	SingleIdAllocator<RenderVertexImpl> vertexAlloc;
	SingleIdAllocator<RenderUniformImpl> uniformAlloc;
	
public:
	RenderAllocator();
	~RenderAllocator();

	RenderGeomImpl* allocRenderGeom();
	RenderVertexImpl* allocRenderVertex();
	RenderUniformImpl* allocRenderUniform();
	
	void releaseRenderGeom(RenderGeom* geom);
	void releaseRenderVertex(RenderVertex* vertex);
	void releaseRenderUniform(RenderUniform* uniform);

};

}

#endif