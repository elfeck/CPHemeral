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
#include <vector>


namespace cph {

class Player : public Logicable {

private:
	int sceneWidth, sceneHeight;
	float speed;
	Vec2f dest;

	Object* object;
	RenderingComponent* renderingComp;
	LogicComponent* logicComp;

	Camera* camera;

	std::vector<RenderVertex*> vertices;
	std::vector<RenderGeom*> geoms;

	PrmiVec2f* scale;
	PrmiVec2f* offset;

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