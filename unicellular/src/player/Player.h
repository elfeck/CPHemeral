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
	Object* object;

	RenderingComponent* renderingComp;
	LogicComponent* logicComp;

	std::vector<RenderVertex*> vertices;
	RenderGeom* rGeom1, *rGeom2;
	RenderUniform* scaleUniform;

	void initGeom();

public:
	Player(int sceneWidth, int sceneHeight);
	~Player();

	virtual void doLogic(long delta);
	
	void init(Camera& camera, ObjectAllocator* objAlloc);
	void destroy();

};

}

#endif