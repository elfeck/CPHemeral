#include "RenderAllocator.h"


using namespace cph;

RenderAllocator::RenderAllocator() :
	primitiveLookup(), vertexAlloc(), uniformAlloc(),
	vec1fAlloc(1, 0x20000000),
	vec2fAlloc(0x20000000, 0x40000000),
	vec3fAlloc(0x40000000, 0x60000000),
	vec4fAlloc(0x60000000, 0x80000000),
	mat2fAlloc(0x80000000, 0xa0000000),
	mat3fAlloc(0xa0000000, 0xc0000000),
	mat4fAlloc(0xc0000000, 0xe0000000)
{

}

RenderAllocator::~RenderAllocator() {

}

bool RenderAllocator::prmiWithinRange(Primitive* prmi, std::uint32_t lower, std::uint32_t upper) {
	return prmi->getUniqueId() >= lower && prmi->getUniqueId() < upper;
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

PrmiVec1fImpl* RenderAllocator::allocPrmiVec1f() {
	PrmiVec1fImpl* vec = vec1fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiVec2fImpl* RenderAllocator::allocPrmiVec2f() {
	PrmiVec2fImpl* vec = vec2fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiVec3fImpl* RenderAllocator::allocPrmiVec3f() {
	PrmiVec3fImpl* vec = vec3fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiVec4fImpl* RenderAllocator::allocPrmiVec4f() {
	PrmiVec4fImpl* vec = vec4fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiMat2fImpl* RenderAllocator::allocPrmiMat2f() {
	PrmiMat2fImpl* mat = mat2fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(mat->getUniqueId(), mat));
	return mat;
}

PrmiMat3fImpl* RenderAllocator::allocPrmiMat3f() {
	PrmiMat3fImpl* mat = mat3fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(mat->getUniqueId(), mat));
	return mat;
}

PrmiMat4fImpl* RenderAllocator::allocPrmiMat4f() {
	PrmiMat4fImpl* mat = mat4fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(mat->getUniqueId(), mat));
	return mat;
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

void RenderAllocator::releasePrimitive(Primitive* prmi) {
	primitiveLookup.erase(prmi->getUniqueId());
	if(prmiWithinRange(prmi, 1, 0x20000000)) vec1fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x20000000, 0x40000000)) vec2fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x40000000, 0x60000000)) vec3fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x60000000, 0x80000000)) vec4fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x80000000, 0xa0000000)) mat2fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0xa0000000, 0xc0000000)) mat3fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0xc0000000, 0xe0000000)) mat4fAlloc.release(prmi->getUniqueId());
}

RenderGeomImpl* RenderAllocator::lookupGeom(RenderGeom* geom) const {
	return geomAlloc.at(geom->getUniqueId());
}

RenderUniformImpl* RenderAllocator::lookupUniform(RenderUniform* uniform) const {
	return uniformAlloc.at(uniform->getUniqueId());
}
