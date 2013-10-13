#ifndef RENDER_GEOM_IMPL_H_
#define RENDER_GEOM_IMPL_H_

#include <map>
#include "RenderVertexImpl.h"
#include "SingleIdAllocator.h"
#include "../include/RenderGeom.h"


namespace cph {

class RenderGeomImpl : public RenderGeom {

private:
	std::uint32_t uniqueId;

	std::map<std::uint32_t, RenderVertexImpl*> vertices;

	SingleIdAllocator<RenderVertexImpl>* vertexLookupPtr;

public:
	RenderGeomImpl(std::uint32_t uniqueId);
	~RenderGeomImpl();

	virtual void addVertex(RenderVertex* vertex);
	virtual void removeVertex(RenderVertex* vertex);

	virtual std::uint32_t getUniqueId() const;

	void setVertexLookupPtr(SingleIdAllocator<RenderVertexImpl>* vertexLookupPtr);
};

}

#endif