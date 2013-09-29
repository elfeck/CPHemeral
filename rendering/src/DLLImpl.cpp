#include "../include/RenderingSystem.h"

#include "RenderingSystemImpl.h"


cph::RenderingSystem* cph::createRenderingSystem(int size) {
	return new RenderingSystemImpl(size);
}

void cph::deleteRenderingSystem(cph::RenderingSystem* renderingSystem) {
	delete renderingSystem;
}

virtual cph::RenderingSystem::~RenderingSystem() {

}

