#ifndef MAT2F_H_
#define MAT2F_H_

#include <vector>

#include"Matf.h"


namespace cph {

class Mat2f : public Matf {

public:
	Mat2f(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	Mat2f(std::vector<float> values);
	~Mat2f();

	Mat2f* addMat2f(Mat2f* mat);
	Mat2f* subMat2f(Mat2f* mat);
	Mat2f* mulMat2f(Mat2f* mat);
	Mat2f* mulMat2fLeft(Mat2f* mat);

	Mat2f* addMat2f(Mat2f mat);
	Mat2f* subMat2f(Mat2f mat);
	Mat2f* mulMat2f(Mat2f mat);
	Mat2f* mulMat2fLeft(Mat2f mat);

	Mat2f* mulScalar(float value);
	Mat2f* negate();
	Mat2f* invert();
	Mat2f* transpose();

	Mat2f* setNM(int n, int m, float value);
	Mat2f* setColumn(int n, std::vector<float> column);
	Mat2f* setRow(int m, std::vector<float> row);
	Mat2f* setMat(Mat2f* mat);
	Mat2f* setMat(Mat2f mat);
	
	virtual float det();
	virtual int getDim();

	Mat2f copy();
	Mat2f* copyInto(Mat2f* raw);

	void operator+=(Mat2f* mat);
	void operator-=(Mat2f* mat);
	void operator*=(Mat2f* mat);

	void operator+=(Mat2f mat);
	void operator-=(Mat2f mat);
	void operator*=(Mat2f mat);
};

}

#endif