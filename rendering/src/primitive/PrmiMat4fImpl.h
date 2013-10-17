#ifndef PRMI_MAT4F_IMPL_H_
#define PRMI_MAT4F_IMPL_H_

#include "../../include/PrmiMat4f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiMat4fImpl : public PrmiMat4f, public PrimitiveImpl {
	
private:
	Mat4f matrix;

public:
	PrmiMat4fImpl(std::uint32_t uniqueId);
	~PrmiMat4fImpl();
	
	virtual std::uint32_t getUniqueId() const;
	virtual const char* getName() const;
	virtual void setName(const char* name);

	virtual void uploadAsUniformGL(GLuint program);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const;

	virtual Mat4f* get();

};

}


#endif