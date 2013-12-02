#ifndef VECF_H_
#define VECF_H_

#include <string>


namespace cph {

class Vecf {

public:
	Vecf();
	virtual ~Vecf();

	float length() const;
	std::string toString() const;
	float* toArray(float* raw) const;
	bool isZeroVector() const;
	
	virtual float getN(int n) const = 0;
	virtual Vecf* setN(int  n, float value) = 0;
	virtual int getDim() const = 0;
};

}

#endif