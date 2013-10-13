#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <cstdint>


namespace cph {

struct Component {

	virtual std::uint8_t getSysId() const = 0;
	virtual std::uint32_t getUniqueId() const = 0;

	virtual void destroy() = 0;

};

}


#endif