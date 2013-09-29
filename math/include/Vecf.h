#ifndef VECF_H_
#define VECF_H_

#include <string>


namespace cph {

class Vecf {

public:
	Vecf();
	virtual ~Vecf();

	float length();
	std::string toString();
	float* toArray(float* raw);
	
	virtual Vecf* setN(int  n, float value) = 0;
	virtual float getN(int n) = 0;
	virtual int getDim() = 0;
};

}

#endif