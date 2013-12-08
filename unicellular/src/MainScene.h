#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "CPHObject.h"
#include "player/Player.h"
#include "env/Environment.h"
#include "Camera.h"


namespace cph {

class MainScene {

private:
	ObjectManager* objectManager;
	int sceneWidth, sceneHeight;
	
	Camera camera;
	Player player;
	Environment env;

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