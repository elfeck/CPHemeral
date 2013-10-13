#ifndef RENDER_VERTEX_H_
#define RENDER_VERTEX_H_

#include <cstdint>
#include "Primitive.h"


namespace cph {

struct RenderVertex {

	virtual void addVertexPrimitive(Primitive* prmi) = 0;
	virtual void removeVertexPrimitive(Primitive* prmi) = 0;

	virtual std::uint32_t getUniqueId() const = 0;

};

}

#endif