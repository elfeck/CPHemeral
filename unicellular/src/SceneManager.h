#ifndef SCENE_MANAGER_H_
#define SCENE_MANAGER_H_

#include "MainScene.h"
#include "ObjectManager.h"


namespace cph {

class SceneManager {

private:
	MainScene mainScene;
	ObjectManager* currentManager;


public:
	SceneManager();
	~SceneManager();

	ObjectManager* getCurrentObjManager();

};

}


#endif