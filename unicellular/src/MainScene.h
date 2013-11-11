#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "ObjectManager.h"
#include "player/Player.h"


namespace cph {

class MainScene {

private:
	ObjectManager* objectManager;
	Player player;

public:
	MainScene();
	~MainScene();

	ObjectManager* getObjectManager();

	void init();
	void destroy();

};

}

#endif