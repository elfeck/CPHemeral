#include <algorithm>

#include "VaoEntry.h"


using namespace cph;

VaoEntry::VaoEntry() :
	vertices(), uniforms(), viewportRect(-1, -1, -1, -1), scissorRect(-1, -1, -1, -1),
	shaderPath(""), visible(false), added(false)
{

}

VaoEntry::~VaoEntry() {

}

void VaoEntry::addVertex(VertexImpl* vertex) {
	vertices.push_back(vertex);
}

void VaoEntry::removeVertex(VertexImpl* vertex) {
	vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex), vertices.end());
}

void VaoEntry::addUniform(UniformImpl* uniform) {
	uniforms.push_back(uniform);
}

void VaoEntry::removeUniform(UniformImpl* uniform) {
	uniforms.erase(std::remove(uniforms.begin(), uniforms.end(), uniform), uniforms.end());
}

std::string VaoEntry::getShaderPath() {
	return shaderPath;
}

bool VaoEntry::isAdded() {
	return added;
}

void VaoEntry::setViewportRect(int x, int y, int width, int height) {
	viewportRect.setRect(static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
}

void VaoEntry::setScissorRect(int x, int y, int width, int height) {
	scissorRect.setRect(static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height));
}

void VaoEntry::setShader(std::string path) {
	this->shaderPath = path;
}

void VaoEntry::setVisible(bool visible) {
	this->visible = visible;
}

void VaoEntry::viewportGL() {
	// glViewport(static_cast<GLint>(viewportRect.getX()), static_cast<GLint>(viewportRect.getY()), 
	//	static_cast<GLsizei>(viewportRect.getWidth()), static_cast<GLsizei>(viewportRect.getHeight()));
}

void VaoEntry::scissorGL() {
	// glScissor(static_cast<GLint>(scissorRect.getX()), static_cast<GLint>(scissorRect.getY()), 
	//	static_cast<GLsizei>(scissorRect.getWidth()), static_cast<GLsizei>(scissorRect.getHeight()));

}

void VaoEntry::uploadUniformsGL(GLuint programHandle) {
	for(std::vector<Uniform*>::size_type i = 0; i < uniforms.size(); i++) {
		uniforms.at(i)->uploadGL(programHandle);
	}
}
