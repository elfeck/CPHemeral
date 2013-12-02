#ifndef CAMERA_H_
#define CAMERA_H_

#include "RenderUniform.h"
#include "Object.h"
#include "Logicable.h"
#include "LogicComponent.h"
#include "RenderingComponent.h"
#include "ObjectAllocator.h"
#include "Vec2f.h"
#include "PrmiVec3f.h"
#include "PrmiMat4f.h"


namespace cph {

class Camera : public Logicable {

private:
	int sceneWidth, sceneHeight;
	float speed;
	Vec2f slideDirection, slideFactor;

	Object* object;
	LogicComponent* logicComp;

	PrmiVec3f* camera;
	PrmiMat4f* mvpMatrix;

	Camera(const Camera& other);

	void initMvpMatrix();
	void computeMovement(long delta);
	void computeSlide(long delta);

public:
	Camera(int sceneWidth, int sceneHeight);
	~Camera();

	virtual void doLogic(long delta);

	RenderUniform* addCameraAsUniform(RenderingComponent* comp);
	RenderUniform* addMvpMatrixAsUniform(RenderingComponent* comp);

	const Vec3f* getCamera() const;
	const Mat4f* getMvpMatirx() const;

	void init(ObjectAllocator* alloc);
	void destroy();

};


}

#endif