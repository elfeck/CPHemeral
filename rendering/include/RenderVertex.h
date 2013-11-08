#ifndef RENDER_VERTEX_H_
#define RENDER_VERTEX_H_

#include <cstdint>


namespace cph {

struct Primitive;
struct PrmiVec1f;
struct PrmiVec2f;
struct PrmiVec3f;
struct PrmiVec4f;
struct PrmiMat2f;
struct PrmiMat3f;
struct PrmiMat4f;

struct RenderVertex {
		
	virtual PrmiVec1f* addVec1f(const char* name = "", float x = 0.0f) = 0;
	virtual PrmiVec2f* addVec2f(const char* name = "", float x = 0.0f, float y = 0.0f) = 0;
	virtual PrmiVec3f* addVec3f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f) = 0;
	virtual PrmiVec4f* addVec4f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f) = 0;
	virtual PrmiMat2f* addMat2f(const char* name = "") = 0;
	virtual PrmiMat3f* addMat3f(const char* name = "") = 0;
	virtual PrmiMat4f* addMat4f(const char* name = "") = 0;
	
	virtual void removePrimitive(Primitive* prmi) = 0;

	virtual std::uint32_t getUniqueId() const = 0;

};

}

#endif