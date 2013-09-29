#include "../include/Vec3f.h"


using namespace cph;

Vec3f::Vec3f(float x, float y, float z) :
	Vecf(), x(x), y(y), z(z)
{

}

Vec3f::~Vec3f() {

}


Vec3f* Vec3f::addVec3f(Vec3f* vec) {
	x += vec->x;
	y += vec->y;
	z += vec->z;
	return this;
}

Vec3f* Vec3f::subVec3f(Vec3f* vec) {
	x -= vec->x;
	y -= vec->y;
	z -= vec->z;
	return this;
}

Vec3f* Vec3f::mulVec3f(Vec3f* vec) {
	x *= vec->x;
	y *= vec->y;
	z *= vec->z;
	return this;
}

Vec3f* Vec3f::divVec3f(Vec3f* vec) {
	if(vec->x != 0 && vec->y != 0 && vec->z != 0) {
		x /= vec->x;
		y /= vec->y;
		z /= vec->z;
	}
	return this;
}

Vec3f* Vec3f::mulMat3f(Mat3f* mat) {
	Vec3f vec = Vec3f(*this);
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


Vec3f* Vec3f::addVec3f(Vec3f vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return this;
}

Vec3f* Vec3f::subVec3f(Vec3f vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return this;
}

Vec3f* Vec3f::mulVec3f(Vec3f vec) {
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	return this;
}

Vec3f* Vec3f::divVec3f(Vec3f vec) {
	if(vec.x != 0 && vec.y != 0 && vec.z != 0) {
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
	}
	return this;
}

Vec3f* Vec3f::mulMat3f(Mat3f mat) {
	Vec3f vec = Vec3f(*this);
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

	
Vec3f* Vec3f::addVec3f(float vx, float vy, float vz) {
	x += vx;
	y += vy;
	z += vz;
	return this;
}

Vec3f* Vec3f::subVec3f(float vx, float vy, float vz) {
	x -= vx;
	y -= vy;
	z -= vz;
	return this;
}

Vec3f* Vec3f::mulVec3f(float vx, float vy, float vz) {
	x *= vx;
	y *= vy;
	z *= vz;
	return this;
}

Vec3f* Vec3f::divVec3f(float vx, float vy, float vz) {
	if(vx != 0 && vy != 0 && vz != 0) {
		x /= vx;
		y /= vy;
		z /= vz;
	}
	return this;
}

	
float Vec3f::dot(Vec3f* vec) {
	return x * vec->x + y * vec->y + z * vec->z;
}

float Vec3f::dot(Vec3f vec) {
	return x * vec.x + y * vec.y + z * vec.z;
}

Vec3f* Vec3f::mulScalar(float value) {
	x *= value;
	y *= value;
	z *= value;
	return this;
}

Vec3f* Vec3f::normalize() {
	if(length() == 0) return this;
	return mulScalar(1.0f / length());
}

Vec3f* Vec3f::toLength(float value) {
	return normalize()->mulScalar(value);
}

Vec3f* Vec3f::negate() {
	return mulScalar(-1.0f);
}


Vec3f* Vec3f::setX(float newX) {
	x = newX;
	return this;
}

Vec3f* Vec3f::setY(float newY) {
	y = newY;
	return this;
}

Vec3f* Vec3f::setZ(float newZ) {
	z = newZ;
	return this;
}

Vec3f* Vec3f::setXYZ(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
	return this;
}

Vec3f* Vec3f::setVec(Vec3f* vec) {
	x = vec->x;
	y = vec->y;
	z = vec->z;
	return this;
}

Vec3f* Vec3f::setVec(Vec3f vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return this;
}

float Vec3f::getX() {
	return x;
}

float Vec3f::getY() {
	return y;
}

float Vec3f::getZ() {
	return z;
}


Vecf* Vec3f::setN(int n, float value) {
	if(n == 0) x = value;
	if(n == 1) y = value;
	if(n == 2) z = value;
	return this;
}

float Vec3f::getN(int n) {
	if(n == 0) return x;
	if(n == 1) return y;
	if(n == 2) return z;
	return 0;
}

int Vec3f::getDim() {
	return 3;
}

Vec3f* Vec3f::copyInto(Vec3f* raw) {
	return raw->setVec(this);
}


void Vec3f::operator+=(Vec3f* vec) {
	addVec3f(vec);
}

void Vec3f::operator-=(Vec3f* vec) {
	subVec3f(vec);
}

void Vec3f::operator*=(Vec3f* vec) {
	mulVec3f(vec);
}

void Vec3f::operator/=(Vec3f* vec) {
	divVec3f(vec);
}

void Vec3f::operator*=(Mat3f* mat) {
	mulMat3f(mat);
}


void Vec3f::operator+=(Vec3f vec) {
	addVec3f(vec);
}

void Vec3f::operator-=(Vec3f vec) {
	subVec3f(vec);
}

void Vec3f::operator*=(Vec3f vec) {
	mulVec3f(vec);
}

void Vec3f::operator/=(Vec3f vec) {
	divVec3f(vec);
}

void Vec3f::operator*=(Mat3f mat) {
	mulMat3f(mat);
}