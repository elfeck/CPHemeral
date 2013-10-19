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

public:
	PrimitiveImpl(std::uint32_t uniqueId);
	virtual ~PrimitiveImpl() = 0;
	
	virtual std::uint32_t getUniqueId() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name) = 0;
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const = 0;

	bool isLocal();
	void setLocal(bool local);

};

}

#endif