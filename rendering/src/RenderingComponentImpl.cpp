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
	// delete this prmi from all vertices before deleting it
	system->getRenderAllocator().releasePrimitive(prmi);
}

void RenderingComponentImpl::destroyGeom(RenderGeom* geom) {
	system->getRenderAllocator().releaseRenderGeom(geom);
}

void RenderingComponentImpl::destroyVertex(RenderVertex* vertex) {
	// delete this vertex from all geoms before deleting it
	system->getRenderAllocator().releaseRenderVertex(vertex);
}

void RenderingComponentImpl::destroyUniform(RenderUniform* uniform) {
	system->getRenderAllocator().releaseRenderUniform(uniform);
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