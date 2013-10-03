#include "../../include/Mat2f.h"


using namespace cph;

Mat2f::Mat2f(std::vector<std::vector<float>> matrix) :
	Matf(matrix)
{
	bool valid = this->matrix.size() == 2;
	if(valid) {
		for(int i = 0; i < 2; i++) {
			valid = valid && this->matrix.at(i).size() == 2;
		}
	}
	if(!valid) this->matrix = std::vector<std::vector<float>>(2, std::vector<float>(2, 0.0f));

}

Mat2f::Mat2f(std::vector<float> values) :
	Matf(std::vector<std::vector<float>>(2, std::vector<float>(2, 0.0f)))
{
	if(values.size() == 4) {
		for(int n = 0; n < 2; n++) {
			for(int m = 0; m < 2; m++) {
				matrix.at(n).at(m) = values.at(n * 2 + m);
			}
		}
	}
}

Mat2f::~Mat2f() {

}


Mat2f* Mat2f::addMat2f(Mat2f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) += mat->getNM(n, m);
		}
	}
	return this;
}

Mat2f* Mat2f::subMat2f(Mat2f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) -= mat->getNM(n, m);
		}
	}
	return this;
}

Mat2f* Mat2f::mulMat2f(Mat2f* mat) {
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

Mat2f* Mat2f::mulMat2fLeft(Mat2f* mat) {
	return setMat(setMat(mat->copy().mulMat2f(this)));
}

	
Mat2f* Mat2f::addMat2f(Mat2f mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) += mat.getNM(n, m);
		}
	}
	return this;
}

Mat2f* Mat2f::subMat2f(Mat2f mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) -= mat.getNM(n, m);
		}
	}
	return this;
}

Mat2f* Mat2f::mulMat2f(Mat2f mat) {
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

Mat2f* Mat2f::mulMat2fLeft(Mat2f mat) {
	return setMat(mat.copy().mulMat2f(this));
}


Mat2f* Mat2f::mulScalar(float value) {
	if(!isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) *= value;
		}
	}
	return this;
}

Mat2f* Mat2f::negate() {
	return mulScalar(-1.0f);
}

Mat2f* Mat2f::invert() {
	return this;
}

Mat2f* Mat2f::transpose() {
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


Mat2f* Mat2f::setNM(int n, int m, float value) {
	if(!isValid() || !inRange(n, m)) return this;
	matrix.at(n).at(m) = value;
	return this;
}

Mat2f* Mat2f::setColumn(int n, std::vector<float> column) {
	if(!isValid() || !inRange(n, 0) || column.size() != getDim()) return this;
	matrix.at(0) = column;
	return this;
}

Mat2f* Mat2f::setRow(int m, std::vector<float> row) {
	if(!isValid() || !inRange(0, m) || row.size() != getDim()) return this;
	for(int n = 0; n < getDim(); n++) {
		matrix.at(n).at(m) = row.at(n);
	}
	return this;
}

Mat2f* Mat2f::setMat(Mat2f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) = mat->getNM(n, m);
		}
	}
	return this;
}

Mat2f* Mat2f::setMat(Mat2f mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) = mat.getNM(n, m);
		}
	}
	return this;
}


float Mat2f::det() {
	if(!isValid()) return 0;
	return matrix.at(0).at(0) * matrix.at(1).at(1) - matrix.at(1).at(0) * matrix.at(0).at(1);
}

int Mat2f::getDim() {
	return 2;
}

Mat2f Mat2f::copy() {
	return *(Mat2f().setMat(this));
}

Mat2f* Mat2f::copyInto(Mat2f* raw) {
	return raw->setMat(this);
}


void Mat2f::operator+=(Mat2f* mat) {
	addMat2f(mat);
}

void Mat2f::operator-=(Mat2f* mat) {
	subMat2f(mat);
}

void Mat2f::operator*=(Mat2f* mat) {
	mulMat2f(mat);
}

void Mat2f::operator+=(Mat2f mat) {
	addMat2f(mat);
}

void Mat2f::operator-=(Mat2f mat) {
	subMat2f(mat);
}

void Mat2f::operator*=(Mat2f mat) {
	mulMat2f(mat);
}