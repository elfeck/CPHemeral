#ifndef RENDER_VERTEX_IMPL_H_
#define RENDER_VERTEX_IMPL_H_

#include <map>
#include <gl/glew.h>
#include "../include/RenderVertex.h"
#include "primitive/PrimitiveImpl.h"


namespace cph {

class RenderVertexImpl : public RenderVertex {

private:
	const std::uint32_t vertId;
	unsigned int vertexIndex;

public:
	RenderVertexImpl(std::uint32_t vertId);
	~RenderVertexImpl();

	virtual void addPrimitive(Primitive* prmi);
	virtual void removePrimitive(Primitive* prmi);

	virtual std::uint32_t getVertId() const;

	void fetchVertexData(std::vector<GLfloat>& buffer) const;
	unsigned int getVertexIndex() const;
	void setVertexIndex(unsigned int vertexIndex);

};

}

#endif