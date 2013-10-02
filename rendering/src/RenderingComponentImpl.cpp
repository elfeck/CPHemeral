#include <algorithm>

#include "RenderingSystemImpl.h"
#include "RenderingComponentImpl.h"


using namespace cph;

RenderingComponentImpl::RenderingComponentImpl() :
	name("rendering"), system(0), vertices(), uniforms()
{

}

RenderingComponentImpl::~RenderingComponentImpl() {
	for(std::vector<VertexImpl*>::size_type i = 0; i != vertices.size(); i++) {
		vertices.at(i)->destroy();
	}
	for(std::vector<UniformImpl*>::size_type i = 0; i != uniforms.size(); i++) {
		uniforms.at(i)->destroy();
	}
}

Vertex* RenderingComponentImpl::addVertex() {
	VertexImpl* vertex = system->allocVertex();
	vertex->setComponent(this);
	vertices.push_back(vertex);
	return vertex;
}

Uniform* RenderingComponentImpl::addUniform() {
	UniformImpl* uniform = system->allocUniform();
	uniform->setComponent(this);
	uniforms.push_back(uniform);
	return uniform;
}

void RenderingComponentImpl::setShader(const char* path) {

}

void RenderingComponentImpl::setViewport(int x, int y, int width, int height) {

}

void RenderingComponentImpl::setScissor(int x, int y, int width, int height) {

}

const char* RenderingComponentImpl::getName() const {
	return name.c_str();
}

void RenderingComponentImpl::destroy() {
	system->releaseComponent(this);
}

void RenderingComponentImpl::removeVertex(VertexImpl* vertex) {
	vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex), vertices.end());
	system->releaseVertex(vertex);
}

void RenderingComponentImpl::removeUniform(UniformImpl* uniform) {
	uniforms.erase(std::remove(uniforms.begin(), uniforms.end(), uniform), uniforms.end());
	system->releaseUniform(uniform);
}

void RenderingComponentImpl::setSystem(RenderingSystemImpl* system) {
	this->system = system;
}