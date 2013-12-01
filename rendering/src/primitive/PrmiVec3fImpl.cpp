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

bool PrmiVec3fImpl::isLocal() const {
	return PrimitiveImpl::isLocal();
}

void PrmiVec3fImpl::uploadAsUniformGL(GLuint program, std::string name) {
	if(modified || !isLocal()) {
		glUniform3f(glGetUniformLocation(program, name.c_str()), vector.getX(), vector.getY(), vector.getZ());
		modified = false;
	}
}

void PrmiVec3fImpl::fetchVertexData(std::vector<GLfloat>& buffer) {
	buffer.push_back(vector.getX());
	buffer.push_back(vector.getY());
	buffer.push_back(vector.getZ());
	modified = false;
}

Vec3f* PrmiVec3fImpl::wget() {
	modified = true;
	return &vector;
}

const Vec3f* PrmiVec3fImpl::rget() const {
	return &vector;
}
