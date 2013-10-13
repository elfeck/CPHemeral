#include "RenderUniformImpl.h"


using namespace cph;

RenderUniformImpl::RenderUniformImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), primitives(), prmiLookupPtr(0)
{

}

RenderUniformImpl::~RenderUniformImpl() {

}

void RenderUniformImpl::addUniformPrimitive(Primitive* prmi) {
	primitives.insert(std::make_pair(prmi->getUniqueId(), prmiLookupPtr->at(prmi->getUniqueId())));

}

void RenderUniformImpl::removeUniformPrimitive(Primitive* prmi) {
	primitives.erase(prmi->getUniqueId());
}

std::uint32_t RenderUniformImpl::getUniqueId() const {
	return uniqueId;
}

void RenderUniformImpl::uploadUniformGL(GLuint program) {

}

void RenderUniformImpl::setPrmiLookupPtr(std::unordered_map<std::uint32_t, PrimitiveImpl*>* prmiLookupPtr) {
	this->prmiLookupPtr = prmiLookupPtr;
}
