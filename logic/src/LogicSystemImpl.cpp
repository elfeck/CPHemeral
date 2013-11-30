#include "LogicSystemImpl.h"
#include "ObjectQueue.h"
#include "Object.h"


using namespace cph;

LogicSystemImpl::LogicSystemImpl(std::uint8_t sysId) :
	logicAlloc(), sysId(sysId), errorLog("[ LogicSys ]"), debugLog("[ LogicSys ]")
{
	errorLog.setLocalConsolePrintOnLog(true);
}

LogicSystemImpl::~LogicSystemImpl() {

}

LogicComponent* LogicSystemImpl::createComponent() {
	LogicComponentImpl* comp =  logicAlloc.allocate();
	debugLog.pre() << "Created [LogicComponent= " << comp->getUniqueId() << "]" << std::endl;
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
	debugLog.pre() << "Destroyed [LogicComponent= " << component->getUniqueId() << "]" << std::endl;
	logicAlloc.release(component->getUniqueId());
}

