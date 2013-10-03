#ifndef UNIFORM_H_
#define UNIFORM_H_


namespace cph {

class Vecf;
class Matf;

struct Uniform {

	virtual void addUniformVec(const char* name, Vecf* vec) = 0;
	virtual void addUniformMat(const char* name, Matf* mat) = 0;
	virtual void removeUniform(const char* name) = 0;

	virtual int getId() const = 0;

};

}

#endif