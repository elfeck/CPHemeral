#include <algorithm>

#include "RenderingSystemImpl.h"
#include "RenderingComponentImpl.h"
#include "primitive/PrmiVec4fImpl.h"


using namespace cph;

RenderingComponentImpl::RenderingComponentImpl(std::uint32_t id) :
	sysId(0), uniqueId(id), system(0), vaoEntry()
{

}

RenderingComponentImpl::~RenderingComponentImpl() {

}

PrmiVec1f* RenderingComponentImpl::createVec1f(const char* name, float x) {
	PrmiVec1f* vec = system->getRenderAllocator().allocPrmiVec1f();
	vec->get()->setX(x);
	vec->setName(name);
	return vec;
}

PrmiVec2f* RenderingComponentImpl::createVec2f(const char* name, float x, float y) {
	PrmiVec2f* vec = system->getRenderAllocator().allocPrmiVec2f();
	vec->get()->setXY(x, y);
	vec->setName(name);
	return vec;
}

PrmiVec3f* RenderingComponentImpl::createVec3f(const char* name, float x, float y, float z) {
	PrmiVec3f* vec = system->getRenderAllocator().allocPrmiVec3f();
	vec->get()->setXYZ(x, y, z);
	vec->setName(name);
	return vec;
}

PrmiVec4f* RenderingComponentImpl::createVec4f(const char* name, float x, float y, float z, float w) {
	PrmiVec4f* vec = system->getRenderAllocator().allocPrmiVec4f();
	vec->get()->setXYZW(x, y, z, w);
	vec->setName(name);
	return vec;
}	

PrmiMat2f* RenderingComponentImpl::createMat2f(const char* name) {
	PrmiMat2f* mat = system->getRenderAllocator().allocPrmiMat2f();
	mat->setName(name);
	return mat;
}

PrmiMat3f* RenderingComponentImpl::createMat3f(const char* name) {
	PrmiMat3f* mat = system->getRenderAllocator().allocPrmiMat3f();
	mat->setName(name);
	return mat;
}

PrmiMat4f* RenderingComponentImpl::createMat4f(const char* name) {
	PrmiMat4f* mat = system->getRenderAllocator().allocPrmiMat4f();
	mat->setName(name);
	return mat;
}

RenderGeom* RenderingComponentImpl::createGeom() {
	return system->getRenderAllocator().allocRenderGeom();
}

RenderVertex* RenderingComponentImpl::createVertex() {
	RenderVertexImpl* vertex = system->getRenderAllocator().allocRenderVertex();
	vaoEntry.addVertex(vertex);
	return vertex;
}

RenderUniform* RenderingComponentImpl::createUniform() {
	RenderUniformImpl* uniform = system->getRenderAllocator().allocRenderUniform();
	vaoEntry.addUniform(uniform);
	return uniform;
}

void RenderingComponentImpl::destroyPrimitive(Primitive* prmi) {
	// All geoms and vertices should check for that prmi
	system->getRenderAllocator().releasePrimitive(prmi);
}

void RenderingComponentImpl::destroyVertex(RenderVertex* vertex) {
	// All geoms should check for that vertex
	vaoEntry.removeVertex(vertex->getUniqueId());
	system->getRenderAllocator().releaseRenderVertex(vertex);
}

void RenderingComponentImpl::destroyUniform(RenderUniform* uniform) {
	vaoEntry.removeUniform(uniform->getUniqueId());
	system->getRenderAllocator().releaseRenderUniform(uniform);
}

void RenderingComponentImpl::destroyGeom(RenderGeom* geom) {
	vaoEntry.removeGeom(geom->getUniqueId());
	system->getRenderAllocator().releaseRenderGeom(geom);
}

void RenderingComponentImpl::destroyAllGeomsRecursively() {
	for(std::map<std::uint32_t, RenderGeomImpl*>::iterator it = vaoEntry.getGeoms()->begin(); it != vaoEntry.getGeoms()->end(); ++it) {
		system->getRenderAllocator().releaseRenderGeom(it->second);
	}
	for(std::map<std::uint32_t, RenderVertexImpl*>::iterator it = vaoEntry.getVertices()->begin(); it != vaoEntry.getVertices()->end(); ++it) {
		it->second->destroyAllPrimitivesRecursively(this);
		system->getRenderAllocator().releaseRenderVertex(it->second);
	}
	vaoEntry.clear();
}

void RenderingComponentImpl::setShader(const char* path) {
	vaoEntry.setShader(path);
}

void RenderingComponentImpl::setViewport(int x, int y, int width, int height) {
	vaoEntry.setViewportRect(x, y, width, height);
}

void RenderingComponentImpl::setScissor(int x, int y, int width, int height) {
	vaoEntry.setScissorRect(x, y, width, height);
}

void RenderingComponentImpl::setVisible(bool visible) {
	vaoEntry.setVisible(visible);
}

std::uint8_t RenderingComponentImpl::getSysId() const {
	return sysId;
}

std::uint32_t RenderingComponentImpl::getUniqueId() const {
	return uniqueId;
}

void RenderingComponentImpl::destroy() {
	system->releaseComponent(this);
}

void RenderingComponentImpl::setSystem(RenderingSystemImpl* system) {
	this->system = system;
}

void RenderingComponentImpl::setSysId(std::uint8_t id) {
	sysId = id;
}

VaoEntry* RenderingComponentImpl::getVaoEntry() {
	return &vaoEntry;
}