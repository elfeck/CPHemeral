#ifndef PRIMITIVE_IMPL_H_
#define PRIMITIVE_IMPL_H_

#include <string>
#include <vector>
#include <gl/glew.h>
#include "../../include/Primitive.h"

namespace cph {


class PrimitiveImpl : public Primitive {

protected:
	std::uint64_t parentId;
	const std::uint32_t prmiId;
	std::string name;

public:
	PrimitiveImpl(std::uint32_t prmiId);
	virtual ~PrimitiveImpl() = 0;
	
	virtual std::uint64_t getParentId() const;
	virtual std::uint32_t getPrmiId() const;
	virtual const char* getName() const;

	virtual void uploadAsUniformGL(GLuint program) = 0;
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const = 0;

	void checkAsUniformGL(GLuint program);

};

}

#endif