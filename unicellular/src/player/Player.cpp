#include "../Unicellular.h"
#include "Display.h"
#include "Player.h"
#include <iostream>

using namespace cph;

Player::Player(int sceneWidth, int sceneHeight) :
	sceneWidth(sceneWidth), sceneHeight(sceneHeight)
{

}

Player::~Player() {

}

void Player::doLogic(long delta) {

}

void Player::init(Camera& camera, ObjectAllocator* objAlloc) {
	object = objAlloc->createObject();
	logicComp = getComponentAllocator().getLogicAllocator()->createComponent();
	logicComp->setLogicable(this);
	
	renderingComp = getComponentAllocator().getRenderingAllocator()->createComponent();
	renderingComp->setShader(getAbsolutePath().append("/shader/Player").c_str());
	renderingComp->setVisible(true);
	initGeom();
	scaleUniform = renderingComp->addUniform();
	scaleUniform->addLocalVec2f("scale", 10.0f / sceneWidth, 10.0f / sceneHeight);
	camera.addCameraAsUniform(renderingComp);

	object->addComponent(renderingComp);
	object->addComponent(logicComp);
}

void Player::initGeom() {
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.at(0)->addLocalVec4f("vert_position", -1.0f, 1.0f, 0.0f, 1.0f);
	vertices.at(1)->addLocalVec4f("vert_position", -1.0f, -1.0f, 0.0f, 1.0f);
	vertices.at(2)->addLocalVec4f("vert_position", 1.0f, -1.0f, 0.0f, 1.0f);
	vertices.at(3)->addLocalVec4f("vert_position", 1.0f, 1.0f, 0.0f, 1.0f);
	rGeom1 = renderingComp->addGeom();
	rGeom2 = renderingComp->addGeom();
	rGeom1->addVertex(vertices.at(0));
	rGeom1->addVertex(vertices.at(1));
	rGeom1->addVertex(vertices.at(2));
	rGeom2->addVertex(vertices.at(2));
	rGeom2->addVertex(vertices.at(3));
	rGeom2->addVertex(vertices.at(0));
}

void Player::destroy() {
	object->destroy();
	renderingComp->destroy();
	logicComp->destroy();
}
