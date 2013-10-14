#ifndef PRMI_VEC3F_H_
#define PRMI_VEC3F_H_

#include <cstdint>
#include "Vec3f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec3f {

	virtual std::uint32_t getUniqueId() const = 0;
	virtual const char* getName() const = 0;
	virtual void setName(const char* name) = 0;

	virtual Vec3f* get() = 0;

};

}

#endif