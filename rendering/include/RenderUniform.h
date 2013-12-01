#ifndef RENDER_UNIFORM_H_
#define RENDER_UNIFORM_H_

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

struct RenderUniform {

	virtual PrmiVec1f* addLocalVec1f(const char* name, float x = 0.0f) = 0;
	virtual PrmiVec2f* addLocalVec2f(const char* name, float x = 0.0f, float y = 0.0f) = 0;
	virtual PrmiVec3f* addLocalVec3f(const char* name, float x = 0.0f, float y = 0.0f, float z = 0.0f) = 0;
	virtual PrmiVec4f* addLocalVec4f(const char* name, float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f) = 0;
	virtual PrmiMat2f* addLocalMat2f(const char* name) = 0;
	virtual PrmiMat3f* addLocalMat3f(const char* name) = 0;
	virtual PrmiMat4f* addLocalMat4f(const char* name) = 0;

	virtual void addGlobalVec1f(const char* name, PrmiVec1f* vec) = 0;
	virtual void addGlobalVec2f(const char* name, PrmiVec2f* vec) = 0;
	virtual void addGlobalVec3f(const char* name, PrmiVec3f* vec) = 0;
	virtual void addGlobalVec4f(const char* name, PrmiVec4f* vec) = 0;
	virtual void addGlobalMat2f(const char* name, PrmiMat2f* mat) = 0;
	virtual void addGlobalMat3f(const char* name, PrmiMat3f* mat) = 0;
	virtual void addGlobalMat4f(const char* name, PrmiMat4f* mat) = 0;
	
	virtual void removePrimitive(Primitive* prmi) = 0;

	virtual std::uint32_t getUniqueId() const = 0;

};

}

#endif