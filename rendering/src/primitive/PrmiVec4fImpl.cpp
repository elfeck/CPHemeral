#include "PrmiVec4fImpl.h"


using namespace cph;

PrmiVec4fImpl::PrmiVec4fImpl(std::uint32_t prmiId) :
	PrimitiveImpl(prmiId), vector()
{

}

PrmiVec4fImpl::~PrmiVec4fImpl() {

}

std::uint64_t PrmiVec4fImpl::getParentId() const {
	return PrimitiveImpl::getParentId();
}

std::uint32_t PrmiVec4fImpl::getPrmiId() const {
	return PrimitiveImpl::getPrmiId();
}

const char* PrmiVec4fImpl::getName() const {
	return PrimitiveImpl::getName();
}

void PrmiVec4fImpl::uploadAsUniformGL(GLuint program) {
	PrimitiveImpl::checkAsUniformGL(program);
	glUniform4f((parentId >> 48) & 0xffff, vector.getX(), vector.getY(), vector.getZ(), vector.getW());
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

