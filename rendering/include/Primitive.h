#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include <cstdint>


namespace cph {

struct Primitive {

	virtual std::uint32_t getUniqueId() const = 0;

};

}


#endif