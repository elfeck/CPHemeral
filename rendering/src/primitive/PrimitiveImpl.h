#ifndef PRIMITIVE_IMPL_H_
#define PRIMITIVE_IMPL_H_

#include <string>
#include <vector>
#include <gl/glew.h>
#include "../../include/Primitive.h"

namespace cph {


class PrimitiveImpl : public Primitive {

protected:
	const std::uint32_t uniqueId;
	std::string name;

public:
	PrimitiveImpl(std::uint32_t uniqueId);
	virtual ~PrimitiveImpl() = 0;
	
	virtual std::uint32_t getUniqueId() const;
	virtual const char* getName() const;
	virtual void setName(const char* name);

	virtual void uploadAsUniformGL(GLuint program) = 0;
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const = 0;

};

}

#endif