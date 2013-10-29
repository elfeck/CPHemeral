#ifndef NOISE_OBJECT_H_
#define NOISE_OBJECT_H_

#include "ObjectManager.h"
#include "RenderingComponent.h"
#include "Object.h"
#include "RenderingSystem.h"


class NoiseObject {

private:
	cph::Object* object;
	cph::RenderingComponent* render;

public:
	NoiseObject();
	~NoiseObject();

	void create(cph::ObjectManager* scene, cph::RenderingSystem* sys);
	void destroy();

};


#endif