#include "RenderVertexImpl.h"


using namespace cph;

RenderVertexImpl::RenderVertexImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), vertexIndex(-1), primitives(), prmiAllocPtr(0)
{

}

RenderVertexImpl::~RenderVertexImpl() {
	for(std::map<std::uint32_t, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		if(it->second->isLocal()) prmiAllocPtr->releasePrimitive(it->second);
	}
}

PrmiVec1f* RenderVertexImpl::addVec1f(const char* name, float x) {
	PrmiVec1fImpl* vec = prmiAllocPtr->allocPrmiVec1f();
	vec->get()->setX(x);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}

PrmiVec2f* RenderVertexImpl::addVec2f(const char* name, float x, float y) {
	PrmiVec2fImpl* vec = prmiAllocPtr->allocPrmiVec2f();
	vec->get()->setXY(x, y);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}

PrmiVec3f* RenderVertexImpl::addVec3f(const char* name, float x, float y, float z) {
	PrmiVec3fImpl* vec = prmiAllocPtr->allocPrmiVec3f();
	vec->get()->setXYZ(x, y, z);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}

PrmiVec4f* RenderVertexImpl::addVec4f(const char* name, float x, float y, float z, float w) {
	PrmiVec4fImpl* vec = prmiAllocPtr->allocPrmiVec4f();
	vec->get()->setXYZW(x, y, z, w);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}	

PrmiMat2f* RenderVertexImpl::addMat2f(const char* name) {
	PrmiMat2fImpl* mat = prmiAllocPtr->allocPrmiMat2f();
	mat->setName(name);
	mat->setLocal(true);
	return mat;
}

PrmiMat3f* RenderVertexImpl::addMat3f(const char* name) {
	PrmiMat3fImpl* mat = prmiAllocPtr->allocPrmiMat3f();
	mat->setName(name);
	mat->setLocal(true);
	return mat;
}

PrmiMat4f* RenderVertexImpl::addMat4f(const char* name) {
	PrmiMat4fImpl* mat = prmiAllocPtr->allocPrmiMat4f();
	mat->setName(name);
	mat->setLocal(true);
	return mat;
}

void RenderVertexImpl::removePrimitive(Primitive* prmi) {
	prmiAllocPtr->releasePrimitive(prmi);
}

std::uint32_t RenderVertexImpl::getUniqueId() const {
	return uniqueId;
}

void RenderVertexImpl::fetchVertexData(std::vector<GLfloat>& buffer) const {
	for(std::map<std::uint32_t, PrimitiveImpl*>::const_iterator it = primitives.begin(); it != primitives.end(); ++it) {
		it->second->fetchVertexData(buffer);
	}
}

int RenderVertexImpl::getVertexIndex() const {
	return vertexIndex;
}

void RenderVertexImpl::setVertexIndex(int vertexIndex) {
	this->vertexIndex = vertexIndex;
}

void RenderVertexImpl::setPrmiAllocPtr(PrimitiveAllocator* prmiAllocPtr) {
	this->prmiAllocPtr = prmiAllocPtr;
}
