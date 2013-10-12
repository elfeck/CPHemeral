#include <algorithm>

#include "VaoEntry.h"


using namespace cph;

VaoEntry::VaoEntry() :
	viewportRect(-1, -1, -1, -1), scissorRect(-1, -1, -1, -1),
	shaderPath(""), visible(false), added(false)
{

}

VaoEntry::~VaoEntry() {

}

std::string VaoEntry::getShaderPath() const {
	return shaderPath;
}

GLenum VaoEntry::getMode() const {
	return mode;
}

bool VaoEntry::isAdded() const {
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

void VaoEntry::setMode(GLenum mode) {
	this->mode = mode;
}

void VaoEntry::setVisible(bool visible) {
	this->visible = visible;
}

void VaoEntry::setAdded(bool added) {
	this->added = added;
}

void VaoEntry::viewportGL() const {
	glViewport(static_cast<GLint>(viewportRect.getX()), static_cast<GLint>(viewportRect.getY()), 
		static_cast<GLsizei>(viewportRect.getWidth()), static_cast<GLsizei>(viewportRect.getHeight()));
}

void VaoEntry::scissorGL() const {
	glScissor(static_cast<GLint>(scissorRect.getX()), static_cast<GLint>(scissorRect.getY()), 
		static_cast<GLsizei>(scissorRect.getWidth()), static_cast<GLsizei>(scissorRect.getHeight()));
}

void VaoEntry::uploadUniformsGL(GLuint programHandle) const  {

}
