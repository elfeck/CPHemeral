#include "GlobalUtils.h"

#include "VaoManager.h"
#include "ShaderProgram.h"


using namespace cph;

VaoManager::VaoManager() :
	vaoAlloc()
{

}

VaoManager::~VaoManager() {

}

void VaoManager::processVaoEntry(VaoEntry* entry) {
	if(!entry->isAdded()) {
		for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
			if(it->hasShader(entry->getShaderPath())) {
				it->addVaoEntry(entry);
				return;
			}
		}
		if(fileExists(entry->getShaderPath() + ".vert") && fileExists(entry->getShaderPath() + ".frag")) {
			ShaderProgram shaderProgram(entry->getShaderPath());
			// ~
			entry->setAdded(true);
		}
	}
}

void VaoManager::cleanVaoEntry(VaoEntry* entry) {
	for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
		if(it->hasShader(entry->getShaderPath())) {
			it->removeVaoEntry(entry);
			break;
		}
	}
}

void VaoManager::drawGL() {
	for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
		it->drawGL();
	}
}