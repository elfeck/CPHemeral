#include "RenderingSystemImpl.h"
#include "../include/ObjectQueue.h"

#include "../include/Object.h"


using namespace cph;

Logger RenderingSystemImpl::errorLog;
Logger RenderingSystemImpl::debugLog;

RenderingSystemImpl::RenderingSystemImpl(std::uint8_t id) :
	componentAlloc(), renderAlloc(), sysId(id), vaoManager()
{

}

RenderingSystemImpl::~RenderingSystemImpl() {

}

RenderingComponent* RenderingSystemImpl::createComponent() {
	RenderingComponentImpl* comp = componentAlloc.allocate();
	comp->setSystem(this);
	comp->setSysId(sysId);
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

void RenderingSystemImpl::setLog(Log* log, const char* target = 0) {
	if(log != 0) {
		if(log->getTarget() == "error") ;
		if(log->getTarget() == "debug") ;
	} else if(target != 0) {
		if(strcmp(target, "error")) ;
		if(strcmp(target, "debug")) ;
	}
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	vaoManager.cleanVaoEntry(component->getVaoEntry());
	componentAlloc.release(component->getUniqueId());

}

RenderAllocator* RenderingSystemImpl::getRenderAllocator() {
	return &renderAlloc;
}
