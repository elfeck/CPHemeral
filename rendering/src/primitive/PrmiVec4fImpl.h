#ifndef PRMI_VEC4F_IMPL_H_
#define PRMI_VEC4F_IMPL_H_

#include "../../include/PrmiVec4f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiVec4fImpl : public PrmiVec4f, public PrimitiveImpl {
	
private:
	Vec4f vector;

public:
	PrmiVec4fImpl(std::uint32_t prmiId);
	~PrmiVec4fImpl();

	virtual std::uint64_t getParentId() const;
	virtual std::uint32_t getPrmiId() const;
	virtual const char* getName() const;

	virtual void uploadAsUniformGL(GLuint program);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const;

	virtual Vec4f* get();

};

}


#endif