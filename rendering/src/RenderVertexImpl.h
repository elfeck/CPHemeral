#ifndef RENDER_VERTEX_IMPL_H_
#define RENDER_VERTEX_IMPL_H_

#include <map>
#include <unordered_map>
#include <cstdint>
#include <set>
#include <gl/glew.h>
#include "../include/RenderVertex.h"
#include "opengl/AttributeFormat.h"
#include "primitive/PrimitiveImpl.h"
#include "PrimitiveAllocator.h"


namespace cph {

class RenderVertexImpl : public RenderVertex {

private:
	const std::uint32_t uniqueId;
	int vertexIndex;

	std::map<std::string, PrimitiveImpl*> primitives;
	
	PrimitiveAllocator* prmiAllocPtr;

public:
	RenderVertexImpl(std::uint32_t uniqueId);
	~RenderVertexImpl();
		
	virtual PrmiVec1f* addVec1f(const char* name = "", float x = 0.0f);
	virtual PrmiVec2f* addVec2f(const char* name = "", float x = 0.0f, float y = 0.0f);
	virtual PrmiVec3f* addVec3f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f);
	virtual PrmiVec4f* addVec4f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
	virtual PrmiMat2f* addMat2f(const char* name = "");
	virtual PrmiMat3f* addMat3f(const char* name = "");
	virtual PrmiMat4f* addMat4f(const char* name = "");
	
	virtual void removePrimitive(Primitive* prmi);
	
	virtual std::uint32_t getUniqueId() const;

	void fetchVertexData(std::vector<GLfloat>& buffer, const std::set<AttributeFormat>& format) const;
	
	int getVertexIndex() const;
	void setVertexIndex(int vertexIndex);
	void setPrmiAllocPtr(PrimitiveAllocator* prmiAllocPtr);

};

}

#endif