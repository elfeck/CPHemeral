#ifndef RENDERING_ALLOCATOR_H_
#define RENDERING_ALLOCATOR_H_


namespace cph {

struct RenderingComponent;
struct Primitive;
struct PrmiVec1f;
struct PrmiVec2f;
struct PrmiVec3f;
struct PrmiVec4f;
struct PrmiMat2f;
struct PrmiMat3f;
struct PrmiMat4f;

struct RenderingAllocator {

	virtual RenderingComponent* createComponent() = 0;

	virtual PrmiVec1f* createGlobalVec1f() = 0;
	virtual PrmiVec2f* createGlobalVec2f() = 0;
	virtual PrmiVec3f* createGlobalVec3f() = 0;
	virtual PrmiVec4f* createGlobalVec4f() = 0;
	virtual PrmiMat2f* createGlobalMat2f() = 0;
	virtual PrmiMat3f* createGlobalMat3f() = 0;
	virtual PrmiMat4f* createGlobalMat4f() = 0;

	virtual void destroyGlobalPrimitive(Primitive* prmi) = 0;

};

}


#endif