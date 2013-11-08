#ifndef MAIN_SCENE_H_
#define MAIN_SCENE_H_

#include "ObjectManager.h"


namespace cph {

class MainScene {

private:
	ObjectManager* objectManager;

public:
	MainScene();
	~MainScene();

	ObjectManager* getObjectManager();

};

}

#endif