#ifndef RENDER_ALLOCATOR_H_
#define RENDER_ALLOCATOR_H_

#include <unordered_map>
#include "SingleIdAllocator.h"
#include "RenderVertexImpl.h"
#include "RenderUniformImpl.h"
#include "RenderGeomImpl.h"

#include "primitive/PrmiVec4fImpl.h"


namespace cph {

class RenderAllocator {

private:
	std::unordered_map<std::uint32_t, PrimitiveImpl*> primitiveLookup;

	SingleIdAllocator<RenderGeomImpl> geomAlloc;
	SingleIdAllocator<RenderVertexImpl> vertexAlloc;
	SingleIdAllocator<RenderUniformImpl> uniformAlloc;

	SingleIdAllocator<PrmiVec4fImpl> vec4fAlloc;

public:
	RenderAllocator();
	~RenderAllocator();

	RenderGeomImpl* allocRenderGeom();
	RenderVertexImpl* allocRenderVertex();
	RenderUniformImpl* allocRenderUniform();

	PrmiVec4fImpl* allocPrmiVec4f();

	void releaseRenderGeom(RenderGeom* geom);
	void releaseRenderVertex(RenderVertex* vertex);
	void releaseRenderUniform(RenderUniform* uniform);

	void releasePrimitive(Primitive* prmi);
};

}

#endif