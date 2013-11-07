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

	virtual void uploadAsUniformGL(GLuint program, std::string name);
	virtual void fetchVertexData(std::vector<GLfloat>& buffer);

	virtual Vec2f* wget();
	virtual const Vec2f* rget() const;

};

}


#endif