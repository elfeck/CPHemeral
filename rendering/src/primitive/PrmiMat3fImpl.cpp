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

bool PrmiMat3fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiMat3fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified || !isLocal()) {
		GLfloat rawMatrix[9] = { 0 };
		matrix.toArray(rawMatrix);
		glUniformMatrix3fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, rawMatrix);
		modified = false;
	}
}

void PrmiMat3fImpl::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset) {
	modified = false;
}

Mat3f* PrmiMat3fImpl::wget() {
	modified = true;
	return &matrix;
}

const Mat3f* PrmiMat3fImpl::rget() const {
	return &matrix;
}
