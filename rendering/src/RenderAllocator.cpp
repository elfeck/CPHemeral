#include "RenderAllocator.h"


using namespace cph;

RenderAllocator::RenderAllocator() :
	prmiAlloc(), geomAlloc(), vertexAlloc(), uniformAlloc()
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
	vertex->setPrmiAllocPtr(&prmiAlloc);
	return vertex;
}

RenderUniformImpl* RenderAllocator::allocRenderUniform() {
	RenderUniformImpl* uniform = uniformAlloc.allocate();
	uniform->setPrmiAllocPtr(&prmiAlloc);
	return uniform;
}

void RenderAllocator::releaseRenderVertex(RenderVertex* vertex) {
	vertexAlloc.release(vertex->getUniqueId());
}

void RenderAllocator::releaseRenderUniform(RenderUniform* uniform) {
	uniformAlloc.release(uniform->getUniqueId());
}

void RenderAllocator::releaseRenderGeom(RenderGeom* geom) {
	geomAlloc.release(geom->getUniqueId());
}