#ifndef PRMI_VEC1F_H_
#define PRMI_VEC1F_H_

#include <cstdint>
#include "Vec1f.h"
#include "Primitive.h"


namespace cph {

struct PrmiVec1f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;
	virtual const char* getName() const = 0;
	virtual void setName(const char* name) = 0;

	virtual Vec1f* get() = 0;

};

}

#endif