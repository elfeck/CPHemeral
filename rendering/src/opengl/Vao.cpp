#include <algorithm>

#include "Vao.h"


using namespace cph;

Vao::Vao() :
	vaoHandle(0), vboHandle(0), iboHandle(0),
	usage(GL_STATIC_DRAW), modified(false), entries(), shaderPrograms(), bufferFormat()
{

}

Vao::~Vao() {

}

void Vao::addVaoEntry(VaoEntry* entry, ShaderProgram* program) {
	if(hasShader(entry->getShaderPath())) {
		entries.push_back(entry);
	} else if(program != 0) {
		if(entry->getShaderPath() == program->getShaderId() && supportsShader(*program)) {
			shaderPrograms.insert(std::make_pair(program->getShaderId(), *program));
			entries.push_back(entry);
		}
	} else {
		shaderPrograms.insert(std::make_pair(entry->getShaderPath(), ShaderProgram(entry->getShaderPath())));
		entries.push_back(entry);
	}
	entry->setAdded(true);
	modified = true;
}

void Vao::removeVaoEntry(VaoEntry* entry) {
	entries.erase(std::remove(entries.begin(), entries.end(), entry), entries.end());
	modified = true;
}

bool Vao::hasShader(std::string shaderId) const {
	return shaderPrograms.count(shaderId) == 1;
}

bool Vao::supportsShader(ShaderProgram& shader) const {
	return bufferFormat.isCompatible(shader.getAttritbuteFormat());
}

void Vao::setUsage(GLenum usage) {
	this->usage = usage;
}

void Vao::initGL(ShaderProgram initialProgram) {
	shaderPrograms.insert(std::make_pair(initialProgram.getShaderId(), initialProgram));
	for(std::set<AttributeFormat>::iterator it = initialProgram.getAttritbuteFormat().begin();
		it != initialProgram.getAttritbuteFormat().end(); ++it) {
		bufferFormat.addVertexAttribute(VertexAttribute(*it));
	}
	if(vaoHandle == 0) {
		glGenVertexArrays(1, &vaoHandle);
		glGenBuffers(1, &vboHandle);
		glGenBuffers(1, &iboHandle);
	}
	glBindVertexArray(vaoHandle);
	bindVboGL();
	bindIboGL();
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vao::bindVboGL() {
	glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
	bufferFormat.bindVertexAttributesGL();
}

void Vao::bindIboGL() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboHandle);
}

bool Vao::entryModifiedVert() {
	for(std::vector<VaoEntry*>::iterator it = entries.begin(); it != entries.end(); ++it) {
		if((*it)->wasVertModified()) return true;
	}
	return false;
}

bool Vao::entryModifiedGeom() {
	for(std::vector<VaoEntry*>::iterator it = entries.begin(); it != entries.end(); ++it) {
		if((*it)->wasGeomModified()) return true;
	}
	return false;
}

void Vao::uploadVboGL() {
	std::vector<GLfloat> vertexBuffer;
	unsigned int vertexOffset = 0;
	for(std::vector<VaoEntry*>::iterator it = entries.begin(); it != entries.end(); ++it) {
		(*it)->fetchVertexData(vertexBuffer, &vertexOffset, shaderPrograms.at((*it)->getShaderPath()).getAttritbuteFormat());
	}
	glBindBuffer(GL_ARRAY_BUFFER, vboHandle);
	glBufferData(GL_ARRAY_BUFFER, vertexBuffer.size() * sizeof(GLfloat), &vertexBuffer.at(0), usage);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Vao::uploadIboGL() {
	std::vector<GLushort> indexBuffer;
	unsigned int indexOffset = 0;
	for(std::vector<VaoEntry*>::iterator it = entries.begin(); it != entries.end(); ++it) {
		(*it)->fetchIndexData(indexBuffer, &indexOffset);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboHandle);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.size() * sizeof(GLushort), &indexBuffer.at(0), usage);
}

void Vao::drawGL() {
	glBindVertexArray(vaoHandle);
	VaoEntry* entry = 0;
	for(std::vector<VaoEntry*>::iterator it = entries.begin(); it != entries.end(); ++it) {
		entry = *it;
		if(!entry->isVisible()) continue;
		entry->viewportGL();
		entry->scissorGL();
		shaderPrograms.at(entry->getShaderPath()).bindGL();
		entry->uploadUniformsGL(shaderPrograms.at(entry->getShaderPath()).getProgramHandle());
		glDrawElements(entry->getMode(), entry->getIndexCount(), GL_UNSIGNED_SHORT, 
			reinterpret_cast<GLvoid*>(entry->getIndexOffset() * sizeof(GLushort)));
		shaderPrograms.at(entry->getShaderPath()).unbindGL();
	}
	glBindVertexArray(0);
}

void Vao::updateGL() {
	if(modified || entryModifiedVert()) {
		uploadVboGL();
	} else {

	}

	if(modified || entryModifiedGeom()) {
		uploadIboGL();
	} else {

	}

	modified = true;
}