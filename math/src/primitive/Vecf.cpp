#include "GlobalUtils.h"

#include "../../include/Vecf.h"


using namespace cph;

Vecf::Vecf() {

}

Vecf::~Vecf() {

}


float Vecf::length() {
	float sum = 0;
	
	for(int i = 0; i < getDim(); i++) {
		sum += getN(i) * getN(i);
	}
	return std::sqrt(sum);
}

std::string Vecf::toString() {
	std::string string = "(";
	for(int i = 0; i < getDim(); i++) {
		string += floatToString(getN(i));
		if(i < getDim() -1) string += ", ";
	}
	string += ")";
	return string;
}

float* Vecf::toArray(float* raw) {
	bool valid = true;
	for(int i = 0; i < getDim(); i++) {
		valid = valid && raw[i] == 0;
	}
	if(valid) {
		for(int i = 0; i < getDim(); i++) {
			raw[i] = getN(i);
		}
	}
	return raw;
}