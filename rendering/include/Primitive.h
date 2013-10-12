#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include <cstdint>

namespace cph {

struct Primitive {

	virtual std::uint64_t getParentId() const = 0;
	virtual std::uint32_t getPrmiId() const = 0;
	virtual const char* getName() const = 0;

};

}


#endif