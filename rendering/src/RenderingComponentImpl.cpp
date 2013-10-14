#include <algorithm>

#include "RenderingSystemImpl.h"
#include "RenderingComponentImpl.h"
#include "primitive/PrmiVec4fImpl.h"


using namespace cph;

RenderingComponentImpl::RenderingComponentImpl(std::uint32_t id) :
	sysId(0), uniqueId(id), geoms(), uniforms(), system(0), vaoEntry()
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

RenderGeom* RenderingComponentImpl::createGeom() {
	return system->getRenderAllocator().allocRenderGeom();
}

RenderVertex* RenderingComponentImpl::createVertex() {
	return system->getRenderAllocator().allocRenderVertex();
}

RenderUniform* RenderingComponentImpl::createUniform() {
	return system->getRenderAllocator().allocRenderUniform();
}

void RenderingComponentImpl::destroyPrimitive(Primitive* prmi) {
	// All geoms and vertices should check for that prmi
	system->getRenderAllocator().releasePrimitive(prmi);
}

void RenderingComponentImpl::destroyGeom(RenderGeom* geom) {
	geoms.erase(geom->getUniqueId());
	system->getRenderAllocator().releaseRenderGeom(geom);
}

void RenderingComponentImpl::destroyVertex(RenderVertex* vertex) {
	// All geoms should check for that vertex
	system->getRenderAllocator().releaseRenderVertex(vertex);
}

void RenderingComponentImpl::destroyUniform(RenderUniform* uniform) {
	uniforms.erase(uniform->getUniqueId());
	system->getRenderAllocator().releaseRenderUniform(uniform);
}

void RenderingComponentImpl::destroyAllGeomsRecursively() {
	for(std::map<std::uint32_t, RenderGeomImpl*>::iterator it = geoms.begin(); it != geoms.end(); ++it) {
		it->second->destroyAllVerticesRecursively(this);
		system->getRenderAllocator().releaseRenderGeom(it->second);
	}
	geoms.clear();
}

void RenderingComponentImpl::addGeom(RenderGeom* geom) {
	geoms.insert(std::make_pair(geom->getUniqueId(), system->getRenderAllocator().lookupGeom(geom)));
}

void RenderingComponentImpl::addUniform(RenderUniform* uniform) {
	uniforms.insert(std::make_pair(uniform->getUniqueId(), system->getRenderAllocator().lookupUniform(uniform)));
}

void RenderingComponentImpl::removeGeom(RenderGeom* geom) {
	geoms.erase(geom->getUniqueId());
}

void RenderingComponentImpl::removeUniform(RenderUniform* uniform) {
	uniforms.erase(uniform->getUniqueId());
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