#include <iostream>
#include "PrimitiveImpl.h"


using namespace cph;

PrimitiveImpl::PrimitiveImpl(std::uint32_t uniqueId) :
	local(true), uniqueId(uniqueId), modified(true)
{

}


PrimitiveImpl::~PrimitiveImpl() {

}

std::uint32_t PrimitiveImpl::getUniqueId() const {
	return uniqueId;
}

bool PrimitiveImpl::isLocal() const {
	return local;
}

void PrimitiveImpl::setLocal(bool local) {
	this->local = local;
}

bool PrimitiveImpl::wasModified() const	{
	return modified;
}
