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

bool PrmiMat4fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiMat4fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified ||!isLocal()) {
		GLfloat rawMatrix[16] = { 0 };
		matrix.toArray(rawMatrix);
		glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, rawMatrix);
		modified = false;
	}
}

void PrmiMat4fImpl::fetchVertexData(std::vector<GLfloat>& buffer) {
	modified = false;
}

Mat4f* PrmiMat4fImpl::wget() {
	modified = true;
	return &matrix;
}

const Mat4f* PrmiMat4fImpl::rget() const {
	return &matrix;
}
