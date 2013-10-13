#include "RenderAllocator.h"


using namespace cph;

RenderAllocator::RenderAllocator() :
	primitiveLookup(), vertexAlloc(), uniformAlloc(),
	//vec1fAlloc(1, 0x20000000),
	//(0x20000000, 0x40000000),
	//vec3fAlloc(0x40000000, 0x60000000),
	vec4fAlloc(0x60000000, 0x80000000)
	//mat2fAlloc(0x80000000, 0xa0000000),
	//mat3fAlloc(0xa0000000, 0xc0000000),
	//mat4fAlloc(0xc0000000, 0xe0000000),
{

}

RenderAllocator::~RenderAllocator() {

}

RenderGeomImpl* RenderAllocator::allocRenderGeom() {
	RenderGeomImpl* geom = geomAlloc.allocate();
	geom->setVertexLookupPtr(&vertexAlloc);
	return geom;
}

RenderVertexImpl* RenderAllocator::allocRenderVertex() {
	RenderVertexImpl* vertex = vertexAlloc.allocate();
	vertex->setPrmiLookupPtr(&primitiveLookup);
	return vertex;
}

RenderUniformImpl* RenderAllocator::allocRenderUniform() {
	RenderUniformImpl* uniform = uniformAlloc.allocate();
	uniform->setPrmiLookupPtr(&primitiveLookup);
	return uniform;
}

PrmiVec4fImpl* RenderAllocator::allocPrmiVec4f() {
	PrmiVec4fImpl* vec = vec4fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

void RenderAllocator::releaseRenderVertex(RenderVertex* vertex) {
	vertexAlloc.release(vertex->getUniqueId());
}

void RenderAllocator::releaseRenderUniform(RenderUniform* uniform) {
	vertexAlloc.release(uniform->getUniqueId());
}

void RenderAllocator::releaseRenderGeom(RenderGeom* geom) {
	geomAlloc.release(geom->getUniqueId());
}

void RenderAllocator::releasePrimitive(Primitive* prmi) {

}
