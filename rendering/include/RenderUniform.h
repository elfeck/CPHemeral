#ifndef RENDER_UNIFORM_H_
#define RENDER_UNIFORM_H_

#include <cstdint>
#include "PrmiVec4f.h"


namespace cph {

struct RenderUniform {

	virtual void addUniformPrimitive(Primitive* prmi) = 0;
	virtual void removeUniformPrimitive(Primitive* prmi) = 0;

	virtual std::uint32_t getUniqueId() const = 0;

};

}

#endif