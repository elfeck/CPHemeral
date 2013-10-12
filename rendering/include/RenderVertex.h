#ifndef RENDER_VERTEX_H_
#define RENDER_VERTEX_H_

#include <cstdint>
#include "Primitive.h"


namespace cph {

struct RenderVertex {

	virtual void addPrimitive(Primitive* prmi) = 0;
	virtual void removePrimitive(Primitive* prmi) = 0;

	virtual std::uint32_t getVertId() const = 0;

};

}

#endif