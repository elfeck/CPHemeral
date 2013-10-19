#include "PrmiVec3fImpl.h"


using namespace cph;

PrmiVec3fImpl::PrmiVec3fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), vector()
{

}

PrmiVec3fImpl::~PrmiVec3fImpl() {

}

std::uint32_t PrmiVec3fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

void PrmiVec3fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	glUniform3f(glGetUniformLocation(program, name.c_str()), vector.getX(), vector.getY(), vector.getZ());
}

void PrmiVec3fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {
	buffer.push_back(vector.getX());
	buffer.push_back(vector.getY());
	buffer.push_back(vector.getZ());
}

Vec3f* PrmiVec3fImpl::get() {
	return &vector;
}