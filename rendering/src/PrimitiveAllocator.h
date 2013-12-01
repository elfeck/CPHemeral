#ifndef PRIMITIVE_ALLOCATOR_H_
#define PRIMITIVE_ALLOCATOR_H_

#include "SingleIdAllocator.h"
#include <unordered_map>
#include "primitive/PrmiVec1fImpl.h"
#include "primitive/PrmiVec2fImpl.h"
#include "primitive/PrmiVec3fImpl.h"
#include "primitive/PrmiVec4fImpl.h"
#include "primitive/PrmiMat2fImpl.h"
#include "primitive/PrmiMat3fImpl.h"
#include "primitive/PrmiMat4fImpl.h"


namespace cph {

class PrimitiveAllocator {

private:
	std::unordered_map<std::uint32_t, PrimitiveImpl*> primitiveLookup;

	SingleIdAllocator<PrmiVec1fImpl> vec1fAlloc;
	SingleIdAllocator<PrmiVec2fImpl> vec2fAlloc;
	SingleIdAllocator<PrmiVec3fImpl> vec3fAlloc;
	SingleIdAllocator<PrmiVec4fImpl> vec4fAlloc;

	SingleIdAllocator<PrmiMat2fImpl> mat2fAlloc;
	SingleIdAllocator<PrmiMat3fImpl> mat3fAlloc;
	SingleIdAllocator<PrmiMat4fImpl> mat4fAlloc;
	
	bool prmiWithinRange(Primitive* prmi, std::uint32_t lower, std::uint32_t upper);

	PrimitiveAllocator(const PrimitiveAllocator& other);

public:
	PrimitiveAllocator();
	~PrimitiveAllocator();
	
	PrimitiveImpl* lookupPrimitive(Primitive* prmi);

	PrmiVec1fImpl* allocPrmiVec1f();
	PrmiVec2fImpl* allocPrmiVec2f();
	PrmiVec3fImpl* allocPrmiVec3f();
	PrmiVec4fImpl* allocPrmiVec4f();

	PrmiMat2fImpl* allocPrmiMat2f();
	PrmiMat3fImpl* allocPrmiMat3f();
	PrmiMat4fImpl* allocPrmiMat4f();

	void releasePrimitive(Primitive* prmi);

};

}

#endif