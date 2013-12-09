#include "MainScene.h"
#include "Unicellular.h"


using namespace cph;

MainScene::MainScene() :
	objectManager(createObjectManager()), sceneWidth(getDisplayWidth()), sceneHeight(getDisplayHeight()), 
	 camera(getDisplayWidth(), getDisplayHeight()), 
	 player(getDisplayWidth(), getDisplayHeight()), 
	 env(getDisplayWidth(), getDisplayHeight())
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
	env.init(camera, objectManager);
	player.init(camera, objectManager);
}

void MainScene::destroy() {
	player.destroy();
	env.destroy();
	camera.destroy();
	deleteObjectManager(objectManager);
}

int MainScene::getSceneWidth() const {
	return sceneWidth;
}

int MainScene::getSceneHeight() const {
	return sceneHeight;
}
