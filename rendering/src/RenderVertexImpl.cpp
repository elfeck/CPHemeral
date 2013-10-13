#include "RenderVertexImpl.h"


using namespace cph;

RenderVertexImpl::RenderVertexImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), vertexIndex(-1), primitives(), prmiLookupPtr(0)
{

}

RenderVertexImpl::~RenderVertexImpl() {

}

void RenderVertexImpl::addVertexPrimitive(Primitive* prmi) {
	primitives.insert(std::make_pair(prmi->getUniqueId(), prmiLookupPtr->at(prmi->getUniqueId())));
}

void RenderVertexImpl::removeVertexPrimitive(Primitive* prmi) {
	primitives.erase(prmi->getUniqueId());
}

std::uint32_t RenderVertexImpl::getUniqueId() const {
	return uniqueId;
}

void RenderVertexImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {

}

int RenderVertexImpl::getVertexIndex() const {
	return vertexIndex;
}

void RenderVertexImpl::setVertexIndex(int vertexIndex) {
	this->vertexIndex = vertexIndex;
}

void RenderVertexImpl::setPrmiLookupPtr(std::unordered_map<std::uint32_t, PrimitiveImpl*>* prmiLookupPtr) {
	this->prmiLookupPtr = prmiLookupPtr;
}
