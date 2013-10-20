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


namespace cph {

class RenderingSystemImpl : public RenderingSystem {

private:
	SingleIdAllocator<RenderingComponentImpl> componentAlloc;
	RenderAllocator renderAlloc;

	const std::uint8_t sysId;

	VaoManager vaoManager;

public:
	RenderingSystemImpl(std::uint8_t id);
	~RenderingSystemImpl();

	virtual RenderingComponent* createComponent();
	virtual std::uint8_t getSysId() const;
	virtual void execute(ObjectManager* objectManager, long delta);

	void releaseComponent(RenderingComponentImpl* component);
	RenderAllocator* getRenderAllocator();

};

}

#endif