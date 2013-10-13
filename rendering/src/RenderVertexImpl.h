#ifndef RENDER_VERTEX_IMPL_H_
#define RENDER_VERTEX_IMPL_H_

#include <map>
#include <unordered_map>
#include <cstdint>
#include <gl/glew.h>
#include "../include/RenderVertex.h"
#include "primitive/PrimitiveImpl.h"


namespace cph {

class RenderVertexImpl : public RenderVertex {

private:
	const std::uint32_t uniqueId;
	int vertexIndex;

	std::map<std::uint32_t, PrimitiveImpl*> primitives;
	
	std::unordered_map<std::uint32_t, PrimitiveImpl*>* prmiLookupPtr;

public:
	RenderVertexImpl(std::uint32_t uniqueId);
	~RenderVertexImpl();

	virtual void addVertexPrimitive(Primitive* prmi);
	virtual void removeVertexPrimitive(Primitive* prmi);

	virtual std::uint32_t getUniqueId() const;

	void fetchVertexData(std::vector<GLfloat>& buffer) const;
	
	int getVertexIndex() const;
	void setVertexIndex(int vertexIndex);

	void setPrmiLookupPtr(std::unordered_map<std::uint32_t, PrimitiveImpl*>* prmiLookupPtr);

};

}

#endif