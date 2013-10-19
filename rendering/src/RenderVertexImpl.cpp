#include "RenderVertexImpl.h"


using namespace cph;

RenderVertexImpl::RenderVertexImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), vertexIndex(-1), primitives(), prmiAllocPtr(0)
{

}

RenderVertexImpl::~RenderVertexImpl() {

}


PrmiVec1f* RenderVertexImpl::addVec1f(const char* name, float x) {
	PrmiVec1f* vec = prmiAllocPtr->allocPrmiVec1f();
	vec->get()->setX(x);
	vec->setName(name);
	return vec;
}

PrmiVec2f* RenderVertexImpl::addVec2f(const char* name, float x, float y) {
	PrmiVec2f* vec = prmiAllocPtr->allocPrmiVec2f();
	vec->get()->setXY(x, y);
	vec->setName(name);
	return vec;
}

PrmiVec3f* RenderVertexImpl::addVec3f(const char* name, float x, float y, float z) {
	PrmiVec3f* vec = prmiAllocPtr->allocPrmiVec3f();
	vec->get()->setXYZ(x, y, z);
	vec->setName(name);
	return vec;
}

PrmiVec4f* RenderVertexImpl::addVec4f(const char* name, float x, float y, float z, float w) {
	PrmiVec4f* vec = prmiAllocPtr->allocPrmiVec4f();
	vec->get()->setXYZW(x, y, z, w);
	vec->setName(name);
	return vec;
}	

PrmiMat2f* RenderVertexImpl::addMat2f(const char* name) {
	PrmiMat2f* mat = prmiAllocPtr->allocPrmiMat2f();
	mat->setName(name);
	return mat;
}

PrmiMat3f* RenderVertexImpl::addMat3f(const char* name) {
	PrmiMat3f* mat = prmiAllocPtr->allocPrmiMat3f();
	mat->setName(name);
	return mat;
}

PrmiMat4f* RenderVertexImpl::addMat4f(const char* name) {
	PrmiMat4f* mat = prmiAllocPtr->allocPrmiMat4f();
	mat->setName(name);
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
