#include <algorithm>

#include "RenderingSystemImpl.h"
#include "RenderingComponentImpl.h"


using namespace cph;

SingleIdAllocator<VertexImpl> RenderingComponentImpl::vertexAlloc;
SingleIdAllocator<UniformImpl> RenderingComponentImpl::uniformAlloc;

RenderingComponentImpl::RenderingComponentImpl(std::uint32_t id) :
	sysId(0), compId(id), system(0), vaoEntry()
{

}

RenderingComponentImpl::~RenderingComponentImpl() {

}

Vertex* RenderingComponentImpl::addVertex() {
	return vertexAlloc.allocate();
}

Uniform* RenderingComponentImpl::addUniform() {
	return uniformAlloc.allocate();
}

void RenderingComponentImpl::removeVertex(Vertex* vertex) {
	vertexAlloc.release(vertex->getId());
}

void RenderingComponentImpl::removeUniform(Uniform* uniform) {
	uniformAlloc.release(uniform->getId());
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

std::uint32_t RenderingComponentImpl::getCompId() const {
	return compId;
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