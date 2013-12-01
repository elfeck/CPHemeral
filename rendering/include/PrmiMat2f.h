#ifndef PRMI_MAT2F_H_
#define PRMI_MAT2F_H_

#include <cstdint>
#include "Mat2f.h"
#include "Primitive.h"


namespace cph {

struct PrmiMat2f : public Primitive {
	
	virtual std::uint32_t getUniqueId() const = 0;
	virtual bool isLocal() const = 0;

	virtual Mat2f* wget() = 0;
	virtual const Mat2f* rget() const = 0;

};

}

#endif