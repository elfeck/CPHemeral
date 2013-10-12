#ifndef RENDER_UNIFORM_H_
#define RENDER_UNIFORM_H_

#include "Primitive.h"


namespace cph {

struct RenderUniform {

	virtual void addPrimitive(Primitive* prmi) = 0;
	virtual void removePrimitive(Primitive* prmi) = 0;

	virtual std::uint32_t getUniId() = 0;

};

}

#endif