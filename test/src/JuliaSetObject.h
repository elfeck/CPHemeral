#ifndef JULIA_SET_OBJECT
#define JULIA_SET_OBJECT

#include "ObjectManager.h"
#include "RenderingSystem.h"


class JuliaSetObject {

private:
	cph::Object* object;
	cph::RenderingComponent* render;

	cph::PrmiVec1f* zoom;
	cph::PrmiVec2f* center;

public:
	JuliaSetObject();
	~JuliaSetObject();

	void create(cph::ObjectManager* scene, cph::RenderingSystem* sys);
	void destroy();

};


#endif