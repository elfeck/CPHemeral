#ifndef PRMI_VEC2F_H_
#define PRMI_VEC2F_H_

#include <cstdint>
#include "Vec2f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec2f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;
	virtual const char* getName() const = 0;
	virtual void setName(const char* name) = 0;

	virtual Vec2f* get() = 0;

};

}

#endif