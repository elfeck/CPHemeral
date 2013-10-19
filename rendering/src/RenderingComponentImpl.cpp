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

RenderGeom* RenderingComponentImpl::addGeom() {
	RenderGeomImpl* geom = system->getRenderAllocator().allocRenderGeom();
	vaoEntry.addGeom(geom);
	return geom;
}

RenderVertex* RenderingComponentImpl::addVertex() {
	RenderVertexImpl* vertex = system->getRenderAllocator().allocRenderVertex();
	vaoEntry.addVertex(vertex);
	return vertex;
}

RenderUniform* RenderingComponentImpl::addLocalUniform() {
	RenderUniformImpl* uniform = system->getRenderAllocator().allocRenderUniform();
	vaoEntry.addUniform(uniform);
	return uniform;
}

void RenderingComponentImpl::removeGeom(RenderGeom* geom) {
	vaoEntry.removeGeom(geom->getUniqueId());
	system->getRenderAllocator().releaseRenderGeom(geom);
}

void RenderingComponentImpl::removeVertex(RenderVertex* vertex) {
	vaoEntry.removeVertex(vertex->getUniqueId());
	system->getRenderAllocator().releaseRenderVertex(vertex);
}

void RenderingComponentImpl::removeLocalUniform(RenderUniform* uniform) {
	vaoEntry.removeUniform(uniform->getUniqueId());
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