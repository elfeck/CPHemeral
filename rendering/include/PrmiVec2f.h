#ifndef PRMI_VEC2F_H_
#define PRMI_VEC2F_H_

#include <cstdint>
#include "Vec2f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec2f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;

	virtual Vec2f* wget() = 0;
	virtual const Vec2f* rget() const = 0;

};

}

#endif