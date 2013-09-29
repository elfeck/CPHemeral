#include "RenderingSystemImpl.h"


using namespace cph;

RenderingSystemImpl::RenderingSystemImpl(int size) :
	componentArray(new RenderingComponentImpl[size]), componentPool(size)
{

}

RenderingSystemImpl::~RenderingSystemImpl() {
	delete[] componentArray;
}

void RenderingSystemImpl::execute(long delta) {
	// Render VAOs directly
}

RenderingComponent* RenderingSystemImpl::createComponent() {
	if(componentPool.isEmpty()) return 0;
	return &componentArray[componentPool.aquire()];
}

void RenderingSystemImpl::releaseId(int id) {
	componentPool.release(id);
}
