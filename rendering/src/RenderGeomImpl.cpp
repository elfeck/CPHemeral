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

void RenderGeomImpl::fetchIndexData(std::vector<GLushort>& buffer, unsigned int offset) const {
	for(std::map<std::uint32_t, RenderVertexImpl*>::const_iterator it = vertices.begin(); it != vertices.end(); ++it) { 
		buffer.push_back(offset + it->second->getVertexIndex());
	}
}

void RenderGeomImpl::setVertexLookupPtr(SingleIdAllocator<RenderVertexImpl>* vertexLookupPtr) {
	this->vertexLookupPtr = vertexLookupPtr;
}