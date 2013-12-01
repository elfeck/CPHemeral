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
	virtual bool isLocal() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer);

	virtual Mat4f* wget();
	virtual const Mat4f* rget() const;

};

}


#endif