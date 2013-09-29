#ifndef MAT4F_H_
#define MAT4F_H_

#include <vector>

#include "Matf.h"


namespace cph {

class Mat4f : public Matf {

public:
	Mat4f(std::vector<std::vector<float>> matrix = std::vector<std::vector<float>>());
	Mat4f(std::vector<float> values);
	~Mat4f();

	Mat4f* addMat4f(Mat4f* mat);
	Mat4f* subMat4f(Mat4f* mat);
	Mat4f* mulMat4f(Mat4f* mat);
	Mat4f* mulMat4fLeft(Mat4f* mat);

	Mat4f* addMat4f(Mat4f mat);
	Mat4f* subMat4f(Mat4f mat);
	Mat4f* mulMat4f(Mat4f mat);
	Mat4f* mulMat4fLeft(Mat4f mat);

	Mat4f* mulScalar(float value);
	Mat4f* negate();
	Mat4f* invert();
	Mat4f* transpose();

	Mat4f* setNM(int n, int m, float value);
	Mat4f* setColumn(int n, std::vector<float> column);
	Mat4f* setRow(int m, std::vector<float> row);
	Mat4f* setMat(Mat4f* mat);
	Mat4f* setMat(Mat4f mat);
	
	virtual float det();
	virtual int getDim();
	
	Mat4f copy();
	Mat4f* copyInto(Mat4f* raw);

	void operator+=(Mat4f* mat);
	void operator-=(Mat4f* mat);
	void operator*=(Mat4f* mat);

	void operator+=(Mat4f mat);
	void operator-=(Mat4f mat);
	void operator*=(Mat4f mat);
};

}


#endif