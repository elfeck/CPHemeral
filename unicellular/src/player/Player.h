#ifndef PLAYER_H_
#define PLAYER_H_

#include "Object.h"
#include "RenderingComponent.h"
#include "LogicComponent.h"
#include "ObjectAllocator.h"
#include "Logicable.h"
#include "RenderVertex.h"
#include "RenderGeom.h"
#include "../ComponentAllocator.h"
#include <vector>


namespace cph {

class Player : public Logicable {

private:
	Object* object;

	RenderingComponent* renderingComp;
	std::vector<RenderVertex*> vertices;
	RenderGeom* rGeom1, *rGeom2;

	LogicComponent* logicComp;

	void initGeom();

public:
	Player();
	~Player();

	virtual void doLogic(long delta);
	
	void init(ObjectAllocator* objAlloc);
	void destroy();

};

}

#endif