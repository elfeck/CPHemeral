#ifndef PRMI_VEC4F_IMPL_H_
#define PRMI_VEC4F_IMPL_H_

#include "../../include/PrmiVec4f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiVec4fImpl : public PrmiVec4f, public PrimitiveImpl {
	
private:
	Vec4f vector;

public:
	PrmiVec4fImpl(std::uint32_t uniqueId);
	~PrmiVec4fImpl();
	
	virtual std::uint32_t getUniqueId() const;
	virtual const char* getName() const;
	virtual void setName(const char* name);

	virtual void uploadAsUniformGL(GLuint program);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const;

	virtual Vec4f* get();

};

}


#endif