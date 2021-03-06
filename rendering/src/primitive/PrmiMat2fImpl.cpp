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

bool PrmiMat2fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiMat2fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified || !isLocal()) {
		GLfloat rawMatrix[4] = { 0 };
		matrix.toArray(rawMatrix);
		glUniformMatrix2fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, rawMatrix);
		modified = false;
	}
}

void PrmiMat2fImpl::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset) {
	modified = false;
}

Mat2f* PrmiMat2fImpl::wget() {
	modified = true;
	return &matrix;
}

const Mat2f* PrmiMat2fImpl::rget() const {
	return &matrix;
}
