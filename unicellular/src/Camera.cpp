#include "Camera.h"
#include "Unicellular.h"
#include <iostream>

using namespace cph;

Camera::Camera(int sceneWidth, int sceneHeight) :
	sceneWidth(sceneWidth), sceneHeight(sceneHeight), speed(0.1f), object(0), logicComp(0), camera(0)
{

}

Camera::~Camera() {

}

void Camera::initMvpMatrix() {
	std::vector<float> column;
	column.push_back(2.0f / sceneWidth);
	column.push_back(0);
	column.push_back(0);
	column.push_back(0);
	mvpMatrix->wget()->setColumn(0, column);
	column.at(0) = 0;
	column.at(1) = 2.0f / sceneHeight;
	mvpMatrix->wget()->setColumn(1, column);
	column.at(1) = 0;
	column.at(2) = 1.0f;
	mvpMatrix->wget()->setColumn(2, column);
	column.at(2) = 0;
	column.at(3) = 1.0f;
	mvpMatrix->wget()->setColumn(3, column);
 }

void Camera::doLogic(long delta) {
	if(getInput()->isKeyPressed(Key::W)) camera->wget()->addVec3f(0.0f, -speed * delta, 0.0f);
	if(getInput()->isKeyPressed(Key::A)) camera->wget()->addVec3f(speed * delta, 0.0f, 0.0f);
	if(getInput()->isKeyPressed(Key::S)) camera->wget()->addVec3f(0.0f, speed * delta, 0.0f);
	if(getInput()->isKeyPressed(Key::D)) camera->wget()->addVec3f(-speed * delta, 0.0f, 0.0f);
}

RenderUniform* Camera::addCameraAsUniform(RenderingComponent* comp) {
	RenderUniform* uniform = comp->addUniform();
	uniform->addGlobalVec3f("camera", camera);
	return uniform;
}

RenderUniform* Camera::addMvpMatrixAsUniform(RenderingComponent* comp) {
	RenderUniform* uniform = comp->addUniform();
	uniform->addGlobalMat4f("mvp_matrix", mvpMatrix);
	return uniform;
}


const Vec3f* Camera::getCamera() const {
	return camera->rget();
}

const Mat4f* Camera::getMvpMatirx() const {
	return mvpMatrix->rget();
}

void Camera::init(ObjectAllocator* alloc) {
	object = alloc->createObject();
	logicComp = getComponentAllocator().getLogicAllocator()->createComponent();
	logicComp->setLogicable(this);
	object->addComponent(logicComp);
	camera = getComponentAllocator().getRenderingAllocator()->createGlobalVec3f();
	mvpMatrix = getComponentAllocator().getRenderingAllocator()->createGlobalMat4f();
	initMvpMatrix();
}

void Camera::destroy() {
	getComponentAllocator().getRenderingAllocator()->destroyGlobalPrimitive(camera);
	getComponentAllocator().getRenderingAllocator()->destroyGlobalPrimitive(mvpMatrix);
	logicComp->destroy();
	object->destroy();
}