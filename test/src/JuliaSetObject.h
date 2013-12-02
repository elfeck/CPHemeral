#ifndef JULIA_SET_OBJECT
#define JULIA_SET_OBJECT

#include "ObjectManager.h"
#include "RenderingComponent.h"
#include "Object.h"
#include "RenderingAllocator.h"
#include "LogicAllocator.h"
#include "PrmiVec1f.h"
#include "PrmiVec2f.h"
#include "LogicComponent.h"
#include "Logicable.h"


class JuliaSetObject : public cph::Logicable {

private:
	cph::Object* object;
	cph::RenderingComponent* render;
	cph::LogicComponent* logic;

	cph::PrmiVec1f* zoom;
	cph::PrmiVec2f* c;
	cph::PrmiVec2f* camera;

public:
	JuliaSetObject();
	~JuliaSetObject();

	virtual void doLogic(double delta);

	void create(cph::ObjectManager* scene, cph::RenderingAllocator* render, cph::LogicAllocator* logic);
	void destroy();

	bool isVisible();
	void setVisible(bool visible);
	
	void move(float dx, float dy);
	void doZoom(float margin);

	void switchConstant(int examp);

};


#endif