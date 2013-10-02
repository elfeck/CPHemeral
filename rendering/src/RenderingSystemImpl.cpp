#include "RenderingSystemImpl.h"


using namespace cph;

RenderingSystemImpl::RenderingSystemImpl() :
	componentAlloc(), vertexAlloc(), uniformAlloc()
{

}

RenderingSystemImpl::~RenderingSystemImpl() {

}

RenderingComponent* RenderingSystemImpl::createComponent() {
	RenderingComponentImpl* comp = componentAlloc.allocate();
	comp->setSystem(this);
	return comp;
}

void RenderingSystemImpl::execute(long delta) {

}

VertexImpl* RenderingSystemImpl::allocVertex() {
	return vertexAlloc.allocate();
}

UniformImpl* RenderingSystemImpl::allocUniform() {
	return uniformAlloc.allocate();
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	componentAlloc.release(component);
}

void RenderingSystemImpl::releaseVertex(VertexImpl* vertex) {
	vertexAlloc.release(vertex);
}

void RenderingSystemImpl::releaseUniform(UniformImpl* uniform) {
	uniformAlloc.release(uniform);
}
