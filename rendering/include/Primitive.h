#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include <cstdint>

namespace cph {

struct Primitive {

	virtual std::uint32_t getUniqueId() const = 0;
	virtual const char* getName() const = 0;
	virtual void setName(const char* name) = 0;

};

}


#endif