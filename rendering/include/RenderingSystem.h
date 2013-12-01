#ifndef RENDERING_SYSTEM_H_
#define RENDERING_SYSTEM_H_

#ifdef RENDERING_EXPORTS
#define CPH_RENDERING_DLL _declspec(dllexport)
#else
#define CPH_RENDERING_DLL _declspec(dllimport)
#endif

#include "ObjectSystem.h"
#include "RenderingAllocator.h"


namespace cph {

struct ObjectManager;
struct RenderingComponent;
struct RenderUniform;
class Log;

struct RenderingSystem : public RenderingAllocator, public ObjectSystem {

	virtual RenderingComponent* createComponent() = 0;

	virtual PrmiVec1f* createGlobalVec1f() = 0;
	virtual PrmiVec2f* createGlobalVec2f() = 0;
	virtual PrmiVec3f* createGlobalVec3f() = 0;
	virtual PrmiVec4f* createGlobalVec4f() = 0;
	virtual PrmiMat2f* createGlobalMat2f() = 0;
	virtual PrmiMat3f* createGlobalMat3f() = 0;
	virtual PrmiMat4f* createGlobalMat4f() = 0;

	virtual void destroyGlobalPrimitive(Primitive* prmi) = 0;

	virtual std::uint8_t getSysId() const = 0;
	virtual void execute(ObjectManager* objectManager, long delta) = 0;

	virtual void setLog(Log* log, const char* target = 0) = 0;

	virtual ~RenderingSystem() = 0;

};

extern "C" {
	CPH_RENDERING_DLL RenderingSystem* createRenderingSystem(std::uint8_t sysId);
	CPH_RENDERING_DLL void deleteRenderingSystem(RenderingSystem* renderingSystem);
}

}

#endif