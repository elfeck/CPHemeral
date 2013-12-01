#include "Camera.h"
#include "Unicellular.h"
#include "Display.h"

using namespace cph;

Camera::Camera() :
	speed(0.001f), object(0), logicComp(0), camera(0)
{

}

Camera::~Camera() {

}

void Camera::doLogic(long delta) {
	if(getInput()->isKeyPressed(Key::W)) camera->wget()->addVec3f(0.0f, speed * delta, 0.0f);
	if(getInput()->isKeyPressed(Key::A)) camera->wget()->addVec3f(-speed * delta, 0.0f, 0.0f);
	if(getInput()->isKeyPressed(Key::S)) camera->wget()->addVec3f(0.0f, -speed * delta, 0.0f);
	if(getInput()->isKeyPressed(Key::D)) camera->wget()->addVec3f(speed * delta, 0.0f, 0.0f);
}

RenderUniform* Camera::addCameraAsUniform(RenderingComponent* comp) {
	RenderUniform* uniform = comp->addUniform();
	uniform->addGlobalVec3f("camera", camera);
	return uniform;
}

void Camera::init(ObjectAllocator* alloc) {
	object = alloc->createObject();
	logicComp = getComponentAllocator().getLogicAllocator()->createComponent();
	logicComp->setLogicable(this);
	object->addComponent(logicComp);
	camera = getComponentAllocator().getRenderingAllocator()->createGlobalVec3f();
}

void Camera::destroy() {
	getComponentAllocator().getRenderingAllocator()->destroyGlobalPrimitive(camera);
	logicComp->destroy();
	object->destroy();
}