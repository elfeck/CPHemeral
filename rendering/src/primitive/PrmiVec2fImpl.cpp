#include "PrmiVec2fImpl.h"


using namespace cph;

PrmiVec2fImpl::PrmiVec2fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), vector()
{

}

PrmiVec2fImpl::~PrmiVec2fImpl() {

}

std::uint32_t PrmiVec2fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

void PrmiVec2fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	glUniform2f(glGetUniformLocation(program, name.c_str()), vector.getX(), vector.getY());
}

void PrmiVec2fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {
	buffer.push_back(vector.getX());
	buffer.push_back(vector.getY());
}

Vec2f* PrmiVec2fImpl::get() {
	return &vector;
}