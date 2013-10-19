#include <algorithm>

#include "VaoEntry.h"


using namespace cph;

VaoEntry::VaoEntry() :
	vertices(), uniforms(), geoms(), viewportRect(-1, -1, -1, -1), scissorRect(-1, -1, -1, -1),
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

void VaoEntry::fetchVertexData(std::vector<GLfloat>& buffer) const {
	
}

void VaoEntry::fetchIndexData(std::vector<GLushort>& buffer, unsigned int* offset) const {
	for(std::map<std::uint32_t, RenderGeomImpl*>::const_iterator it = geoms.begin(); it != geoms.end(); ++it) {
		it->second->fetchIndexData(buffer, *offset);
	}
}

void VaoEntry::addVertex(RenderVertexImpl* vertex) {
	vertices.insert(std::make_pair(vertex->getUniqueId(), vertex));
}

void VaoEntry::addUniform(RenderUniformImpl* uniform) {
	uniforms.insert(std::make_pair(uniform->getUniqueId(), uniform));
}

void VaoEntry::addGeom(RenderGeomImpl* geom) {
	geoms.insert(std::make_pair(geom->getUniqueId(), geom));
}

void VaoEntry::removeVertex(std::uint32_t uniqueId) {
	// set all vertexIndices above this vertex down
	vertices.erase(uniqueId);
}

void VaoEntry::removeUniform(std::uint32_t uniqueId) {
	uniforms.erase(uniqueId);
}

void VaoEntry::removeGeom(std::uint32_t uniqueId) {
	// remove all vertices in this geom
	geoms.erase(uniqueId);
}

