#ifndef PRIMITIVE_IMPL_H_
#define PRIMITIVE_IMPL_H_

#include <string>
#include <vector>
#include <gl/glew.h>
#include "../../include/Primitive.h"

namespace cph {


class PrimitiveImpl : public Primitive {

private:
	bool local;

protected:
	const std::uint32_t uniqueId;
	bool modified;

public:
	PrimitiveImpl(std::uint32_t uniqueId);
	virtual ~PrimitiveImpl() = 0;
	
	virtual std::uint32_t getUniqueId() const;
	virtual bool isLocal() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name) = 0;
	virtual void fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset) = 0;

	void setLocal(bool local);

	bool wasModified() const;

};

}

#endif