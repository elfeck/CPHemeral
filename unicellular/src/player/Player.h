#ifndef PLAYER_H_
#define PLAYER_H_

#include "Object.h"
#include "RenderingComponent.h"
#include "LogicComponent.h"
#include "ObjectAllocator.h"
#include "Logicable.h"
#include "../ComponentAllocator.h"


namespace cph {

class Player : public Logicable {

private:
	Object* object;
	RenderingComponent* renderingComp;
	LogicComponent* logicComp;

public:
	Player();
	~Player();

	virtual void doLogic(long delta);
	
	void init(ObjectAllocator* objAlloc);
	void destroy();

};

}

#endif