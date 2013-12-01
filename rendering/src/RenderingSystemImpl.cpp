#include "RenderingSystemImpl.h"
#include "../include/ObjectQueue.h"
#include "../include/ObjectManager.h"
#include "../include/Object.h"


using namespace cph;

Logger RenderingSystemImpl::errorLog("[ RendrSys ]");
Logger RenderingSystemImpl::debugLog("[ RendrSys ]");

WriteonlyLogger& RenderingSystemImpl::getErrorLog() {
	return errorLog;
}

WriteonlyLogger& RenderingSystemImpl::getDebugLog() {
	return debugLog;
}

RenderingSystemImpl::RenderingSystemImpl(std::uint8_t id) :
	componentAlloc(), prmiAlloc(), renderAlloc(&prmiAlloc), sysId(id), vaoManager()
{
	errorLog.setLocalConsolePrintOnLog(true);
}

RenderingSystemImpl::RenderingSystemImpl(const RenderingSystemImpl& other) : sysId(other.sysId), renderAlloc(0) { }

RenderingSystemImpl::~RenderingSystemImpl() {

}

RenderingComponent* RenderingSystemImpl::createComponent() {
	RenderingComponentImpl* comp = componentAlloc.allocate();
	comp->setSystem(this);
	debugLog.pre() << "Created [RenderingComp= " << comp->getUniqueId() << "]" << std::endl;
	return comp;
}

PrmiVec1f* RenderingSystemImpl::createGlobalVec1f() {
	PrmiVec1fImpl* vec = prmiAlloc.allocPrmiVec1f();
	vec->setLocal(false);
	return vec;
}

PrmiVec2f* RenderingSystemImpl::createGlobalVec2f() {
	PrmiVec2fImpl* vec = prmiAlloc.allocPrmiVec2f();
	vec->setLocal(false);
	return vec;
}

PrmiVec3f* RenderingSystemImpl::createGlobalVec3f() {
	PrmiVec3fImpl* vec = prmiAlloc.allocPrmiVec3f();
	vec->setLocal(false);
	return vec;
}

PrmiVec4f* RenderingSystemImpl::createGlobalVec4f() {
	PrmiVec4fImpl* vec = prmiAlloc.allocPrmiVec4f();
	vec->setLocal(false);
	return vec;
}

PrmiMat2f* RenderingSystemImpl::createGlobalMat2f() {
	PrmiMat2fImpl* mat = prmiAlloc.allocPrmiMat2f();
	mat->setLocal(false);
	return mat;
}

PrmiMat3f* RenderingSystemImpl::createGlobalMat3f() {
	PrmiMat3fImpl* mat = prmiAlloc.allocPrmiMat3f();
	mat->setLocal(false);
	return mat;
}

PrmiMat4f* RenderingSystemImpl::createGlobalMat4f() {
	PrmiMat4fImpl* mat = prmiAlloc.allocPrmiMat4f();
	mat->setLocal(false);
	return mat;
}

void RenderingSystemImpl::destroyGlobalPrimitive(Primitive* prmi) {
	if(!prmi->isLocal()) {
		prmiAlloc.releasePrimitive(prmi);
	} else {
		getErrorLog().pre() << "Error trying to globally destroy local [Primitive= " << prmi->getUniqueId() << "]" << std::endl;
	}
}

std::uint8_t RenderingSystemImpl::getSysId() const {
	return sysId;
}

void RenderingSystemImpl::execute(ObjectManager* objectManager, long delta) {
	ObjectQueue* queue = objectManager->tempGetObjectsWith(sysId);
	RenderingComponentImpl* comp = 0;
	while(queue->hasElements()) {
		comp = componentAlloc.at(queue->pop()->getComponent(sysId)->getUniqueId());
		vaoManager.processVaoEntry(comp->getVaoEntry());
	}
	vaoManager.updateGL();
	vaoManager.drawGL();
}

void RenderingSystemImpl::setLog(Log* log, const char* target) {
	if(log != 0) {
		if(log->getTarget() == "error") errorLog.setLogPtr(log);
		if(log->getTarget() == "debug") debugLog.setLogPtr(log);
	} else if(target != 0) {
		if(strcmp(target, "error")) errorLog.setLogPtr(0);
		if(strcmp(target, "debug")) errorLog.setLogPtr(0);
	}
}

void RenderingSystemImpl::releaseComponent(RenderingComponentImpl* component) {
	debugLog.pre() << "Destroyed [RenderingComp= " << component->getUniqueId() << "]" << std::endl;
	vaoManager.cleanVaoEntry(component->getVaoEntry());
	componentAlloc.release(component->getUniqueId());
}

RenderAllocator* RenderingSystemImpl::getRenderAllocator() {
	return &renderAlloc;
}
