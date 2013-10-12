#ifndef RENDERING_SYSTEM_IMPL_H_
#define RENDERING_SYSTEM_IMPL_H_

#include "opengl/VaoManager.h"
#include "opengl/VaoEntry.h"
#include "../include/RenderingSystem.h"

#include "SingleIdAllocator.h"
#include "RenderingComponentImpl.h"


namespace cph {

class RenderingSystemImpl : public RenderingSystem {

private:
	SingleIdAllocator<RenderingComponentImpl> componentAlloc;

	const std::uint8_t sysId;

	VaoManager vaoManager;

public:
	RenderingSystemImpl(std::uint8_t id);
	~RenderingSystemImpl();

	virtual RenderingComponent* createComponent();
	virtual std::uint8_t getSysId() const;
	virtual void execute(ObjectManager* objectManager, long delta);

	void releaseComponent(RenderingComponentImpl* component);

};

}

#endif