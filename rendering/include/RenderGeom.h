#ifndef RENDER_GEOM_H_
#define RENDER_GEOM_H_

#include "RenderVertex.h"


namespace cph {

struct RenderGeom {

	virtual void addVertex(RenderVertex* vertex) = 0;
	virtual void removeVertex(RenderVertex* vertex) = 0;

	virtual std::uint32_t getUniqueId() const = 0;

};

}

#endif