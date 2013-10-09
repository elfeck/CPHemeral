#ifndef VERTEX_ATTRIBUTE_H_
#define VERTEX_ATTRIBUTE_H_

#include <gl\glew.h>

#include "AttributeFormat.h"


namespace cph {

class VertexAttribute {

private:
	AttributeFormat format;

	GLsizei stride;
	GLint offset;
	GLboolean normalized;

public:
	VertexAttribute(AttributeFormat format, GLsizei stride = 0, GLint offset = 0, GLboolean normalized = GL_FALSE);
	~VertexAttribute();

	void bindVertexPointerGL();
	void bindAttribLociationGL(GLuint programHandle);

	GLuint getIndex() const;
	GLint getSize() const;
	int getByteSize() const;

	void setStride(GLsizei stride);
	void setOffset(GLint offset);

	bool operator<(const VertexAttribute& other) const;

};

}

#endif