#ifndef RENDER_UNIFORM_IMPL_H_
#define RENDER_UNIFORM_IMPL_H_

#include <map>
#include <vector>
#include <gl/glew.h>
#include "primitive/PrimitiveImpl.h"
#include "../include/RenderUniform.h"


namespace cph {

class RenderUniformImpl : public RenderUniform {

private:
	const std::uint32_t uniId;

public:
	RenderUniformImpl(std::uint32_t uniId);
	~RenderUniformImpl();

	virtual void addPrimitive(Primitive* prmi);
	virtual void removePrimitive(Primitive* prmi);

	virtual std::uint32_t getUniId() const;

	void uploadUniformGL(GLuint program);

};

}

#endif