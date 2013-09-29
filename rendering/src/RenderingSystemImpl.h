#ifndef RENDERING_SYSTEM_IMPL_H_
#define RENDERING_SYSTEM_IMPL_H_

#include "../include/RenderingSystem.h"
#include "../include/RenderingComponent.h"
#include "IntPool.h"

#include "RenderingComponentImpl.h"


namespace cph {

class RenderingSystemImpl : public RenderingSystem {

private:
	RenderingComponentImpl* componentArray;
	IntPool componentPool;

public:
	RenderingSystemImpl(int size);
	~RenderingSystemImpl();

	virtual void execute(long delta);
	virtual RenderingComponent* createComponent();

	void releaseId(int id);

};

}

#endif