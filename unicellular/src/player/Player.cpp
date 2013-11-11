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
	renderingComp = getComponentAllocator().getRenderingAllocator()->createComponent();
	logicComp = getComponentAllocator().getLogicAllocator()->createComponent();
}

void Player::destroy() {
	object->destroy();
	renderingComp->destroy();
	logicComp->destroy();
}
