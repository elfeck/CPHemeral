#ifndef PRMI_MAT2F_H_
#define PRMI_MAT2F_H_

#include <cstdint>
#include "Mat2f.h"
#include "Primitive.h"


namespace cph {

struct PrmiMat2f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;
	virtual const char* getName() const = 0;
	virtual void setName(const char* name) = 0;

	virtual Mat2f* get() = 0;

};

}

#endif