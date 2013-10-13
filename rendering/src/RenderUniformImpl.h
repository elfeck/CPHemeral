#ifndef RENDER_UNIFORM_IMPL_H_
#define RENDER_UNIFORM_IMPL_H_

#include <map>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <gl/glew.h>
#include "primitive/PrimitiveImpl.h"
#include "../include/RenderUniform.h"


namespace cph {

class RenderUniformImpl : public RenderUniform {

private:
	const std::uint32_t uniqueId;
	
	std::map<std::uint32_t, PrimitiveImpl*> primitives;

	std::unordered_map<std::uint32_t, PrimitiveImpl*>* prmiLookupPtr;

public:
	RenderUniformImpl(std::uint32_t uniqueId);
	~RenderUniformImpl();

	virtual void addUniformPrimitive(Primitive* prmi);
	virtual void removeUniformPrimitive(Primitive* prmi);

	virtual std::uint32_t getUniqueId() const;

	void uploadUniformGL(GLuint program);

	void setPrmiLookupPtr(std::unordered_map<std::uint32_t, PrimitiveImpl*>* prmiLookupPtr);

};

}

#endif