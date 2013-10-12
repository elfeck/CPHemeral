#include <iostream>
#include "PrimitiveImpl.h"


using namespace cph;

PrimitiveImpl::PrimitiveImpl(std::uint32_t prmiId) :
	name(""), parentId(0), prmiId(prmiId)
{

}


PrimitiveImpl::~PrimitiveImpl() {

}

std::uint64_t PrimitiveImpl::getParentId() const {
	return parentId;
}

std::uint32_t PrimitiveImpl::getPrmiId() const {
	return prmiId;
}

const char* PrimitiveImpl::getName() const {
	return name.c_str();
}

void PrimitiveImpl::checkAsUniformGL(GLuint program) {
	GLint location = (parentId >> 48) & 0xffff;
	if(location == 0) {
		location = glGetUniformLocation(program, name.c_str());
		if(location >= 0 && location <= 0xffff) {
			parentId = parentId & ((0xffffffffffffffff & location) << 48);
		} else {
			std::cout << "Invalid uniform: " << name << " | " << location << std::endl;
		}
	}
}
