#ifndef RENDERING_SYSTEM_IMPL_H_
#define RENDERING_SYSTEM_IMPL_H_

#include "opengl/VaoManager.h"
#include "opengl/VaoEntry.h"
#include "../include/RenderingSystem.h"

#include "SingleAllocator.h"
#include "SingleIdAllocator.h"
#include "VertexImpl.h"
#include "RenderingComponentImpl.h"


namespace cph {

class RenderingSystemImpl : public RenderingSystem {

private:
	SingleIdAllocator<RenderingComponentImpl> componentAlloc;

	VaoManager vaoManager;

public:
	RenderingSystemImpl();
	~RenderingSystemImpl();

	virtual RenderingComponent* createComponent();
	virtual void execute(ObjectManager* objectManager, long delta);

	void releaseComponent(RenderingComponentImpl* component);

};

}

#endif