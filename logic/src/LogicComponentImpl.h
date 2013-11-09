#ifndef LOGIC_COMPONENT_IMPL_H_
#define LOGIC_COMPONENT_IMPL_H_

#include "../include/LogicComponent.h"
#include "../include/Logicable.h"


namespace cph {

class LogicSystemImpl;

class LogicComponentImpl : public LogicComponent {

private:
	const std::uint32_t uniqueId;
	std::uint8_t sysId;
	LogicSystemImpl* system;

	Logicable* logicable;

public:
	LogicComponentImpl(std::uint32_t uniqueId);
	~LogicComponentImpl();
	
	virtual void setLogicable(Logicable* logicable);

	virtual std::uint8_t getSysId() const;
	virtual std::uint32_t getUniqueId() const;

	virtual void destroy();

	void setSystem(LogicSystemImpl* system);
	void executeLogic(long delta);

};

}

#endif