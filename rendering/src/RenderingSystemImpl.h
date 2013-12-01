#ifndef RENDERING_SYSTEM_IMPL_H_
#define RENDERING_SYSTEM_IMPL_H_

#include "opengl/VaoManager.h"
#include "opengl/VaoEntry.h"
#include "../include/RenderingSystem.h"
#include "primitive/PrimitiveImpl.h"
#include "SingleIdAllocator.h"
#include "RenderAllocator.h"
#include "RenderingComponentImpl.h"
#include "RenderVertexImpl.h"
#include "RenderUniformImpl.h"
#include "Logger.h"


namespace cph {

class RenderingSystemImpl : public RenderingSystem {

private:
	SingleIdAllocator<RenderingComponentImpl> componentAlloc;
	
	PrimitiveAllocator prmiAlloc;
	RenderAllocator renderAlloc;

	const std::uint8_t sysId;
	VaoManager vaoManager;
	
	static Logger errorLog, debugLog;

	RenderingSystemImpl(const RenderingSystemImpl& other);

public:
	RenderingSystemImpl(std::uint8_t id);
	~RenderingSystemImpl();

	virtual RenderingComponent* createComponent();

	virtual PrmiVec1f* createGlobalVec1f();
	virtual PrmiVec2f* createGlobalVec2f();
	virtual PrmiVec3f* createGlobalVec3f();
	virtual PrmiVec4f* createGlobalVec4f();
	virtual PrmiMat2f* createGlobalMat2f();
	virtual PrmiMat3f* createGlobalMat3f();
	virtual PrmiMat4f* createGlobalMat4f();

	virtual void destroyGlobalPrimitive(Primitive* prmi);

	virtual std::uint8_t getSysId() const;
	virtual void execute(ObjectManager* objectManager, long delta);
	
	virtual void setLog(Log* log, const char* target);

	void releaseComponent(RenderingComponentImpl* component);
	RenderAllocator* getRenderAllocator();

	static WriteonlyLogger& getErrorLog();
	static WriteonlyLogger& getDebugLog();

};

}

#endif