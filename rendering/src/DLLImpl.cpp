#include "../include/RenderingSystem.h"

#include "RenderingSystemImpl.h"


cph::RenderingSystem* cph::createRenderingSystem(std::uint8_t sysId) {
	return new RenderingSystemImpl(sysId);
}

void cph::deleteRenderingSystem(cph::RenderingSystem* renderingSystem) {
	delete renderingSystem;
}

cph::RenderingSystem::~RenderingSystem() {

}

