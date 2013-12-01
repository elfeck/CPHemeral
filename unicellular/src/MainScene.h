#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "ObjectManager.h"
#include "player/Player.h"
#include "Camera.h"


namespace cph {

class MainScene {

private:
	int sceneWidth, sceneHeight;

	ObjectManager* objectManager;
	Camera camera;
	Player player;

public:
	MainScene();
	~MainScene();

	ObjectManager* getObjectManager();

	void init();
	void destroy();

	int getSceneWidth() const;
	int getSceneHeight() const;
};

}

#endif