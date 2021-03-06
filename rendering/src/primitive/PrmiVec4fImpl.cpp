#include "PrmiVec4fImpl.h"


using namespace cph;

PrmiVec4fImpl::PrmiVec4fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), vector()
{

}

PrmiVec4fImpl::~PrmiVec4fImpl() {

}

std::uint32_t PrmiVec4fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

bool PrmiVec4fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiVec4fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified || !isLocal()) {
		GLuint uniformLocation = glGetUniformLocation(program, name.c_str());
		glUniform4f(uniformLocation, vector.getX(), vector.getY(), vector.getZ(), vector.getW());
		modified = false;
	}
}

void PrmiVec4fImpl::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset) {
	*offset += vector.getDim();
	buffer.push_back(vector.getX());
	buffer.push_back(vector.getY());
	buffer.push_back(vector.getZ());
	buffer.push_back(vector.getW());
	modified = false;
}

Vec4f* PrmiVec4fImpl::wget() {
	modified = true;
	return &vector;
}

const Vec4f* PrmiVec4fImpl::rget() const {
	return &vector;
}
