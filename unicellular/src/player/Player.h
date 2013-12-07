#ifndef PLAYER_H_
#define PLAYER_H_

#include "../ComponentAllocator.h"
#include "../Camera.h"
#include "Object.h"
#include "RenderingComponent.h"
#include "LogicComponent.h"
#include "ObjectAllocator.h"
#include "Logicable.h"
#include "RenderVertex.h"
#include "RenderGeom.h"
#include "RenderUniform.h"
#include "PrmiVec2f.h"
#include "Vec2f.h"
#include <vector>


namespace cph {

class Player : public Logicable {

private:
	Object* object;
	RenderingComponent* renderingComp;
	LogicComponent* logicComp;

	int sceneWidth, sceneHeight;

	Camera* camera;

	std::vector<RenderVertex*> vertices;
	std::vector<RenderGeom*> geoms;
	
	PrmiVec2f* scale;
	PrmiVec2f* offset;

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