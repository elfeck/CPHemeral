#ifndef MAT3F_H_
#define MAT3F_H_

#include <vector>

#include "Matf.h"


namespace cph {

class Mat3f : public Matf {

public:
	Mat3f(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	Mat3f(std::vector<float> values);
	Mat3f(const Mat3f& other);
	~Mat3f();

	Mat3f* addMat3f(const Mat3f* mat);
	Mat3f* subMat3f(const Mat3f* mat);
	Mat3f* mulMat3f(const Mat3f* mat);
	Mat3f* mulMat3fLeft(const Mat3f* mat);
	
	Mat3f* addMat3f(const Mat3f& mat);
	Mat3f* subMat3f(const Mat3f& mat);
	Mat3f* mulMat3f(const Mat3f& mat);
	Mat3f* mulMat3fLeft(const Mat3f& mat);

	Mat3f* mulScalar(float value);
	Mat3f* negate();
	Mat3f* transpose();

	Mat3f* setNM(int n, int m, float value);
	Mat3f* setColumn(int n, std::vector<float> column);
	Mat3f* setRow(int m, std::vector<float> row);

	Mat3f* setMat(const Mat3f* mat);
	Mat3f* setMat(const Mat3f& mat);
	
	virtual float det() const;
	virtual int getDim() const;

	Mat3f copy() const;
	Mat3f* copyInto(Mat3f* raw) const;

	void operator+=(const Mat3f* mat);
	void operator-=(const Mat3f* mat);
	void operator*=(const Mat3f* mat);
	
	void operator+=(const Mat3f& mat);
	void operator-=(const Mat3f& mat);
	void operator*=(const Mat3f& mat);
};

}

#endif