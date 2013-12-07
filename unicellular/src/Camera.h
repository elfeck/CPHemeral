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
	Object* object;
	LogicComponent* logicComp;

	int sceneWidth, sceneHeight;
	float speed;
	Vec2f slideDirection, slideFactor;

	PrmiVec3f* camera;
	PrmiMat4f* mvpMatrix;

	Camera(const Camera& other);

	void initMvpMatrix();
	void computeMovement(double delta);
	void computeSlide(double delta);

public:
	Camera(int sceneWidth, int sceneHeight);
	~Camera();

	virtual void doLogic(double delta);

	RenderUniform* addCameraAsUniform(RenderingComponent* comp);
	RenderUniform* addMvpMatrixAsUniform(RenderingComponent* comp);

	const Vec3f* getCamera() const;
	const Mat4f* getMvpMatirx() const;

	void init(ObjectAllocator* alloc);
	void destroy();

};


}

#endif