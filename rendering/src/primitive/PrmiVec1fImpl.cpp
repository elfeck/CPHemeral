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

bool PrmiVec1fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiVec1fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified ||!isLocal()) {
		glUniform1f(glGetUniformLocation(program, name.c_str()), vector.getX());
		modified = false;
	}
}

void PrmiVec1fImpl::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset) {
	*offset += vector.getDim();
	buffer.push_back(vector.getX());
	modified = false;
}

Vec1f* PrmiVec1fImpl::wget() {
	modified = true;
	return &vector;
}

const Vec1f* PrmiVec1fImpl::rget() const {
	return &vector;
}

