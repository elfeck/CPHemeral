#include "../Unicellular.h"
#include "Player.h"
#include <iostream>

using namespace cph;

Player::Player(int sceneWidth, int sceneHeight) :
	sceneWidth(sceneWidth), sceneHeight(sceneHeight), destination(), movementFinished(true), speed(0.1f)
{

}

Player::~Player() {

}

void Player::doLogic(double delta) {
	move(delta);

}

void Player::move(double delta) {	
	if(getKeybindings().isKeyReleased(Bindings::PLAYER_MOVE)) {
		destination.setX(getKeybindings().getMouseX() - 0.5f * sceneWidth - camera->getCamera()->getX());
		destination.setY(-1.0f * getKeybindings().getMouseY() + 0.5f * sceneHeight - camera->getCamera()->getY());
		movementFinished = false;
	}
	if(!movementFinished) {
		Vec2f step = *destination.copy().subVec2f(offset->rget());
		float dist = step.length();
		if(speed * delta > dist) {
			offset->wget()->setVec(destination);
			movementFinished = true;
		} else {
			offset->wget()->addVec2f(step.toLength(static_cast<float>(delta * speed)));
		}
	}
}


void Player::init(Camera& camera, ObjectAllocator* objAlloc) {
	this->camera = &camera;
	object = objAlloc->createObject();
	logicComp = getComponentAllocator().getLogicAllocator()->createComponent();
	logicComp->setLogicable(this);
	
	renderingComp = getComponentAllocator().getRenderingAllocator()->createComponent();
	renderingComp->setShader(getAbsolutePath().append("/shader/Player").c_str());
	scale = renderingComp->addUniform()->addLocalVec2f("scale", 10.0f, 10.0f);
	offset = renderingComp->addUniform()->addLocalVec2f("offset", 0.0f, 0.0f);
	camera.addCameraAsUniform(renderingComp);
	camera.addMvpMatrixAsUniform(renderingComp);
	
	initGeom();

	renderingComp->setVisible(true);
	object->addComponent(renderingComp);
	object->addComponent(logicComp);
}

void Player::initGeom() {
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.at(0)->addLocalVec4f("vert_position", 0.0f, 1.0f, 0.4f, 1.0f);
	vertices.at(1)->addLocalVec4f("vert_position", 0.0f, 0.0f, 0.4f, 1.0f);
	vertices.at(2)->addLocalVec4f("vert_position", 1.0f, 0.0f, 0.4f, 1.0f);
	vertices.at(3)->addLocalVec4f("vert_position", 1.0f, 1.0f, 0.4f, 1.0f);
	geoms.push_back(renderingComp->addGeom());
	geoms.push_back(renderingComp->addGeom());
	geoms.at(0)->addVertex(vertices.at(0));
	geoms.at(0)->addVertex(vertices.at(1));
	geoms.at(0)->addVertex(vertices.at(2));
	geoms.at(1)->addVertex(vertices.at(2));
	geoms.at(1)->addVertex(vertices.at(3));
	geoms.at(1)->addVertex(vertices.at(0));
}

void Player::destroy() {
	object->destroy();
	renderingComp->destroy();
	logicComp->destroy();
}
