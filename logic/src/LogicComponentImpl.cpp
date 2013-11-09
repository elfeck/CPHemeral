#include "LogicComponentImpl.h"
#include "LogicSystemImpl.h"


using namespace cph;

LogicComponentImpl::LogicComponentImpl(std::uint32_t uniqueId) : 
	uniqueId(uniqueId), sysId(0), system(0), logicable(0)
{

}

LogicComponentImpl::~LogicComponentImpl() {

}
	
void LogicComponentImpl::setLogicable(Logicable* logicable) {
	this->logicable = logicable;
}

std::uint8_t LogicComponentImpl::getSysId() const {
	return sysId;
}

std::uint32_t LogicComponentImpl::getUniqueId() const {
	return uniqueId;
}

void LogicComponentImpl::destroy() {
	system->releaseComponent(this);
}

void LogicComponentImpl::setSystem(LogicSystemImpl* system) {
	this->system = system;
	sysId = system->getSysId();
}

void LogicComponentImpl::executeLogic(long delta) {
	if(logicable != 0) logicable->doLogic(delta);
}

