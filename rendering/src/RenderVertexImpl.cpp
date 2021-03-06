#include "RenderVertexImpl.h"
#include "SystemLog.h"


using namespace cph;

RenderVertexImpl::RenderVertexImpl(std::uint32_t uniqueId) :
	uniqueId(uniqueId), vertexIndex(-1), primitives(), prmiAllocPtr(0)
{

}

RenderVertexImpl::~RenderVertexImpl() {
	for(std::map<std::string, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		if(it->second->isLocal()) prmiAllocPtr->releasePrimitive(it->second);
	}
}

PrmiVec1f* RenderVertexImpl::addLocalVec1f(const char* name, float x) {
	PrmiVec1fImpl* vec = prmiAllocPtr->allocPrmiVec1f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setX(x);
	vec->setLocal(true);
	return vec;
}

PrmiVec2f* RenderVertexImpl::addLocalVec2f(const char* name, float x, float y) {
	PrmiVec2fImpl* vec = prmiAllocPtr->allocPrmiVec2f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setXY(x, y);
	vec->setLocal(true);
	return vec;
}

PrmiVec3f* RenderVertexImpl::addLocalVec3f(const char* name, float x, float y, float z) {
	PrmiVec3fImpl* vec = prmiAllocPtr->allocPrmiVec3f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setXYZ(x, y, z);
	vec->setLocal(true);
	return vec;
}

PrmiVec4f* RenderVertexImpl::addLocalVec4f(const char* name, float x, float y, float z, float w) {
	PrmiVec4fImpl* vec = prmiAllocPtr->allocPrmiVec4f();
	primitives.insert(std::make_pair(name, vec));
	vec->wget()->setXYZW(x, y, z, w);
	vec->setLocal(true);
	return vec;
}	

PrmiMat2f* RenderVertexImpl::addLocalMat2f(const char* name) {
	PrmiMat2fImpl* mat = prmiAllocPtr->allocPrmiMat2f();
	primitives.insert(std::make_pair(name, mat));
	mat->setLocal(true);
	return mat;
}

PrmiMat3f* RenderVertexImpl::addLocalMat3f(const char* name) {
	PrmiMat3fImpl* mat = prmiAllocPtr->allocPrmiMat3f();
	primitives.insert(std::make_pair(name, mat));
	mat->setLocal(true);
	return mat;
}

PrmiMat4f* RenderVertexImpl::addLocalMat4f(const char* name) {
	PrmiMat4fImpl* mat = prmiAllocPtr->allocPrmiMat4f();
	primitives.insert(std::make_pair(name, mat));
	mat->setLocal(true);
	return mat;
}

void RenderVertexImpl::addGlobalVec1f(const char* name, PrmiVec1f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::addGlobalVec2f(const char* name, PrmiVec2f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::addGlobalVec3f(const char* name, PrmiVec3f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::addGlobalVec4f(const char* name, PrmiVec4f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::addGlobalMat2f(const char* name, PrmiMat2f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::addGlobalMat3f(const char* name, PrmiMat3f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::addGlobalMat4f(const char* name, PrmiMat4f* vec) {
	primitives.insert(std::make_pair(name, prmiAllocPtr->lookupPrimitive(vec)));
}

void RenderVertexImpl::removePrimitive(Primitive* prmi) {
	for(std::map<std::string, PrimitiveImpl*>::iterator it = primitives.begin(); it != primitives.end(); ++it) {
		if(it->second->getUniqueId() == prmi->getUniqueId()) {
			primitives.erase(it->first);
			if(prmi->isLocal()) prmiAllocPtr->releasePrimitive(prmi);
			break;
		}
	}
}

std::uint32_t RenderVertexImpl::getUniqueId() const {
	return uniqueId;
}

void RenderVertexImpl::fetchVertexData(std::vector<GLfloat>& buffer, const std::set<AttributeFormat>& format, 
										unsigned int* offset) const {
	for(std::set<AttributeFormat>::const_iterator it = format.begin(); it != format.end(); ++it) {
		if(primitives.count(it->getOriginalName()) == 1) {
			primitives.at(it->getOriginalName())->fetchVertexData(buffer, offset);
		}
		else {
			getErrorLog().pre() << "Vertex attribute: " << it->getOriginalName() << " not available in RenderVertex " 
				<< uniqueId << std::endl;
		}
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
