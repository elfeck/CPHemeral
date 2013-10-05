#include "RenderingSystemImpl.h"
#include "../include/ObjectQueue.h"


using namespace cph;

RenderingSystemImpl::RenderingSystemImpl(std::uint8_t id) :
	componentAlloc(), sysId(id), vaoManager()
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
		comp = componentAlloc.at(queue->pop()->getComponent(sysId)->getCompId());
		vaoManager.processVaoEntry(comp->getVaoEntry());
	}
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	vaoManager.cleanVaoEntry(component->getVaoEntry());
	componentAlloc.release(component->getCompId());
}