#ifndef VERTEX_FORMAT_H_
#define VERTEX_FORMAT_H_

#include <map>
#include <set>
#include <gl\glew.h>

#include "VertexAttribute.h"


namespace cph {

class VertexFormat {

private:
	std::map<GLuint, VertexAttribute> attributes;

	void computeOffsets();

public:
	VertexFormat();
	~VertexFormat();

	void addVertexAttribute(VertexAttribute attrib);
	void removeVertexAttribute(VertexAttribute attrib);

	bool isCompatible(const std::set<AttributeFormat>& attributeFormat) const;
	void bindVertexAttributesGL() const;

};

}

#endif