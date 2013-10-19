#include "PrmiVec1fImpl.h"


using namespace cph;

PrmiVec1fImpl::PrmiVec1fImpl(std::uint32_t uniqueId) :
	PrimitiveImpl(uniqueId), vector()
{

}

PrmiVec1fImpl::~PrmiVec1fImpl() {

}

std::uint32_t PrmiVec1fImpl::getUniqueId() const {
	return PrimitiveImpl::getUniqueId();
}

void PrmiVec1fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	glUniform1f(glGetUniformLocation(program, name.c_str()), vector.getX());
}

void PrmiVec1fImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {
	buffer.push_back(vector.getX());
}

Vec1f* PrmiVec1fImpl::get() {
	return &vector;
}