#ifndef PRMI_MAT4F_H_
#define PRMI_MAT4F_H_

#include <cstdint>
#include "Mat4f.h"
#include "Primitive.h"


namespace cph {

struct PrmiMat4f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;

	virtual Mat4f* get() = 0;

};

}

#endif