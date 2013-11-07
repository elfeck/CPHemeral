#include <iostream>
#include "GlobalUtils.h"
#include "VaoManager.h"
#include "ShaderProgram.h"
#include "../SystemLog.h"


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
				getDebugLog() << "[RenSys: Adding [entry= " << cutFilepath(entry->getShaderPath()) << "] to existing vao" << std::endl;
				break;
			}
		}
		if(!entry->isAdded() && fileExists(entry->getShaderPath() + ".vert") && fileExists(entry->getShaderPath() + ".frag")) {
			ShaderProgram shaderProgram(entry->getShaderPath());
			for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
				if(it->supportsShader(shaderProgram)) {
					it->addVaoEntry(entry, &shaderProgram);
					getDebugLog() << "[RenSys: Adding [entry= " << cutFilepath(entry->getShaderPath()) << "] to existing vao" << std::endl;
					break;
				}
			}
			if(!entry->isAdded()) {
				getDebugLog() << "[RenSys: Creating new vao for [entry= " << cutFilepath(entry->getShaderPath()) << "]" << std::endl;
				Vao* vao = vaoAlloc.allocate();
				vao->initGL(shaderProgram);
				getDebugLog() << "[RenSys: Adding entry to newly created vao" << std::endl;
				vao->addVaoEntry(entry);
			}
		} else {
			getErrorLog() << "[RenSys: Invalid shader path: " << entry->getShaderPath() << std::endl;
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

void VaoManager::updateGL() {
	for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
		it->updateGL();
	}
}

void VaoManager::drawGL() {
	for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
		it->drawGL();
	}
}