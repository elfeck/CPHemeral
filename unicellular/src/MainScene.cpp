#include "MainScene.h"
#include "Unicellular.h"


using namespace cph;

MainScene::MainScene() :
	objectManager(createObjectManager()), player()
{

}

MainScene::~MainScene() {
}

ObjectManager* MainScene::getObjectManager() {
	return objectManager;
}

void MainScene::init() {
	setLog(objectManager);
	player.init(objectManager);
}

void MainScene::destroy() {
	player.destroy();
	deleteObjectManager(objectManager);
}
