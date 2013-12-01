#ifndef PRMI_MAT2F_IMPL_H_
#define PRMI_MAT2F_IMPL_H_

#include "../../include/PrmiMat2f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiMat2fImpl : public PrmiMat2f, public PrimitiveImpl {
	
private:
	Mat2f matrix;

public:
	PrmiMat2fImpl(std::uint32_t uniqueId);
	~PrmiMat2fImpl();
	
	virtual std::uint32_t getUniqueId() const;
	virtual bool isLocal() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer);

	virtual Mat2f* wget();
	virtual const Mat2f* rget() const;

};

}


#endif