#include <algorithm>

#include "VaoEntry.h"


using namespace cph;

const std::string VaoEntry::ERROR_PATH = "error_path";

VaoEntry::VaoEntry() :
	vertices(), uniforms(), geoms(), viewportRect(-1, -1, -1, -1), scissorRect(-1, -1, -1, -1),
	shaderPath(""), mode(GL_TRIANGLES), visible(false), added(false), vertModified(false), geomModified(false),
	indexOffset(0), indexCount(0), indexBufferOffset(0), vertexBufferOffset(0), allocPtr(0)
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

bool VaoEntry::isVisible() const {
	return visible;
}

bool VaoEntry::isAdded() const {
	return added;
}

bool VaoEntry::wasVertModified() const {
	return vertModified;
}

bool VaoEntry::wasGeomModified() const {
	return geomModified;
}

bool VaoEntry::nextNeedsViewportChange(VaoEntry& next) const {
	return viewportRect != next.viewportRect;
}

bool VaoEntry::nextNeedsScissorChange(VaoEntry& next) const {
	return scissorRect != next.scissorRect;
}

bool VaoEntry::nextNeedsShaderChange(VaoEntry& next) const {
	return shaderPath != next.shaderPath;
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
	for(std::map<std::uint32_t, RenderUniformImpl*>::const_iterator it = uniforms.begin(); it != uniforms.end(); ++it) {
		it->second->uploadUniformGL(programHandle);
	}
}

unsigned int VaoEntry::getIndexOffset() const {
	return indexOffset;
}

unsigned int VaoEntry::getIndexCount() const {
	return indexCount;
}

unsigned int VaoEntry::getIndexBufferOffset() const {
	return indexBufferOffset;
}

void VaoEntry::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset, const std::set<AttributeFormat>& format) {
	vertexBufferOffset = *offset;
	for(std::map<std::uint32_t, RenderVertexImpl*>::const_iterator it = vertices.begin(); it != vertices.end(); ++it) {
		it->second->fetchVertexData(buffer, format, offset);
	}
	vertModified = false;
}

void VaoEntry::fetchIndexData(std::vector<GLushort>& buffer, unsigned int* indexOffs, unsigned int* indexBufferOffs) {
	indexOffset = *indexOffs;
	indexBufferOffset = *indexBufferOffs;
	indexCount = 0;
	for(std::map<std::uint32_t, RenderGeomImpl*>::const_iterator it = geoms.begin(); it != geoms.end(); ++it) {
		it->second->fetchIndexData(buffer, *indexOffs);
		indexCount += it->second->getVertexCount();
	}
	*indexOffs += vertices.size();
	*indexBufferOffs += indexCount;
	geomModified = false;
}

RenderGeomImpl* VaoEntry::addGeom() {
	RenderGeomImpl* geom = allocPtr->allocRenderGeom();
	geoms.insert(std::make_pair(geom->getUniqueId(), geom));
	geomModified = true;
	return geom;
}

RenderVertexImpl* VaoEntry::addVertex() {
	RenderVertexImpl* vertex = allocPtr->allocRenderVertex();
	vertex->setVertexIndex(vertices.size());
	vertices.insert(std::make_pair(vertex->getUniqueId(), vertex));
	vertModified = true;
	return vertex;
}

RenderUniformImpl* VaoEntry::addUniform() {
	RenderUniformImpl* uniform = allocPtr->allocRenderUniform();
	uniforms.insert(std::make_pair(uniform->getUniqueId(), uniform));
	return uniform;
}

void VaoEntry::removeGeom(RenderGeom* geom) {
	geoms.erase(geom->getUniqueId());
	allocPtr->releaseRenderGeom(geom);
	geomModified = true;
}

void VaoEntry::removeVertex(RenderVertex* vertex) {
	vertices.erase(vertex->getUniqueId());
	allocPtr->releaseRenderVertex(vertex);
	vertModified = true;
}

void VaoEntry::removeUniform(RenderUniform* uniform) {
	uniforms.erase(uniform->getUniqueId());
	allocPtr->releaseRenderUniform(uniform);
}

void VaoEntry::setAllocPtr(RenderAllocator* allocPtr) {
	this->allocPtr = allocPtr;
}
