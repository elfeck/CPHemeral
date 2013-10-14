#ifndef RENDER_ALLOCATOR_H_
#define RENDER_ALLOCATOR_H_

#include <unordered_map>
#include "SingleIdAllocator.h"
#include "RenderVertexImpl.h"
#include "RenderUniformImpl.h"
#include "RenderGeomImpl.h"

#include "primitive/PrmiVec1fImpl.h"
#include "primitive/PrmiVec2fImpl.h"
#include "primitive/PrmiVec3fImpl.h"
#include "primitive/PrmiVec4fImpl.h"


namespace cph {

class RenderAllocator {

private:
	std::unordered_map<std::uint32_t, PrimitiveImpl*> primitiveLookup;

	SingleIdAllocator<RenderGeomImpl> geomAlloc;
	SingleIdAllocator<RenderVertexImpl> vertexAlloc;
	SingleIdAllocator<RenderUniformImpl> uniformAlloc;

	SingleIdAllocator<PrmiVec1fImpl> vec1fAlloc;
	SingleIdAllocator<PrmiVec2fImpl> vec2fAlloc;
	SingleIdAllocator<PrmiVec3fImpl> vec3fAlloc;
	SingleIdAllocator<PrmiVec4fImpl> vec4fAlloc;
	
	bool prmiWithinRange(Primitive* prmi, std::uint32_t lower, std::uint32_t upper);

public:
	RenderAllocator();
	~RenderAllocator();

	RenderGeomImpl* allocRenderGeom();
	RenderVertexImpl* allocRenderVertex();
	RenderUniformImpl* allocRenderUniform();
	
	PrmiVec1fImpl* allocPrmiVec1f();
	PrmiVec2fImpl* allocPrmiVec2f();
	PrmiVec3fImpl* allocPrmiVec3f();
	PrmiVec4fImpl* allocPrmiVec4f();

	void releaseRenderGeom(RenderGeom* geom);
	void releaseRenderVertex(RenderVertex* vertex);
	void releaseRenderUniform(RenderUniform* uniform);

	void releasePrimitive(Primitive* prmi);

	RenderGeomImpl* lookupGeom(RenderGeom* geom) const;
	RenderUniformImpl* lookupUniform(RenderUniform* uniform) const;
};

}

#endif