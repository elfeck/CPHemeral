#ifndef PRMI_VEC2F_IMPL_H_
#define PRMI_VEC2F_IMPL_H_

#include "../../include/PrmiVec2f.h"
#include "PrimitiveImpl.h"


namespace cph {

class PrmiVec2fImpl : public PrmiVec2f, public PrimitiveImpl {
	
private:
	Vec2f vector;

public:
	PrmiVec2fImpl(std::uint32_t uniqueId);
	~PrmiVec2fImpl();
	
	virtual std::uint32_t getUniqueId() const;
	virtual const char* getName() const;
	virtual void setName(const char* name);

	virtual void uploadAsUniformGL(GLuint program);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer) const;

	virtual Vec2f* get();

};

}


#endif