#ifndef MAT2F_H_
#define MAT2F_H_

#include <vector>

#include"Matf.h"


namespace cph {

class Mat2f : public Matf {

public:
	Mat2f(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	Mat2f(std::vector<float> values);
	Mat2f(const Mat2f& other);
	~Mat2f();

	Mat2f* addMat2f(const Mat2f* mat);
	Mat2f* subMat2f(const Mat2f* mat);
	Mat2f* mulMat2f(const Mat2f* mat);
	Mat2f* mulMat2fLeft(const Mat2f* mat);

	Mat2f* addMat2f(const Mat2f& mat);
	Mat2f* subMat2f(const Mat2f& mat);
	Mat2f* mulMat2f(const Mat2f& mat);
	Mat2f* mulMat2fLeft(const Mat2f& mat);

	Mat2f* mulScalar(float value);
	Mat2f* negate();
	Mat2f* transpose();

	Mat2f* setNM(int n, int m, float value);
	Mat2f* setColumn(int n, std::vector<float> column);
	Mat2f* setRow(int m, std::vector<float> row);

	Mat2f* setMat(const Mat2f* mat);
	Mat2f* setMat(const Mat2f& mat);

	virtual float det() const;
	virtual int getDim() const;

	Mat2f copy() const;
	Mat2f* copyInto(Mat2f* raw) const;

	void operator+=(const Mat2f* mat);
	void operator-=(const Mat2f* mat);
	void operator*=(const Mat2f* mat);

	void operator+=(const Mat2f& mat);
	void operator-=(const Mat2f& mat);
	void operator*=(const Mat2f& mat);
};

}

#endif