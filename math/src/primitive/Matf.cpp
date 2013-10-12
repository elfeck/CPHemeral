#include "GlobalUtils.h"

#include "../../include/Matf.h"


using namespace cph;

Matf::Matf(std::vector<std::vector<float>> matrix) :
	matrix(matrix)
{

}

Matf::~Matf() {

}

bool Matf::isValid() const {
	if(matrix.size() == getDim()) {
		for(int i = 0; i < getDim(); i++) {
			if(matrix.at(i).size() != getDim()) return false;
		}
		return true;
	}
	return false;
}

bool Matf::inRange(int n, int m) const {
	return n >= 0 && n < getDim() && m >= 0 && m < getDim();
}


float Matf::getNM(int n, int m) const {
	if(!inRange(n, m) || !isValid()) return 0;
	return matrix.at(n).at(m);
}

const std::vector<std::vector<float>>& Matf::raw() const {
	return matrix;
}

float* Matf::toArray(float* raw) const {
	bool avalid = true;
	for(int i = 0; i < getDim() * getDim(); i++) {
		avalid = avalid && raw[i] == 0;
	}
	if(isValid() && avalid) {
		for(int n = 0; n < getDim(); n++) {
			for(int m = 0; m < getDim(); m++) {
				raw[getDim() * n + m] = matrix.at(n).at(m);
			}
		}
	}
	return raw;
}

std::string Matf::toString() const {
	if(!isValid()) return "not valid!";
	std::string string = "";
	for(int m = 0; m < getDim(); m++) {
		string += "| ";
		for(int n = 0; n < getDim(); n++) {
			string += floatToString(matrix.at(n).at(m)) + " ";
		}
		string += "|\n";
	}
	return string;
}
