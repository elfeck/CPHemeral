#ifndef VERTEX_H_
#define VERTEX_H_


namespace cph {

class Vecf;
class Matf;

struct Vertex {

	virtual void addAttributeVec(const char* name, Vecf* vec) = 0;
	virtual void addAttributeMat(const char* name, Matf* mat) = 0;
	virtual void removeAttribute(const char* name) = 0;

	virtual void addPrimitiveIndex(int index) = 0;
	virtual void removePrimitiveIndex(int index) = 0;

	virtual void destroy() = 0;
};

}

#endif