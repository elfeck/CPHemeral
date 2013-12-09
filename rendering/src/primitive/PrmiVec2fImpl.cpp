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

bool PrmiVec2fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiVec2fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified || !isLocal()) {
		glUniform2f(glGetUniformLocation(program, name.c_str()), vector.getX(), vector.getY());
		modified = false;
	}
}

void PrmiVec2fImpl::fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset) {
	*offset += vector.getDim();
	buffer.push_back(vector.getX());
	buffer.push_back(vector.getY());
	modified = false;
}

Vec2f* PrmiVec2fImpl::wget() {
	modified = true;
	return &vector;
}

const Vec2f* PrmiVec2fImpl::rget() const {
	return &vector;
}
