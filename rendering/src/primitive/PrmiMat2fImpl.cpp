#include "PrmiMat2fImpl.h"


using namespace cph;

PrmiMat2fImpl::PrmiMat2fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), matrix()
{

}

PrmiMat2fImpl::~PrmiMat2fImpl() {

}

std::uint32_t PrmiMat2fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

void PrmiMat2fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	GLfloat rawMatrix[4] = { 0 };
	matrix.toArray(rawMatrix);
	glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, rawMatrix);
}

void PrmiMat2fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {

}

Mat2f* PrmiMat2fImpl::get() {
	return &matrix;
}