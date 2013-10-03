#include "RenderingSystemImpl.h"


using namespace cph;

RenderingSystemImpl::RenderingSystemImpl() :
	componentAlloc(), vaoManager()
{

}

RenderingSystemImpl::~RenderingSystemImpl() {

}

RenderingComponent* RenderingSystemImpl::createComponent() {
	RenderingComponentImpl* comp = componentAlloc.allocate();
	comp->setSystem(this);
	return comp;
}

void RenderingSystemImpl::execute(ObjectManager* objectManager, long delta) {
	Object* currentObject = 0;
	RenderingComponentImpl* currentComponent = 0;
	for(int i = 0; i < objectManager->size(); i++) {
		currentObject = objectManager->at(i);
		if(currentObject->hasComponent("rendering")) {
			currentComponent = componentAlloc.at(currentObject->getComponent("rendering")->getId());
			// do stuff with it
		}
	}
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	componentAlloc.release(component->getId());
}