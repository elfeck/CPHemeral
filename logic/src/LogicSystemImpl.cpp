#include "LogicSystemImpl.h"
#include "ObjectQueue.h"
#include "Object.h"


using namespace cph;

LogicSystemImpl::LogicSystemImpl(std::uint8_t sysId) :
	logicAlloc(), sysId(sysId), errorLog(), debugLog()
{
	errorLog.setLocalConsolePrintOnLog(true);
}

LogicSystemImpl::~LogicSystemImpl() {

}

LogicComponent* LogicSystemImpl::createComponent() {
	LogicComponentImpl* comp =  logicAlloc.allocate();
	debugLog << "[LgcSys: created [LogicComponent= " << comp->getUniqueId << "]" << std::endl;
	comp->setSystem(this);
	return comp;
}

void LogicSystemImpl::execute(ObjectManager* objectManager, long delta) {
	ObjectQueue* queue = objectManager->tempGetObjectsWith(sysId);
	LogicComponentImpl* comp = 0;
	while(queue->hasElements()) {
		comp = logicAlloc.at(queue->pop()->getComponent(sysId)->getUniqueId());
		comp->executeLogic(delta);
	}
}

std::uint8_t LogicSystemImpl::getSysId() const {
	return sysId;
}

void LogicSystemImpl::setLog(Log* log, const char* target) {
	if(log != 0) {
		if(log->getTarget() == "error") errorLog.setLogPtr(log);
		if(log->getTarget() == "debug") debugLog.setLogPtr(log);
	} else {
		if(strcmp(target, "error")) errorLog.setLogPtr(0);
		if(strcmp(target, "debug")) debugLog.setLogPtr(0);
	}

}

void LogicSystemImpl::releaseComponent(LogicComponent* component) {
	logicAlloc.release(component->getUniqueId());
	debugLog << "[LgcSys: destroyed [logicComponent= " << component->getUniqueId() << "]" << std::endl;
}

