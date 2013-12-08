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

VaoManager::VaoManager(const VaoManager& other) { }

void VaoManager::processVaoEntry(VaoEntry* entry) {
	if(!entry->isAdded()) {
		for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
			if(it->hasShader(entry->getShaderPath())) {
				it->addVaoEntry(entry);
				getDebugLog().pre() << "Adding [VaoEntry= " << cutFilepath(entry->getShaderPath()) << "] to existing Vao (existing Shader)" << std::endl;
				break;
			}
		}
		if(!entry->isAdded() && fileExists(entry->getShaderPath() + ".vert") && fileExists(entry->getShaderPath() + ".frag")) {
			ShaderProgram shaderProgram(entry->getShaderPath());
			for(SingleAllocator<Vao>::iterator it = vaoAlloc.begin(); it != vaoAlloc.end(); ++it) {
				if(it->supportsShader(shaderProgram)) {
					it->addVaoEntry(entry, &shaderProgram);
					getDebugLog().pre() << "Adding [VaoEntry= " << cutFilepath(entry->getShaderPath()) << "] to existing Vao (new Shader)" << std::endl;
					break;
				}
			}
			if(!entry->isAdded()) {
				getDebugLog().pre() << "Creating new Vao for [VaoEntry= " << cutFilepath(entry->getShaderPath()) << "]" << std::endl;
				Vao* vao = vaoAlloc.allocate();
				vao->initGL(shaderProgram);
				getDebugLog().pre() << "Adding [VaoEntry= " << cutFilepath(entry->getShaderPath()) << "] to newly created Vao" << std::endl;
				vao->addVaoEntry(entry);
			}
		} else if(entry->getShaderPath() != VaoEntry::ERROR_PATH) {
			getErrorLog().pre() << "Invalid shader path: " << entry->getShaderPath() << std::endl;
			entry->setShader(VaoEntry::ERROR_PATH);
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