#include "MainScene.h"
#include "Unicellular.h"


using namespace cph;

MainScene::MainScene() :
	sceneWidth(getDisplayWidth()), sceneHeight(getDisplayHeight()), objectManager(createObjectManager()), 
	 camera(), player(getDisplayWidth(), getDisplayHeight())
{

}

MainScene::~MainScene() {
}

ObjectManager* MainScene::getObjectManager() {
	return objectManager;
}

void MainScene::init() {
	setLog(objectManager);
	camera.init(objectManager);
	player.init(camera, objectManager);
}

void MainScene::destroy() {
	player.destroy();
	camera.destroy();
	deleteObjectManager(objectManager);
}

int MainScene::getSceneWidth() const {
	return sceneWidth;
}

int MainScene::getSceneHeight() const {
	return sceneHeight;
}
