#ifndef LOGIC_COMPONENT_H_
#define LOGIC_COMPONENT_H_

#include "Component.h"


namespace cph {

struct Logicable;

struct LogicComponent : public Component {

	virtual void setLogicable(Logicable* logicable) = 0;

	virtual std::uint8_t getSysId() const = 0;
	virtual std::uint32_t getUniqueId() const = 0;

	virtual void destroy() = 0;

};

}

#endif