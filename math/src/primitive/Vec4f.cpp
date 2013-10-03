#include "../../include/Vec4f.h"


using namespace cph;

Vec4f::Vec4f(float x, float y, float z, float w) :
	Vecf(), x(x), y(y), z(z), w(w)
{

}

Vec4f::~Vec4f() {

}


Vec4f* Vec4f::addVec4f(Vec4f* vec) {
	x += vec->x;
	y += vec->y;
	z += vec->z;
	w += vec->w;
	return this;
}

Vec4f* Vec4f::subVec4f(Vec4f* vec) {
	x -= vec->x;
	y -= vec->y;
	z -= vec->z;
	w -= vec->w;
	return this;
}

Vec4f* Vec4f::mulVec4f(Vec4f* vec) {
	x *= vec->x;
	y *= vec->y;
	z *= vec->z;
	w *= vec->w;
	return this;
}

Vec4f* Vec4f::divVec4f(Vec4f* vec) {
	if(vec->x != 0 && vec->y != 0 && vec->z != 0 && vec->w != 0) {
		x /= vec->x;
		y /= vec->y;
		z /= vec->z;
		w /= vec->w;
	}
	return this;
}

Vec4f* Vec4f::mulMat4f(Mat4f* mat) {
	Vec4f vec = Vec4f(*this);
	float rowSum = 0;
	for(int m = 0; m < getDim(); m++) {
		for(int n = 0; n < getDim(); n++) {
			rowSum += mat->getNM(n, m) * vec.getN(n);
		}
		setN(m, rowSum);
		rowSum = 0;
	}
	return this;
}


Vec4f* Vec4f::addVec4f(Vec4f vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
	return this;
}

Vec4f* Vec4f::subVec4f(Vec4f vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
	return this;
}

Vec4f* Vec4f::mulVec4f(Vec4f vec) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	w *= vec.w;
	return this;
}

Vec4f* Vec4f::divVec4f(Vec4f vec) {
	if(vec.x != 0 && vec.y != 0 && vec.z != 0 && vec.w != 0) {
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		w /= vec.w;
	}
	return this;
}

Vec4f* Vec4f::mulMat4f(Mat4f mat) {
	Vec4f vec = Vec4f(*this);
	float rowSum = 0;
	for(int m = 0; m < getDim(); m++) {
		for(int n = 0; n < getDim(); n++) {
			rowSum += mat.getNM(n, m) * vec.getN(n);
		}
		setN(m, rowSum);
		rowSum = 0;
	}
	return this;
}


	
Vec4f* Vec4f::addVec4f(float vx, float vy, float vz, float vw) {
	x += vx;
	y += vy;
	z += vz;
	w += vw;
	return this;
}

Vec4f* Vec4f::subVec4f(float vx, float vy, float vz, float vw) {
	x -= vx;
	y -= vy;
	z -= vz;
	w -= vw;
	return this;
}

Vec4f* Vec4f::mulVec4f(float vx, float vy, float vz, float vw) {
	x *= vx;
	y *= vy;
	z *= vz;
	w *= vw;
	return this;
}

Vec4f* Vec4f::divVec4f(float vx, float vy, float vz, float vw) {
	if(vx != 0 && vy != 0 && vz != 0 && vw != 0) {
		x /= vx;
		y /= vy;
		z /= vz;
		w /= vw;
	}
	return this;
}

	
float Vec4f::dot(Vec4f* vec) {
	return x * vec->x + y * vec->y + z * vec->z + w * vec->w;
}

float Vec4f::dot(Vec4f vec) {
	return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

Vec4f*Vec4f:: mulScalar(float value) {
	x *= value;
	y *= value;
	z *= value;
	w *= value;
	return this;
}

Vec4f* Vec4f::normalize() {
	if(length() == 0) return this;
	return mulScalar(1.0f / length());
}

Vec4f* Vec4f::toLength(float value) {
	return normalize()->mulScalar(value);
}

Vec4f* Vec4f::negate() {
	return mulScalar(-1.0f);
}


Vec4f* Vec4f::setX(float newX) {
	x = newX;
	return this;
}

Vec4f* Vec4f::setY(float newY) {
	y = newY;
	return this;
}

Vec4f* Vec4f::setZ(float newZ) {
	z = newZ;
	return this;
}

Vec4f* Vec4f::setW(float newW) {
	w = newW;
	return this;
}

Vec4f* Vec4f::setXYZW(float newX, float newY, float newZ, float newW) {
	x = newX;
	y = newY;
	z = newZ;
	w = newW;
	return this;
}

Vec4f* Vec4f::setVec(Vec4f* vec) {
	x = vec->x;
	y = vec->y;
	z = vec->z;
	w = vec->w;
	return this;
}

Vec4f* Vec4f::setVec(Vec4f vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
	return this;
}

float Vec4f::getX() {
	return x;
}

float Vec4f::getY() {
	return y;
}

float Vec4f::getZ() {
	return z;
}

float Vec4f::getW() {
	return w;
}


Vecf* Vec4f::setN(int n, float value) {
	if(n == 0) x = value;
	if(n == 1) y = value;
	if(n == 2) z = value;
	if(n == 3) w = value;
	return this;
}

float Vec4f::getN(int n) {
	if(n == 0) return x;
	if(n == 1) return y;
	if(n == 2) return z;
	if(n == 3) return w;
	return 0;
}

int Vec4f::getDim() {
	return 4;
}

Vec4f* Vec4f::copyInto(Vec4f* raw) {
	return raw->setVec(this);
}


void Vec4f::operator+=(Vec4f* vec) {
	addVec4f(vec);
}

void Vec4f::operator-=(Vec4f* vec) {
	subVec4f(vec);
}

void Vec4f::operator*=(Vec4f* vec) {
	mulVec4f(vec);
}

void Vec4f::operator/=(Vec4f* vec) {
	divVec4f(vec);
}

void Vec4f::operator*=(Mat4f* mat) {
	mulMat4f(mat);
}


void Vec4f::operator+=(Vec4f vec) {
	addVec4f(vec);
}

void Vec4f::operator-=(Vec4f vec) {
	subVec4f(vec);
}

void Vec4f::operator*=(Vec4f vec) {
	mulVec4f(vec);
}

void Vec4f::operator/=(Vec4f vec) {
	divVec4f(vec);
}

void Vec4f::operator*=(Mat4f mat) {
	mulMat4f(mat);
}