#ifndef UNIFORM_IMPL_H_
#define UNIFORM_IMPL_H_

#include <map>
#include "Vecf.h"
#include "Matf.h"

#include "../include/Uniform.h"


namespace cph {

class RenderingComponentImpl;

class UniformImpl : public Uniform {

private:
	std::map<std::string, Vecf*> vecUniforms;
	std::map<std::string, Matf*> matUniforms;

	RenderingComponentImpl* component;

public:
	UniformImpl();
	~UniformImpl();

	virtual void addUniformVec(const char* name, Vecf* vec);
	virtual void addUniformMat(const char* name, Matf* mat);
	virtual void removeUniform(const char* name);

	virtual void destroy();

	void setComponent(RenderingComponentImpl* component);

};

}

#endif