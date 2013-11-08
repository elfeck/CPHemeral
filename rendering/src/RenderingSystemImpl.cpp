#include "RenderingSystemImpl.h"
#include "../include/ObjectQueue.h"
#include "../include/ObjectManager.h"
#include "../include/Object.h"


using namespace cph;

Logger RenderingSystemImpl::errorLog;
Logger RenderingSystemImpl::debugLog;

WriteonlyLogger& RenderingSystemImpl::getErrorLog() {
	return errorLog;
}

WriteonlyLogger& RenderingSystemImpl::getDebugLog() {
	return debugLog;
}

RenderingSystemImpl::RenderingSystemImpl(std::uint8_t id) :
	componentAlloc(), renderAlloc(), sysId(id), vaoManager()
{
	errorLog.setLocalConsolePrintOnLog(true);
}

RenderingSystemImpl::~RenderingSystemImpl() {

}

RenderingComponent* RenderingSystemImpl::createComponent() {
	RenderingComponentImpl* comp = componentAlloc.allocate();
	comp->setSystem(this);
	comp->setSysId(sysId);
	debugLog << "[RenSys: created [renderingComp= " << comp->getUniqueId() << "]" << std::endl;
	return comp;
}

std::uint8_t RenderingSystemImpl::getSysId() const {
	return sysId;
}

void RenderingSystemImpl::execute(ObjectManager* objectManager, long delta) {
	ObjectQueue* queue = objectManager->tempGetObjectsWith(sysId);
	RenderingComponentImpl* comp = 0;
	while(queue->hasElements()) {
		comp = componentAlloc.at(queue->pop()->getComponent(sysId)->getUniqueId());
		vaoManager.processVaoEntry(comp->getVaoEntry());
	}
	vaoManager.updateGL();
	vaoManager.drawGL();
}

void RenderingSystemImpl::setLog(Log* log, const char* target) {
	if(log != 0) {
		if(log->getTarget() == "error") errorLog.setLogPtr(log);
		if(log->getTarget() == "debug") debugLog.setLogPtr(log);
	} else if(target != 0) {
		if(strcmp(target, "error")) errorLog.setLogPtr(0);
		if(strcmp(target, "debug")) errorLog.setLogPtr(0);
	}
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	debugLog << "[RenSys: destroyed [renderingComp= " << component->getUniqueId() << "]" << std::endl;
	vaoManager.cleanVaoEntry(component->getVaoEntry());
	componentAlloc.release(component->getUniqueId());

}

RenderAllocator* RenderingSystemImpl::getRenderAllocator() {
	return &renderAlloc;
}
