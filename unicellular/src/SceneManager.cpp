#include "SceneManager.h"


using namespace cph;

SceneManager::SceneManager() :
	mainScene()
{
	// show the main scene on startup (for now)
	currentManager = mainScene.getObjectManager();
}

SceneManager::~SceneManager() {

}


ObjectManager* SceneManager::getCurrentObjManager() {
	return currentManager;
}

void SceneManager::init() {
	mainScene.init();
}

void SceneManager::destroy() {
	mainScene.destroy();
}
