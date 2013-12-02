#include "../../include/Mat4f.h"


using namespace cph;

Mat4f::Mat4f(std::vector<std::vector<float>> matrix) :
	Matf(matrix)
{
	bool valid = this->matrix.size() == 4;
	if(valid) {
		
		for(int i = 0; i < 4; i++) {
			valid = valid && this->matrix.at(i).size() == 4;
		}
	}
	if(!valid) this->matrix = std::vector<std::vector<float>>(4, std::vector<float>(4, 0.0f));

}

Mat4f::Mat4f(std::vector<float> values) :
	Matf(std::vector<std::vector<float>>(4, std::vector<float>(4, 0.0f)))
{
	if(values.size() == 16) {
		for(int n = 0; n < 4; n++) {
			for(int m = 0; m < 4; m++) {
				matrix.at(n).at(m) = values.at(n * 4 + m);
			}
		}
	}
}

Mat4f::Mat4f(const Mat4f& other) :
	Matf(std::vector<std::vector<float>>(4, std::vector<float>(4, 0.0f)))
{
	setMat(&other);
}


Mat4f::~Mat4f() {

}

Mat4f* Mat4f::addMat4f(const Mat4f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) += mat->getNM(n, m);
		}
	}
	return this;
}

Mat4f* Mat4f::subMat4f(const Mat4f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) -= mat->getNM(n, m);
		}
	}
	return this;
}

Mat4f* Mat4f::mulMat4f(const Mat4f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	std::vector<float> currentRow(getDim(), 0.0f);
	for(int m = 0; m < getDim(); m++) {
		std::fill_n(currentRow.begin(), getDim(), 0.0f); 
		for(int n = 0; n < getDim(); n++) {
			for(int i = 0; i < getDim(); i++) {
				currentRow.at(n) += matrix.at(i).at(m) * mat->getNM(n, i);
			}
		}
		setRow(m, currentRow);
	}
	return this;
}

Mat4f* Mat4f::mulMat4fLeft(const Mat4f* mat) {
	return setMat(setMat(mat->copy().mulMat4f(this)));
}

Mat4f* Mat4f::addMat4f(const Mat4f& mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) += mat.getNM(n, m);
		}
	}
	return this;
}

Mat4f* Mat4f::subMat4f(const Mat4f& mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) -= mat.getNM(n, m);
		}
	}
	return this;
}

Mat4f* Mat4f::mulMat4f(const Mat4f& mat) {
	if(!isValid() || !mat.isValid()) return this;
	std::vector<float> currentRow(getDim(), 0.0f);
	for(int m = 0; m < getDim(); m++) {
		std::fill_n(currentRow.begin(), getDim(), 0.0f); 
		for(int n = 0; n < getDim(); n++) {
			for(int i = 0; i < getDim(); i++) {
				currentRow.at(n) += matrix.at(i).at(m) * mat.getNM(n, i);
			}
		}
		setRow(m, currentRow);
	}
	return this;
}

Mat4f* Mat4f::mulMat4fLeft(const Mat4f& mat) {
	return setMat(setMat(mat.copy().mulMat4f(this)));
}

Mat4f* Mat4f::mulScalar(float value) {
	if(!isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) *= value;
		}
	}
	return this;
}

Mat4f* Mat4f::negate() {
	return mulScalar(-1.0f);
}

Mat4f* Mat4f::transpose() {
	if(!isValid()) return this;
	float temp = 0;
	for(int m = 0; m < getDim(); m++) {
		for(int n = m; n < getDim(); n++) {
			temp = matrix.at(n).at(m);
			matrix.at(n).at(m) = matrix.at(m).at(n);
			matrix.at(m).at(n) = temp;
		}
	}
	return this;
}

Mat4f* Mat4f::setNM(int n, int m, float value) {
	if(!isValid() || !inRange(n, m)) return this;
	matrix.at(n).at(m) = value;
	return this;
}

Mat4f* Mat4f::setColumn(int n, std::vector<float> column) {
	if(!isValid() || !inRange(n, 0) || column.size() != getDim()) return this;
	matrix.at(n) = column;
	return this;
}

Mat4f* Mat4f::setRow(int m, std::vector<float> row) {
	if(!isValid() || !inRange(0, m) || row.size() != getDim()) return this;
	for(int n = 0; n < getDim(); n++) {
		matrix.at(n).at(m) = row.at(n);
	}
	return this;
}

Mat4f* Mat4f::setMat(const Mat4f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) = mat->getNM(n, m);
		}
	}
	return this;
}

Mat4f* Mat4f::setMat(const Mat4f& mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) = mat.getNM(n, m);
		}
	}
	return this;
}

float Mat4f::det() const {
	if(!isValid()) return 0;
	//TODO: !
	return 0;
}

int Mat4f::getDim() const {
	return 4;
}

Mat4f Mat4f::copy() const {
	return *(Mat4f().setMat(this));
}

Mat4f* Mat4f::copyInto(Mat4f* raw) const {
	return raw->setMat(this);
}

void Mat4f::operator+=(const Mat4f* mat) {
	addMat4f(mat);
}

void Mat4f::operator-=(const Mat4f* mat) {
	subMat4f(mat);
}

void Mat4f::operator*=(const Mat4f* mat) {
	mulMat4f(mat);
}

void Mat4f::operator+=(const Mat4f& mat) {
	addMat4f(mat);
}

void Mat4f::operator-=(const Mat4f& mat) {
	subMat4f(mat);
}

void Mat4f::operator*=(const Mat4f& mat) {
	mulMat4f(mat);
}