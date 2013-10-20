#include "RenderUniformImpl.h"


using namespace cph;

RenderUniformImpl::RenderUniformImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), primitives(), prmiAllocPtr(0)
{

}

RenderUniformImpl::~RenderUniformImpl() {
	for(std::map<std::uint32_t, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		if(it->second->isLocal()) prmiAllocPtr->releasePrimitive(it->second);
	}
}

PrmiVec1f* RenderUniformImpl::addVec1f(const char* name, float x) {
	PrmiVec1fImpl* vec = prmiAllocPtr->allocPrmiVec1f();
	vec->get()->setX(x);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}

PrmiVec2f* RenderUniformImpl::addVec2f(const char* name, float x, float y) {
	PrmiVec2fImpl* vec = prmiAllocPtr->allocPrmiVec2f();
	vec->get()->setXY(x, y);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}

PrmiVec3f* RenderUniformImpl::addVec3f(const char* name, float x, float y, float z) {
	PrmiVec3fImpl* vec = prmiAllocPtr->allocPrmiVec3f();
	vec->get()->setXYZ(x, y, z);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}

PrmiVec4f* RenderUniformImpl::addVec4f(const char* name, float x, float y, float z, float w) {
	PrmiVec4fImpl* vec = prmiAllocPtr->allocPrmiVec4f();
	vec->get()->setXYZW(x, y, z, w);
	vec->setName(name);
	vec->setLocal(true);
	return vec;
}	

PrmiMat2f* RenderUniformImpl::addMat2f(const char* name) {
	PrmiMat2fImpl* mat = prmiAllocPtr->allocPrmiMat2f();
	mat->setName(name);
	mat->setLocal(true);
	return mat;
}

PrmiMat3f* RenderUniformImpl::addMat3f(const char* name) {
	PrmiMat3fImpl* mat = prmiAllocPtr->allocPrmiMat3f();
	mat->setName(name);
	mat->setLocal(true);
	return mat;
}

PrmiMat4f* RenderUniformImpl::addMat4f(const char* name) {
	PrmiMat4fImpl* mat = prmiAllocPtr->allocPrmiMat4f();
	mat->setName(name);
	mat->setLocal(true);
	return mat;
}

void RenderUniformImpl::removePrimitive(Primitive* prmi) {
	prmiAllocPtr->releasePrimitive(prmi);
}

std::uint32_t RenderUniformImpl::getUniqueId() const {
	return uniqueId;
}

void RenderUniformImpl::uploadUniformGL(GLuint program) {

}

void RenderUniformImpl::setPrmiAllocPtr(PrimitiveAllocator* prmiAllocPtr) {
	this->prmiAllocPtr = prmiAllocPtr;
}
