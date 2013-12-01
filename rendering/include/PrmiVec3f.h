#ifndef PRMI_VEC3F_H_
#define PRMI_VEC3F_H_

#include <cstdint>
#include "Vec3f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec3f : public Primitive {

	virtual std::uint32_t getUniqueId() const = 0;
	virtual bool isLocal() const = 0;

	virtual Vec3f* wget() = 0;
	virtual const Vec3f* rget() const = 0;

};

}

#endif