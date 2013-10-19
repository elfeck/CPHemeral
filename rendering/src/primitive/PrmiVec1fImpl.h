#ifndef PRMI_VEC1F_IMPL_H_
#define PRMI_VEC1F_IMPL_H_

#include "../../include/PrmiVec1f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiVec1fImpl : public PrmiVec1f, public PrimitiveImpl {
	
private:
	Vec1f vector;

public:
	PrmiVec1fImpl(std::uint32_t uniqueId);
	~PrmiVec1fImpl();
	
	virtual std::uint32_t getUniqueId() const;

	virtual void uploadAsUniformGL(GLuint program, std::string name);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const;

	virtual Vec1f* get();

};

}


#endif