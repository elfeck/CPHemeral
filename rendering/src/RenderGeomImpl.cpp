#include "RenderGeomImpl.h"
#include "../include/RenderingComponent.h"

using namespace cph;

RenderGeomImpl::RenderGeomImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), vertices(), vertexLookupPtr(0)
{

}

RenderGeomImpl::~RenderGeomImpl() {

}

void RenderGeomImpl::addVertex(RenderVertex* vertex) {
	vertices.insert(std::make_pair(vertex->getUniqueId(), vertexLookupPtr->at(vertex->getUniqueId())));
}

void RenderGeomImpl::removeVertex(RenderVertex* vertex) {
	vertices.erase(vertex->getUniqueId());
}

std::uint32_t RenderGeomImpl::getUniqueId() const {
	return uniqueId;
}

void RenderGeomImpl::setVertexLookupPtr(SingleIdAllocator<RenderVertexImpl>* vertexLookupPtr) {
	this->vertexLookupPtr = vertexLookupPtr;
}

void RenderGeomImpl::destroyAllVerticesRecursively(RenderingComponent* comp) {
	for(std::map<std::uint32_t, RenderVertexImpl*>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
		it->second->destroyAllPrimitivesRecursively(comp);
		comp->destroyVertex(it->second);
	}
}
