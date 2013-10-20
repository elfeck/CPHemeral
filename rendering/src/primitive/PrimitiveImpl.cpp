#include <iostream>
#include "PrimitiveImpl.h"


using namespace cph;

PrimitiveImpl::PrimitiveImpl(std::uint32_t uniqueId) :
	local(true), name(""), uniqueId(uniqueId)
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

bool PrimitiveImpl::isLocal() {
	return local;
}

void PrimitiveImpl::setLocal(bool local) {
	this->local = local;
}
