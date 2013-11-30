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

RenderGeom* RenderingComponentImpl::addLocalGeom() {
	return vaoEntry.addLocalGeom();
}

RenderVertex* RenderingComponentImpl::addLocalVertex() {
	return vaoEntry.addLocalVertex();
}

RenderUniform* RenderingComponentImpl::addLocalUniform() {
	return vaoEntry.addLocalUniform();
}

void RenderingComponentImpl::removeLocalGeom(RenderGeom* geom) {
	vaoEntry.removeLocalGeom(geom);
}

void RenderingComponentImpl::removeLocalVertex(RenderVertex* vertex) {
	vaoEntry.removeLocalVertex(vertex);
}

void RenderingComponentImpl::removeLocalUniform(RenderUniform* uniform) {
	vaoEntry.removeLocalUniform(uniform);
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

void RenderingComponentImpl::setRenderMode(RenderMode mode) {
	switch(mode) {
	case POINTS: vaoEntry.setMode(GL_POINTS); break;
	case LINES: vaoEntry.setMode(GL_LINES); break;
	case TRIANGLES: vaoEntry.setMode(GL_TRIANGLES); break;
	}
}

void RenderingComponentImpl::setVisible(bool visible) {
	vaoEntry.setVisible(visible);
}

bool RenderingComponentImpl::isVisible() const {
	return vaoEntry.isVisible();
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
	this->sysId = system->getSysId();
	vaoEntry.setAllocPtr(system->getRenderAllocator());
}

VaoEntry* RenderingComponentImpl::getVaoEntry() {
	return &vaoEntry;
}