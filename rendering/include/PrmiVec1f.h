#ifndef PRMI_VEC1F_H_
#define PRMI_VEC1F_H_

#include <cstdint>
#include "Vec1f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec1f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;
	virtual bool isLocal() const = 0;

	virtual Vec1f* wget() = 0;
	virtual const Vec1f* rget() const = 0;

};

}

#endif