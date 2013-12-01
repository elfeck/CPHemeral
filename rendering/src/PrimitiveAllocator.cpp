#include "PrimitiveAllocator.h"


using namespace cph;

PrimitiveAllocator::PrimitiveAllocator() :
	vec1fAlloc(1, 0x20000000),
	vec2fAlloc(0x20000000, 0x40000000),
	vec3fAlloc(0x40000000, 0x60000000),
	vec4fAlloc(0x60000000, 0x80000000),
	mat2fAlloc(0x80000000, 0xa0000000),
	mat3fAlloc(0xa0000000, 0xc0000000),
	mat4fAlloc(0xc0000000, 0xe0000000)
{

}

PrimitiveAllocator::~PrimitiveAllocator() {

}

bool PrimitiveAllocator::prmiWithinRange(Primitive* prmi, std::uint32_t lower, std::uint32_t upper) {
	return prmi->getUniqueId() >= lower && prmi->getUniqueId() < upper;
}

PrimitiveImpl* PrimitiveAllocator::lookupPrimitive(Primitive* prmi) {
	if(prmiWithinRange(prmi, 1, 0x20000000)) return vec1fAlloc.at(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x20000000, 0x40000000)) return vec2fAlloc.at(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x40000000, 0x60000000)) return vec3fAlloc.at(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x60000000, 0x80000000)) return vec4fAlloc.at(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x80000000, 0xa0000000)) return mat2fAlloc.at(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0xa0000000, 0xc0000000)) return mat3fAlloc.at(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0xc0000000, 0xe0000000)) return mat4fAlloc.at(prmi->getUniqueId());
	return 0;
}

PrmiVec1fImpl* PrimitiveAllocator::allocPrmiVec1f() {
	PrmiVec1fImpl* vec = vec1fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiVec2fImpl* PrimitiveAllocator::allocPrmiVec2f() {
	PrmiVec2fImpl* vec = vec2fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiVec3fImpl* PrimitiveAllocator::allocPrmiVec3f() {
	PrmiVec3fImpl* vec = vec3fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiVec4fImpl* PrimitiveAllocator::allocPrmiVec4f() {
	PrmiVec4fImpl* vec = vec4fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(vec->getUniqueId(), vec));
	return vec;
}

PrmiMat2fImpl* PrimitiveAllocator::allocPrmiMat2f() {
	PrmiMat2fImpl* mat = mat2fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(mat->getUniqueId(), mat));
	return mat;
}

PrmiMat3fImpl* PrimitiveAllocator::allocPrmiMat3f() {
	PrmiMat3fImpl* mat = mat3fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(mat->getUniqueId(), mat));
	return mat;
}

PrmiMat4fImpl* PrimitiveAllocator::allocPrmiMat4f() {
	PrmiMat4fImpl* mat = mat4fAlloc.allocate();
	primitiveLookup.insert(std::make_pair(mat->getUniqueId(), mat));
	return mat;
}

void PrimitiveAllocator::releasePrimitive(Primitive* prmi) {
	primitiveLookup.erase(prmi->getUniqueId());
	if(prmiWithinRange(prmi, 1, 0x20000000)) vec1fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x20000000, 0x40000000)) vec2fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x40000000, 0x60000000)) vec3fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x60000000, 0x80000000)) vec4fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0x80000000, 0xa0000000)) mat2fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0xa0000000, 0xc0000000)) mat3fAlloc.release(prmi->getUniqueId());
	else if(prmiWithinRange(prmi, 0xc0000000, 0xe0000000)) mat4fAlloc.release(prmi->getUniqueId());
}
