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

void PrmiVec4fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	glUniform4f(glGetUniformLocation(program, name.c_str()), vector.getX(), vector.getY(), vector.getZ(), vector.getW());
}

void PrmiVec4fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {
	buffer.push_back(vector.getX());
	buffer.push_back(vector.getY());
	buffer.push_back(vector.getZ());
	buffer.push_back(vector.getW());
}

Vec4f* PrmiVec4fImpl::get() {
	return &vector;
}