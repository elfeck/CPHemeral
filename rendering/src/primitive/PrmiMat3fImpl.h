#ifndef PRMI_MAT3F_IMPL_H_
#define PRMI_MAT3F_IMPL_H_

#include "../../include/PrmiMat3f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiMat3fImpl : public PrmiMat3f, public PrimitiveImpl {
	
private:
	Mat3f matrix;

public:
	PrmiMat3fImpl(std::uint32_t uniqueId);
	~PrmiMat3fImpl();
	
	virtual std::uint32_t getUniqueId() const;
	virtual const char* getName() const;
	virtual void setName(const char* name);

	virtual void uploadAsUniformGL(GLuint program);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const;

	virtual Mat3f* get();

};

}


#endif