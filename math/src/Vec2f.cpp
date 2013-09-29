#include "../include/Vec2f.h"


using namespace cph;

Vec2f::Vec2f(float x, float y) :
	Vecf(), x(x), y(y)
{

}

Vec2f::~Vec2f() {

}


Vec2f* Vec2f::addVec2f(Vec2f* vec) {
	x += vec->x;
	y += vec->y;
	return this;
}

Vec2f* Vec2f::subVec2f(Vec2f* vec) {
	x -= vec->x;
	y -= vec->y;
	return this;
}

Vec2f* Vec2f::mulVec2f(Vec2f* vec) {
	x *= vec->x;
	y *= vec->y;
	return this;
}

Vec2f* Vec2f::divVec2f(Vec2f* vec) {
	if(vec->x != 0 && vec->y != 0) {
		x /= vec->x;
		y /= vec->y;
	}
	return this;
}

Vec2f* Vec2f::mulMat2f(Mat2f* mat) {
	Vec2f vec = Vec2f(*this);
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


Vec2f* Vec2f::addVec2f(Vec2f vec) {
	x += vec.x;
	y += vec.y;
	return this;
}

Vec2f* Vec2f::subVec2f(Vec2f vec) {
	x -= vec.x;
	y -= vec.y;
	return this;
}

Vec2f* Vec2f::mulVec2f(Vec2f vec) {
	x *= vec.x;
	y *= vec.y;
	return this;
}

Vec2f* Vec2f::divVec2f(Vec2f vec) {
	if(vec.x != 0 && vec.y != 0) {
		x /= vec.x;
		y /= vec.y;
	}
	return this;
}

Vec2f* Vec2f::mulMat2f(Mat2f mat) {
	Vec2f vec = Vec2f(*this);
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


Vec2f* Vec2f::addVec2f(float vx, float vy) {
	x += vx;
	y += vy;
	return this;
}

Vec2f* Vec2f::subVec2f(float vx, float vy) {
	x -= vx;
	y -= vy;
	return this;
}

Vec2f* Vec2f::mulVec2f(float vx, float vy) {
	x *= vx;
	y *= vy;
	return this;
}

Vec2f* Vec2f::divVec2f(float vx, float vy) {
	if(vx != 0 && vy != 0) {
		x /= vx;
		y /= vy;
	}
	return this;
}


float Vec2f::dot(Vec2f* vec) {
	return x * vec->x + y * vec->y;
}

float Vec2f::dot(Vec2f vec) {
	return x * vec.x + y * vec.y;
}

Vec2f* Vec2f::mulScalar(float value) {
	x *= value;
	y *= value;
	return this;
}

Vec2f* Vec2f::normalize() {
	if(length() == 0) return this;
	return mulScalar(1.0f / length());
}

Vec2f* Vec2f::toLength(float value) {
	return normalize()->mulScalar(value);
}

Vec2f* Vec2f::negate() {
	return mulScalar(-1.0f);
}


Vec2f* Vec2f::setX(float newX) {
	x = newX;
	return this;
}

Vec2f* Vec2f::setY(float newY) {
	y = newY;
	return this;
}

Vec2f* Vec2f::setXY(float newX, float newY) {
	x = newX;
	y = newY;
	return this;
}

Vec2f* Vec2f::setVec(Vec2f* vec) {
	x = vec->x;
	y = vec->y;
	return this;
}

Vec2f* Vec2f::setVec(Vec2f vec) {
	x = vec.x;
	y = vec.y;
	return this;
}

float Vec2f::getX() {
	return x;
}

float Vec2f::getY() {
	return y;
}


Vecf* Vec2f::setN(int n, float value) {
	if(n == 0) x = value;
	if(n == 1) y = value;
	return this;
}

float Vec2f::getN(int n) {
	if(n == 0) return x;
	if(n == 1) return y;
	return 0;
}

int Vec2f::getDim() {
	return 2;
}

Vec2f* Vec2f::copyInto(Vec2f* raw) {
	return raw->setVec(this);
}


void Vec2f::operator+=(Vec2f* vec) {
	addVec2f(vec);
}

void Vec2f::operator-=(Vec2f* vec) {
	subVec2f(vec);
}

void Vec2f::operator*=(Vec2f* vec) {
	mulVec2f(vec);
}

void Vec2f::operator/=(Vec2f* vec) {
	divVec2f(vec);
}

void Vec2f::operator*=(Mat2f* mat) {
	mulMat2f(mat);
}


void Vec2f::operator+=(Vec2f vec) {
	addVec2f(vec);
}

void Vec2f::operator-=(Vec2f vec) {
	subVec2f(vec);
}

void Vec2f::operator*=(Vec2f vec) {
	mulVec2f(vec);
}

void Vec2f::operator/=(Vec2f vec) {
	divVec2f(vec);
}

void Vec2f::operator*=(Mat2f mat) {
	mulMat2f(mat);
}

