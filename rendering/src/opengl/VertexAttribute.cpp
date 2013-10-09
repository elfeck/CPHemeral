#include "VertexAttribute.h"


using namespace cph;

VertexAttribute::VertexAttribute(AttributeFormat format, GLsizei stride, GLint offset, GLboolean normalized) :
	format(format), normalized(normalized), stride(stride), offset(offset)
{

}

VertexAttribute::~VertexAttribute() {

}

void VertexAttribute::bindVertexPointerGL() {
	glEnableVertexAttribArray(format.getIndex());
	glVertexAttribPointer(format.getIndex(), format.getSize(), format.getType(), normalized, stride, reinterpret_cast<GLvoid*>(offset));
}

void VertexAttribute::bindAttribLociationGL(GLuint programHandle) {
	glBindAttribLocation(programHandle, format.getIndex(), format.getName().c_str());
}

GLuint VertexAttribute::getIndex() const {
	return format.getIndex();
}

GLint VertexAttribute::getSize() const {
	return format.getSize();
}

int VertexAttribute::getByteSize() const {
	return format.getByteSize();
}

void VertexAttribute::setStride(GLsizei stride) {
	this->stride = stride;
}

void VertexAttribute::setOffset(GLint offset) {
	this->offset = offset;
}

bool VertexAttribute::operator<(const VertexAttribute& other) const {
	return format < other.format;
}