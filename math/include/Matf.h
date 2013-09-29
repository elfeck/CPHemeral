#ifndef MATF_H_
#define MATF_H_

#include <vector>
#include <string>


namespace cph {

class Matf {

protected:
	std::vector<std::vector<float>> matrix;

	bool isValid();
	bool inRange(int n, int m);

public:
	Matf(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	virtual ~Matf();

	float getNM(int n, int m);
	std::vector<std::vector<float>>* raw();
	float* toArray(float* raw);
	std::string toString();

	virtual float det() = 0;
	virtual int getDim() = 0;

};

}

#endif