#ifndef VERTEX_IMPL_H_
#define VERTEX_IMPL_H_

#include <map>
#include <vector>
#include <string>
#include <Vecf.h>
#include <Matf.h>

#include "../include/Vertex.h"


namespace cph {

class VertexImpl : public Vertex {

private:
	const int id;
	std::map<std::string, Vecf*> vecAttribs;
	std::map<std::string, Matf*> matAttribs;
	std::vector<int> primitiveIndices;

public:
	VertexImpl(int id);
	~VertexImpl();

	virtual void addAttributeVec(const char* name, Vecf* vec);
	virtual void addAttributeMat(const char* name, Matf* mat);
	virtual void removeAttribute(const char* name);

	virtual void addPrimitiveIndex(int index);
	virtual void removePrimitiveIndex(int index);

	virtual int getId() const;

};

}

#endif