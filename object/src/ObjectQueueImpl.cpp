#include "ObjectQueueImpl.h"


using namespace cph;

ObjectQueueImpl::ObjectQueueImpl() :
	objects()
{

}

ObjectQueueImpl::~ObjectQueueImpl() {

}

const Object* ObjectQueueImpl::pop() {
	const Object* obj = objects.back();
	objects.pop_back();
	return obj;
}

bool ObjectQueueImpl::hasElements() const {
	return objects.size() > 0;
}

void ObjectQueueImpl::push(const Object* obj) {
	objects.push_back(obj);
}

void ObjectQueueImpl::clear() {
	objects.clear();
}

