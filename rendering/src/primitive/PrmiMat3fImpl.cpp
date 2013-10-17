#include "PrmiMat3fImpl.h"


using namespace cph;

PrmiMat3fImpl::PrmiMat3fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), matrix()
{

}

PrmiMat3fImpl::~PrmiMat3fImpl() {

}

std::uint32_t PrmiMat3fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

const char* PrmiMat3fImpl::getName() const {
	return PrimitiveImpl::getName();
}

void PrmiMat3fImpl::setName(const char* name) {
	PrimitiveImpl::setName(name);
}

void PrmiMat3fImpl::uploadAsUniformGL(GLuint program) {
	GLfloat rawMatrix[9] = { 0 };
	matrix.toArray(rawMatrix);
	glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, rawMatrix);
}

void PrmiMat3fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {

}

Mat3f* PrmiMat3fImpl::get() {
	return &matrix;
}