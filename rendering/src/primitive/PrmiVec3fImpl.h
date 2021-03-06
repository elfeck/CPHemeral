#ifndef PRMI_VEC3F_IMPL_H_
#define PRMI_VEC3F_IMPL_H_

#include "../../include/PrmiVec3f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiVec3fImpl : public PrmiVec3f, public PrimitiveImpl {
	
private:
	Vec3f vector;

public:
	PrmiVec3fImpl(std::uint32_t uniqueId);
	~PrmiVec3fImpl();
	
	virtual std::uint32_t getUniqueId() const;
	virtual bool isLocal() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset);

	virtual Vec3f* wget();
	virtual const Vec3f* rget() const;

};

}


#endif