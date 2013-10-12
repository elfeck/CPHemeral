#ifndef MAT4F_H_
#define MAT4F_H_

#include <vector>

#include "Matf.h"


namespace cph {

class Mat4f : public Matf {

public:
	Mat4f(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	Mat4f(std::vector<float> values);
	Mat4f(const Mat4f& other);
	~Mat4f();

	Mat4f* addMat4f(const Mat4f* mat);
	Mat4f* subMat4f(const Mat4f* mat);
	Mat4f* mulMat4f(const Mat4f* mat);
	Mat4f* mulMat4fLeft(const Mat4f* mat);

	Mat4f* addMat4f(const Mat4f& mat);
	Mat4f* subMat4f(const Mat4f& mat);
	Mat4f* mulMat4f(const Mat4f& mat);
	Mat4f* mulMat4fLeft(const Mat4f& mat);

	Mat4f* mulScalar(float value);
	Mat4f* negate();
	Mat4f* transpose();

	Mat4f* setNM(int n, int m, float value);
	Mat4f* setColumn(int n, std::vector<float> column);
	Mat4f* setRow(int m, std::vector<float> row);

	Mat4f* setMat(const Mat4f* mat);
	Mat4f* setMat(const Mat4f& mat);

	virtual float det() const;
	virtual int getDim() const;
	
	Mat4f copy() const;
	Mat4f* copyInto(Mat4f* raw) const;

	void operator+=(const Mat4f* mat);
	void operator-=(const Mat4f* mat);
	void operator*=(const Mat4f* mat);

	void operator+=(const Mat4f& mat);
	void operator-=(const Mat4f& mat);
	void operator*=(const Mat4f& mat);

};

}


#endif