#ifndef CAMERA_H_
#define CAMERA_H_

#include "RenderUniform.h"
#include "Object.h"
#include "Logicable.h"
#include "LogicComponent.h"
#include "RenderingComponent.h"
#include "ObjectAllocator.h"
#include "PrmiVec3f.h"


namespace cph {

class Camera : Logicable {

private:
	float speed;

	cph::Object* object;
	cph::LogicComponent* logicComp;
	PrmiVec3f* camera;

	Camera(const Camera& other);

public:
	Camera();
	~Camera();

	virtual void doLogic(long delta);

	RenderUniform* addCameraAsUniform(RenderingComponent* comp); 

	void init(ObjectAllocator* alloc);
	void destroy();

};


}

#endif