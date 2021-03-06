#include "Camera.h"
#include "Unicellular.h"
#include <iostream>

using namespace cph;

Camera::Camera(int sceneWidth, int sceneHeight) :
	sceneWidth(sceneWidth), sceneHeight(sceneHeight), speed(0.4f), slideDirection(0.0f, 0.0f), slideFactor(0.0f, 0.0f),
	object(0), logicComp(0), camera(0)
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

void Camera::computeMovement(double delta) {
	if(getKeybindings().isKeyPressed(Bindings::CAMERA_UP)) camera->wget()->addVec3f(0.0f, -speed * delta, 0.0f);
	if(getKeybindings().isKeyPressed(Bindings::CAMERA_LEFT)) camera->wget()->addVec3f(speed * delta, 0.0f, 0.0f);
	if(getKeybindings().isKeyPressed(Bindings::CAMERA_DOWN)) camera->wget()->addVec3f(0.0f, speed * delta, 0.0f);
	if(getKeybindings().isKeyPressed(Bindings::CAMERA_RIGHT)) camera->wget()->addVec3f(-speed * delta, 0.0f, 0.0f);
}

void Camera::computeSlide(double delta) {
	if(getKeybindings().isKeyReleased(Bindings::CAMERA_UP)) {
		slideDirection.setY(-1.0f); 
		slideFactor.setY(1.0f);
	}
	if(getKeybindings().isKeyReleased(Bindings::CAMERA_LEFT)) {
		slideDirection.setX(1.0f); 
		slideFactor.setX(1.0f);
	}
	if(getKeybindings().isKeyReleased(Bindings::CAMERA_DOWN)) {
		slideDirection.setY(1.0f); 
		slideFactor.setY(1.0f);
	}
	if(getKeybindings().isKeyReleased(Bindings::CAMERA_RIGHT)) {
		slideDirection.setX(-1.0f); 
		slideFactor.setX(1.0f);
	}
	slideFactor.subVec2f(delta * 0.0025, delta * 0.0025);
	if(slideFactor.getX() < 0.000001f) slideFactor.setX(0.0f);
	if(slideFactor.getY() < 0.000001f) slideFactor.setY(0.0f);
	camera->wget()->addVec3f(slideDirection.getX() * speed * delta * slideFactor.getX(), 
		slideDirection.getY() * speed * delta * slideFactor.getY(), 0.0f);
}

void Camera::doLogic(double delta) {
	computeMovement(delta);
	computeSlide(delta);
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