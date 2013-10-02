#include "../include/RenderingSystem.h"

#include "RenderingSystemImpl.h"


cph::RenderingSystem* cph::createRenderingSystem() {
	return new RenderingSystemImpl();
}

void cph::deleteRenderingSystem(cph::RenderingSystem* renderingSystem) {
	delete renderingSystem;
}

cph::RenderingSystem::~RenderingSystem() {

}

