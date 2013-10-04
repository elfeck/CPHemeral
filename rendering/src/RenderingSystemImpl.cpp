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
	while(queue->hasElements()) {
		queue->pop();
	}
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	componentAlloc.release(component->getCompId());
}