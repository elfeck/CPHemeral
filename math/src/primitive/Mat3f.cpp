#include "../../include/Mat3f.h"


using namespace cph;

Mat3f::Mat3f(std::vector<std::vector<float>> matrix) :
	Matf(matrix)
{
	bool valid = this->matrix.size() == 3;
	if(valid) {
		
		for(int i = 0; i < 3; i++) {
			valid = valid && this->matrix.at(i).size() == 3;
		}
	}
	if(!valid) this->matrix = std::vector<std::vector<float>>(3, std::vector<float>(3, 0.0f));

}

Mat3f::Mat3f(std::vector<float> values) :
	Matf(std::vector<std::vector<float>>(3, std::vector<float>(3, 0.0f)))
{
	if(values.size() == 9) {
		for(int n = 0; n < 3; n++) {
			for(int m = 0; m < 3; m++) {
				matrix.at(n).at(m) = values.at(n * 3 + m);
			}
		}
	}
}

Mat3f::~Mat3f() {

}


Mat3f* Mat3f::addMat3f(Mat3f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) += mat->getNM(n, m);
		}
	}
	return this;
}

Mat3f* Mat3f::subMat3f(Mat3f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) -= mat->getNM(n, m);
		}
	}
	return this;
}

Mat3f* Mat3f::mulMat3f(Mat3f* mat) {
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

Mat3f* Mat3f::mulMat3fLeft(Mat3f* mat) {
	return setMat(setMat(mat->copy().mulMat3f(this)));
}


Mat3f* Mat3f::addMat3f(Mat3f mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) += mat.getNM(n, m);
		}
	}
	return this;
}

Mat3f* Mat3f::subMat3f(Mat3f mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) -= mat.getNM(n, m);
		}
	}
	return this;
}

Mat3f* Mat3f::mulMat3f(Mat3f mat) {
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

Mat3f* Mat3f::mulMat3fLeft(Mat3f mat) {
	return setMat(setMat(mat.copy().mulMat3f(this)));
}

Mat3f* Mat3f::mulScalar(float value) {
	if(!isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) *= value;
		}
	}
	return this;
}

Mat3f* Mat3f::negate() {
	return mulScalar(-1.0f);
}

Mat3f* Mat3f::invert() {
	return this;
}

Mat3f* Mat3f::transpose() {
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


Mat3f* Mat3f::setNM(int n, int m, float value) {
	if(!isValid() || !inRange(n, m)) return this;
	matrix.at(n).at(m) = value;
	return this;
}

Mat3f* Mat3f::setColumn(int n, std::vector<float> column) {
	if(!isValid() || !inRange(n, 0) || column.size() != getDim()) return this;
	matrix.at(0) = column;
	return this;
}

Mat3f* Mat3f::setRow(int m, std::vector<float> row) {
	if(!isValid() || !inRange(0, m) || row.size() != getDim()) return this;
	for(int n = 0; n < getDim(); n++) {
		matrix.at(n).at(m) = row.at(n);
	}
	return this;
}

Mat3f* Mat3f::setMat(Mat3f* mat) {
	if(!isValid() || !mat->isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) = mat->getNM(n, m);
		}
	}
	return this;
}

Mat3f* Mat3f::setMat(Mat3f mat) {
	if(!isValid() || !mat.isValid()) return this;
	for(int n = 0; n < getDim(); n++) {
		for(int m = 0; m < getDim(); m++) {
			matrix.at(n).at(m) = mat.getNM(n, m);
		}
	}
	return this;
}


float Mat3f::det() {
	if(!isValid()) return 0;
	float det = 0;
	float prod = 1;
	int dim = getDim();
	for(int i = 0; i < dim; i++) {
		float prod = 1;
		for(int j = 0; j < dim; j++) {
			prod *= matrix.at((i + j)%dim).at(j);
		}
		det += prod;
	}
	for(int i = dim - 1; i >= 0; i--) {
		 prod = 1;
		for(int j = 0; j < dim; j++) {
			prod *= matrix.at((dim + i - j)%dim).at(j);
		}
		det -= prod;
	}
	return det;
}

int Mat3f::getDim() {
	return 3;
}


Mat3f Mat3f::copy() {
	return *(Mat3f().setMat(this));
}

Mat3f* Mat3f::copyInto(Mat3f* raw) {
	return raw->setMat(this);
}

void Mat3f::operator+=(Mat3f* mat) {
	addMat3f(mat);
}

void Mat3f::operator-=(Mat3f* mat) {
	subMat3f(mat);
}

void Mat3f::operator*=(Mat3f* mat) {
	mulMat3f(mat);
}


void Mat3f::operator+=(Mat3f mat) {
	addMat3f(mat);
}

void Mat3f::operator-=(Mat3f mat) {
	subMat3f(mat);
}

void Mat3f::operator*=(Mat3f mat) {
	mulMat3f(mat);
}
