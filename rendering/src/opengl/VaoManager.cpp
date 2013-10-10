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
				break;
			}
		}
		if(!entry->isAdded() && fileExists(entry->getShaderPath() + ".vert") && fileExists(entry->getShaderPath() + ".frag")) {
			ShaderProgram shaderProgram(entry->getShaderPath());
			for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
				if(it->supportsShader(shaderProgram)) {
					it->addVaoEntry(entry, &shaderProgram);
					break;
				}
			}
			if(!entry->isAdded()) {
				Vao* vao = vaoAlloc.allocate();
				vao->initGL(shaderProgram);
				vao->addVaoEntry(entry);
			}
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