#include "GlobalUtils.h"

#include "../../include/Vecf.h"


using namespace cph;

Vecf::Vecf() {

}

Vecf::~Vecf() {

}

float Vecf::length() const {
	float sum = 0;
	for(int i = 0; i < getDim(); i++) {
		sum += getN(i) * getN(i);
	}
	return std::sqrt(sum);
}

std::string Vecf::toString() const {
	std::string string = "(";
	for(int i = 0; i < getDim(); i++) {
		string += floatToString(getN(i));
		if(i < getDim() -1) string += ", ";
	}
	string += ")";
	return string;
}

float* Vecf::toArray(float* raw) const {
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

bool Vecf::isZeroVector() const {
	for(int i = 0; i < getDim(); i++) {
		if(getN(i) != 0.0f) return false;
	}
	return true;
}

bool Vecf::operator==(Vecf& vec) const {
	if(this->getDim() != vec.getDim()) return false;
	for(int i = 0; i < this->getDim(); i++)	{
		if(this->getN(i) != vec.getN(i)) return false;
	}
	return true;
}

bool Vecf::operator==(Vecf* vec) const {
	return *this == *vec;
}

bool Vecf::operator!=(Vecf& vec) const {
	return !(*this == vec);
}

bool Vecf::operator!=(Vecf* vec) const {
	return *this != *vec;
}
