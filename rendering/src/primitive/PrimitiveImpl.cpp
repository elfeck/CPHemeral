#include <iostream>
#include "PrimitiveImpl.h"


using namespace cph;

PrimitiveImpl::PrimitiveImpl(std::uint32_t uniqueId) :
	name(""), uniqueId(uniqueId)
{

}


PrimitiveImpl::~PrimitiveImpl() {

}

std::uint32_t PrimitiveImpl::getUniqueId() const {
	return uniqueId;
}

const char* PrimitiveImpl::getName() const {
	return name.c_str();
}

void PrimitiveImpl::setName(const char* name) {
	this->name = name;
}
