#include "PrmiMat4fImpl.h"


using namespace cph;

PrmiMat4fImpl::PrmiMat4fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), matrix()
{

}

PrmiMat4fImpl::~PrmiMat4fImpl() {

}

std::uint32_t PrmiMat4fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

const char* PrmiMat4fImpl::getName() const {
	return PrimitiveImpl::getName();
}

void PrmiMat4fImpl::setName(const char* name) {
	PrimitiveImpl::setName(name);
}

void PrmiMat4fImpl::uploadAsUniformGL(GLuint program) {
	GLfloat rawMatrix[16] = { 0 };
	matrix.toArray(rawMatrix);
	glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, rawMatrix);
}

void PrmiMat4fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {

}

Mat4f* PrmiMat4fImpl::get() {
	return &matrix;
}