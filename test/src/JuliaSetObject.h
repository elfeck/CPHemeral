#ifndef JULIA_SET_OBJECT
#define JULIA_SET_OBJECT

#include "ObjectManager.h"
#include "RenderingComponent.h"
#include "Object.h"
#include "RenderingSystem.h"


class JuliaSetObject {

private:
	cph::Object* object;
	cph::RenderingComponent* render;

	cph::PrmiVec1f* zoom;
	cph::PrmiVec2f* c;
	cph::PrmiVec2f* camera;

public:
	JuliaSetObject();
	~JuliaSetObject();

	void create(cph::ObjectManager* scene, cph::RenderingSystem* sys);
	void destroy();

	bool isVisible();
	void setVisible(bool visible);
	
	void move(float dx, float dy);
	void doZoom(float margin);

	void switchConstant(int examp);

};


#endif