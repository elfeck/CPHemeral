#include "RenderingComponentImpl.h"


using namespace cph;

RenderingComponentImpl::RenderingComponentImpl() {

}

RenderingComponentImpl::~RenderingComponentImpl() {

}

Vertex* RenderingComponentImpl::addVertex() {
	return 0;
}

void RenderingComponentImpl::removeVertex(Vertex* vertex) {

}

Uniform* RenderingComponentImpl::addUniform() {
	return 0;
}

void RenderingComponentImpl::removeUniform(Uniform* uniform) {

}

void RenderingComponentImpl::setShader(const char* path) {

}

void RenderingComponentImpl::setViewport(int x, int y, int width, int height) {

}

void RenderingComponentImpl::setScissor(int x, int y, int width, int height) {

}

const char* RenderingComponentImpl::getName() const {
	return 0;
}

void RenderingComponentImpl::release() {

}
