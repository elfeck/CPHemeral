#ifndef UNIFORM_IMPL_H_
#define UNIFORM_IMPL_H_

#include <map>
#include <gl/glew.h>
#include "Vecf.h"
#include "Matf.h"

#include "../include/Uniform.h"


namespace cph {

class UniformImpl : public Uniform {

private:
	const int id;
	std::map<std::string, Vecf*> vecUniforms;
	std::map<std::string, Matf*> matUniforms;
	std::map<std::string, GLint> locations;

public:
	UniformImpl(int id);
	~UniformImpl();

	virtual void addUniformVec(const char* name, Vecf* vec);
	virtual void addUniformMat(const char* name, Matf* mat);
	virtual void removeUniform(const char* name);

	virtual int getId() const;
	
	void uploadGL(GLuint programHandle);

};

}

#endif