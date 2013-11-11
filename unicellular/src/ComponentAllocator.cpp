#include "ComponentAllocator.h"


using namespace cph;

ComponentAllocator::ComponentAllocator() :
	renderAlloc(0), logicAlloc(0)
{

}

ComponentAllocator::~ComponentAllocator() {

}

void ComponentAllocator::setRenderAlloc(RenderingAllocator* alloc) {
	renderAlloc = alloc;
}

void ComponentAllocator::setLogicAlloc(LogicAllocator* alloc) {
	logicAlloc = alloc;
}

RenderingAllocator* ComponentAllocator::getRenderingAllocator() {
	return renderAlloc;
}

LogicAllocator* ComponentAllocator::getLogicAllocator() {
	return logicAlloc;
}
