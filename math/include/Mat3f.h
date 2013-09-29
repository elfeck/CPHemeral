#ifndef MAT3F_H_
#define MAT3F_H_

#include <vector>

#include "Matf.h"


namespace cph {

class Mat3f : public Matf {

public:
	Mat3f(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	Mat3f(std::vector<float> values);
	~Mat3f();

	Mat3f* addMat3f(Mat3f* mat);
	Mat3f* subMat3f(Mat3f* mat);
	Mat3f* mulMat3f(Mat3f* mat);
	Mat3f* mulMat3fLeft(Mat3f* mat);

	Mat3f* addMat3f(Mat3f mat);
	Mat3f* subMat3f(Mat3f mat);
	Mat3f* mulMat3f(Mat3f mat);
	Mat3f* mulMat3fLeft(Mat3f mat);

	Mat3f* mulScalar(float value);
	Mat3f* negate();
	Mat3f* invert();
	Mat3f* transpose();

	Mat3f* setNM(int n, int m, float value);
	Mat3f* setColumn(int n, std::vector<float> column);
	Mat3f* setRow(int m, std::vector<float> row);
	Mat3f* setMat(Mat3f* mat);
	Mat3f* setMat(Mat3f mat);
	
	virtual float det();
	virtual int getDim();

	Mat3f copy();
	Mat3f* copyInto(Mat3f* raw);

	void operator+=(Mat3f* mat);
	void operator-=(Mat3f* mat);
	void operator*=(Mat3f* mat);

	void operator+=(Mat3f mat);
	void operator-=(Mat3f mat);
	void operator*=(Mat3f mat);
};

}

#endif