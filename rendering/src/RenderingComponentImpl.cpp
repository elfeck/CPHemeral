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
	return vaoEntry.addGeom();
}

RenderVertex* RenderingComponentImpl::addVertex() {
	return vaoEntry.addVertex();
}

RenderUniform* RenderingComponentImpl::addUniform() {
	return vaoEntry.addUniform();
}

void RenderingComponentImpl::removeGeom(RenderGeom* geom) {
	vaoEntry.removeGeom(geom);
}

void RenderingComponentImpl::removeVertex(RenderVertex* vertex) {
	vaoEntry.removeVertex(vertex);
}

void RenderingComponentImpl::removeUniform(RenderUniform* uniform) {
	vaoEntry.removeUniform(uniform);
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