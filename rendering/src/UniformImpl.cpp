#include "RenderingComponentImpl.h"

#include "UniformImpl.h"


using namespace cph;

UniformImpl::UniformImpl() :
	vecUniforms(), matUniforms(), component(0)
{

}

UniformImpl::~UniformImpl() {

}

void UniformImpl::addUniformVec(const char* name, Vecf* vec) {
	vecUniforms.insert(std::pair<std::string, Vecf*>(name, vec));
}

void UniformImpl::addUniformMat(const char* name, Matf* mat) {
	matUniforms.insert(std::pair<std::string, Matf*>(name, mat));
}

void UniformImpl::removeUniform(const char* name) {
	vecUniforms.erase(name);
	matUniforms.erase(name);
}

void UniformImpl::destroy() {
	component->removeUniform(this);
}

void UniformImpl::setComponent(RenderingComponentImpl* component) {
	this->component = component;
}
