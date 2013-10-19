#ifndef PRMI_MAT3F_H_
#define PRMI_MAT3F_H_

#include <cstdint>
#include "Mat3f.h"
#include "Primitive.h"


namespace cph {

struct PrmiMat3f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;

	virtual Mat3f* get() = 0;

};

}

#endif