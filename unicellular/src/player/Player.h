#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "../ComponentAllocator.h"
#include "../Camera.h"
#include "CPHObject.h"
#include "CPHLogic.h"
#include "CPHRendering.h"


namespace cph {

class Player : public Logicable {

private:
	Object* object;
	RenderingComponent* renderingComp;
	LogicComponent* logicComp;
	std::vector<RenderVertex*> vertices;
	std::vector<RenderGeom*> geoms;
	PrmiVec2f* scale;
	PrmiVec2f* offset;

	int sceneWidth, sceneHeight;
	Camera* camera;
	Vec2f destination;
	bool movementFinished;
	float speed;

	void move(double delta);
	void initGeom();

public:
	Player(int sceneWidth, int sceneHeight);
	~Player();

	virtual void doLogic(double delta);
	
	void init(Camera& camera, ObjectAllocator* objAlloc);
	void destroy();

};

}

#endif