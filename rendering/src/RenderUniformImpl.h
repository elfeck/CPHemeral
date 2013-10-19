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
	
	virtual PrmiVec1f* addVec1f(const char* name = "", float x = 0.0f);
	virtual PrmiVec2f* addVec2f(const char* name = "", float x = 0.0f, float y = 0.0f);
	virtual PrmiVec3f* addVec3f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f);
	virtual PrmiVec4f* addVec4f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
	virtual PrmiMat2f* addMat2f(const char* name = "");
	virtual PrmiMat3f* addMat3f(const char* name = "");
	virtual PrmiMat4f* addMat4f(const char* name = "");
	
	virtual void removePrimitive(Primitive* prmi);
	
	virtual std::uint32_t getUniqueId() const;

	void uploadUniformGL(GLuint program);

	void setPrmiAllocPtr(PrimitiveAllocator* prmiAllocPtr);

};

}

#endif