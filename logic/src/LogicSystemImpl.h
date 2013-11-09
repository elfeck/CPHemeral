#ifndef LOGIC_SYSTEM_IMPL_H_
#define LOGIC_SYSTEM_IMPL_H_

#include "../include/LogicSystem.h"
#include "ObjectManager.h"
#include "Logger.h"
#include "SingleIdAllocator.h"
#include "LogicComponentImpl.h"


namespace cph {

struct LogicSystemImpl : public LogicSystem {
	
private:
	SingleIdAllocator<LogicComponentImpl> logicAlloc;
	Logger errorLog, debugLog;

	const std::uint8_t sysId;


public:
	LogicSystemImpl(std::uint8_t sysId);
	~LogicSystemImpl();

	virtual LogicComponent* createComponent();
	
	virtual void execute(ObjectManager* objectManager, long delta);
	virtual std::uint8_t getSysId() const;	
	
	virtual void setLog(Log* log, const char* target);

	void releaseComponent(LogicComponent* component);

};

}


#endif 
