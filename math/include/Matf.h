#ifndef MATF_H_
#define MATF_H_

#include <vector>
#include <string>


namespace cph {

class Matf {

protected:
	std::vector<std::vector<float>> matrix;

	bool isValid() const;
	bool inRange(int n, int m) const;

public:
	Matf(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	virtual ~Matf();

	float getNM(int n, int m) const;
	const std::vector<std::vector<float>>& raw() const;
	float* toArray(float* raw) const;
	std::string toString() const;

	virtual float det() const = 0;
	virtual int getDim() const = 0;

};

}

#endif