#include "../Unicellular.h"
#include "Player.h"


using namespace cph;

Player::Player() {

}

Player::~Player() {

}

void Player::doLogic(long delta) {

}

void Player::init(ObjectAllocator* objAlloc) {
	object = objAlloc->createObject();
	logicComp = getComponentAllocator().getLogicAllocator()->createComponent();
	
	renderingComp = getComponentAllocator().getRenderingAllocator()->createComponent();
	renderingComp->setShader(getAbsolutePath().append("/shader/Player").c_str());
	renderingComp->setVisible(true);
	initGeom();

	object->addComponent(renderingComp);
	object->addComponent(logicComp);
}

void Player::initGeom() {
	rGeom1 = renderingComp->addLocalGeom();
	rGeom2 = renderingComp->addLocalGeom();
	vertices.push_back(renderingComp->addLocalVertex());
	vertices.push_back(renderingComp->addLocalVertex());
	vertices.push_back(renderingComp->addLocalVertex());
	vertices.push_back(renderingComp->addLocalVertex());
	vertices.at(0)->addVec4f("vert_position", -1.0f, 1.0f, 0.0f, 1.0f);
	vertices.at(1)->addVec4f("vert_position", -1.0f, -1.0f, 0.0f, 1.0f);
	vertices.at(2)->addVec4f("vert_position", 1.0f, -1.0f, 0.0f, 1.0f);
	vertices.at(3)->addVec4f("vert_position", 1.0f, 1.0f, 0.0f, 1.0f);
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
