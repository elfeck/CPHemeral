#include "RenderUniformImpl.h"


using namespace cph;

RenderUniformImpl::RenderUniformImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), primitives(), prmiAllocPtr(0)
{

}

RenderUniformImpl::~RenderUniformImpl() {
	for(std::map<std::string, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		if(it->second->isLocal()) prmiAllocPtr->releasePrimitive(it->second);
	}
}

PrmiVec1f* RenderUniformImpl::addLocalVec1f(const char* name, float x) {
	PrmiVec1fImpl* vec = prmiAllocPtr->allocPrmiVec1f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setX(x);
	vec->setLocal(true);
	return vec;
}

PrmiVec2f* RenderUniformImpl::addLocalVec2f(const char* name, float x, float y) {
	PrmiVec2fImpl* vec = prmiAllocPtr->allocPrmiVec2f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setXY(x, y);
	vec->setLocal(true);
	return vec;
}

PrmiVec3f* RenderUniformImpl::addLocalVec3f(const char* name, float x, float y, float z) {
	PrmiVec3fImpl* vec = prmiAllocPtr->allocPrmiVec3f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setXYZ(x, y, z);
	vec->setLocal(true);
	return vec;
}

PrmiVec4f* RenderUniformImpl::addLocalVec4f(const char* name, float x, float y, float z, float w) {
	PrmiVec4fImpl* vec = prmiAllocPtr->allocPrmiVec4f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setXYZW(x, y, z, w);
	vec->setLocal(true);
	return vec;
}	

PrmiMat2f* RenderUniformImpl::addLocalMat2f(const char* name) {
	PrmiMat2fImpl* mat = prmiAllocPtr->allocPrmiMat2f();
	primitives.insert(std::make_pair(name, mat));
	mat->setLocal(true);
	return mat;
}

PrmiMat3f* RenderUniformImpl::addLocalMat3f(const char* name) {
	PrmiMat3fImpl* mat = prmiAllocPtr->allocPrmiMat3f();
	primitives.insert(std::make_pair(name, mat));
	mat->setLocal(true);
	return mat;
}

PrmiMat4f* RenderUniformImpl::addLocalMat4f(const char* name) {
	PrmiMat4fImpl* mat = prmiAllocPtr->allocPrmiMat4f();
	primitives.insert(std::make_pair(name, mat));
	mat->setLocal(true);
	return mat;
}

void RenderUniformImpl::addGlobalVec1f(const char* name, PrmiVec1f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::addGlobalVec2f(const char* name, PrmiVec2f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::addGlobalVec3f(const char* name, PrmiVec3f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::addGlobalVec4f(const char* name, PrmiVec4f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::addGlobalMat2f(const char* name, PrmiMat2f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::addGlobalMat3f(const char* name, PrmiMat3f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::addGlobalMat4f(const char* name, PrmiMat4f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderUniformImpl::removePrimitive(Primitive* prmi) {
	for(std::map<std::string, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		if(it->second->getUniqueId() == prmi->getUniqueId()) {
			primitives.erase(it->first);
			if(prmi->isLocal()) prmiAllocPtr->releasePrimitive(prmi);
			break;
		}
	}
}

std::uint32_t RenderUniformImpl::getUniqueId() const {
	return uniqueId;
}

void RenderUniformImpl::uploadUniformGL(GLuint program) {
	for(std::map<std::string, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		it->second->uploadAsUniformGL(program, it->first);
	}
}

void RenderUniformImpl::setPrmiAllocPtr(PrimitiveAllocator* prmiAllocPtr) {
	this->prmiAllocPtr = prmiAllocPtr;
}
