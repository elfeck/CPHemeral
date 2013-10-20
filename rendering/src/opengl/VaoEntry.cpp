#include <algorithm>

#include "VaoEntry.h"


using namespace cph;

VaoEntry::VaoEntry() :
	vertices(), uniforms(), geoms(), viewportRect(-1, -1, -1, -1), scissorRect(-1, -1, -1, -1),
	shaderPath(""), visible(false), added(false)
{

}

VaoEntry::~VaoEntry() {
	for(std::map<std::uint32_t, RenderGeomImpl*>::iterator it = geoms.begin(); it != geoms.end(); ++it) {
		allocPtr->releaseRenderGeom(it->second);
	}
	for(std::map<std::uint32_t, RenderVertexImpl*>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		allocPtr->releaseRenderVertex(it->second);
	}
	for(std::map<std::uint32_t, RenderUniformImpl*>::iterator it = uniforms.begin(); it != uniforms.end(); ++it) {
		allocPtr->releaseRenderUniform(it->second);
	}
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

void VaoEntry::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset, const std::set<AttributeFormat>& format) const {
	for(std::map<std::uint32_t, RenderVertexImpl*>::const_iterator it = vertices.begin(); it != vertices.end(); ++it) {
		it->second->fetchVertexData(buffer, format);
	}
}

void VaoEntry::fetchIndexData(std::vector<GLushort>& buffer, unsigned int* offset) const {
	for(std::map<std::uint32_t, RenderGeomImpl*>::const_iterator it = geoms.begin(); it != geoms.end(); ++it) {
		it->second->fetchIndexData(buffer, *offset);
	}
	*offset += vertices.size();
}

RenderGeomImpl* VaoEntry::addLocalGeom() {
	RenderGeomImpl* geom = allocPtr->allocRenderGeom();
	geoms.insert(std::make_pair(geom->getUniqueId(), geom));
	return geom;
}

RenderVertexImpl* VaoEntry::addLocalVertex() {
	RenderVertexImpl* vertex = allocPtr->allocRenderVertex();
	vertex->setVertexIndex(vertices.size());
	vertices.insert(std::make_pair(vertex->getUniqueId(), vertex));
	return vertex;
}

RenderUniformImpl* VaoEntry::addLocalUniform() {
	RenderUniformImpl* uniform = allocPtr->allocRenderUniform();
	uniforms.insert(std::make_pair(uniform->getUniqueId(), uniform));
	return uniform;
}

void VaoEntry::removeLocalGeom(RenderGeom* geom) {
	geoms.erase(geom->getUniqueId());
	allocPtr->releaseRenderGeom(geom);
}

void VaoEntry::removeLocalVertex(RenderVertex* vertex) {
	vertices.erase(vertex->getUniqueId());
	allocPtr->releaseRenderVertex(vertex);
}

void VaoEntry::removeLocalUniform(RenderUniform* uniform) {
	uniforms.erase(uniform->getUniqueId());
	allocPtr->releaseRenderUniform(uniform);
}

void VaoEntry::setAllocPtr(RenderAllocator* allocPtr) {
	this->allocPtr = allocPtr;
}
