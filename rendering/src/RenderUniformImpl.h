#ifndef RENDER_UNIFORM_IMPL_H_
#define RENDER_UNIFORM_IMPL_H_

#include <map>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <gl/glew.h>
#include "primitive/PrimitiveImpl.h"
#include "../include/RenderUniform.h"
#include "PrimitiveAllocator.h"


namespace cph {

class RenderUniformImpl : public RenderUniform {

private:
	const std::uint32_t uniqueId;
	
	std::map<std::string, PrimitiveImpl*> primitives;

	PrimitiveAllocator* prmiAllocPtr;

public:
	RenderUniformImpl(std::uint32_t uniqueId);
	~RenderUniformImpl();
		
	virtual PrmiVec1f* addLocalVec1f(const char* name, float x = 0.0f);
	virtual PrmiVec2f* addLocalVec2f(const char* name, float x = 0.0f, float y = 0.0f);
	virtual PrmiVec3f* addLocalVec3f(const char* name, float x = 0.0f, float y = 0.0f, float z = 0.0f);
	virtual PrmiVec4f* addLocalVec4f(const char* name, float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
	virtual PrmiMat2f* addLocalMat2f(const char* name);
	virtual PrmiMat3f* addLocalMat3f(const char* name);
	virtual PrmiMat4f* addLocalMat4f(const char* name);

	virtual void addGlobalVec1f(const char* name, PrmiVec1f* vec);
	virtual void addGlobalVec2f(const char* name, PrmiVec2f* vec);
	virtual void addGlobalVec3f(const char* name, PrmiVec3f* vec);
	virtual void addGlobalVec4f(const char* name, PrmiVec4f* vec);
	virtual void addGlobalMat2f(const char* name, PrmiMat2f* mat);
	virtual void addGlobalMat3f(const char* name, PrmiMat3f* mat);
	virtual void addGlobalMat4f(const char* name, PrmiMat4f* mat);
	
	virtual void removePrimitive(Primitive* prmi);
	
	virtual std::uint32_t getUniqueId() const;

	void uploadUniformGL(GLuint program);

	void setPrmiAllocPtr(PrimitiveAllocator* prmiAllocPtr);

};

}

#endif