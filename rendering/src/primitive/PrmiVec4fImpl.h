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
	virtual bool isLocal() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer);

	virtual Vec4f* wget();
	virtual const Vec4f* rget() const;

};

}


#endif