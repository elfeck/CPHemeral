#include "MainScene.h"


using namespace cph;

MainScene::MainScene() :
	objectManager(createObjectManager())
{

}

MainScene::~MainScene() {
	deleteObjectManager(objectManager);
}

ObjectManager* MainScene::getObjectManager() {
	return objectManager;
}
