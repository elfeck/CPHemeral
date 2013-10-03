#include "../../include/Vec1f.h"


using namespace cph;

Vec1f::Vec1f(float x) :
	Vecf(), x(x)
{

}

Vec1f::~Vec1f() {

}


Vec1f* Vec1f::addVec1f(Vec1f* vec) {
	x += vec->x;
	return this;
}

Vec1f* Vec1f::subVec1f(Vec1f* vec) {
	x -= vec->x;
	return this;
}

Vec1f* Vec1f::mulVec1f(Vec1f* vec) {
	x *= vec->x;
	return this;
}

Vec1f* Vec1f::divVec1f(Vec1f* vec) {
	if(vec->x != 0) {
		x /= vec->x;
	}
	return this;
}


Vec1f* Vec1f::addVec1f(Vec1f vec) {
	x += vec.x;
	return this;
}

Vec1f* Vec1f::subVec1f(Vec1f vec) {
	x -= vec.x;
	return this;
}

Vec1f* Vec1f::mulVec1f(Vec1f vec) {
	x *= vec.x;
	return this;
}

Vec1f* Vec1f::divVec1f(Vec1f vec) {
	if(vec.x != 0) {
		x /= vec.x;
	}
	return this;
}



Vec1f* Vec1f::addVec1f(float vx) {
	x += vx;
	return this;
}

Vec1f* Vec1f::subVec1f(float vx) {
	x -= vx;
	return this;
}

Vec1f* Vec1f::mulVec1f(float vx) {
	x *= vx;
	return this;
}

Vec1f* Vec1f::divVec1f(float vx) {
	if(vx != 0) {
		x /= vx;
	}
	return this;
}


float Vec1f::dot(Vec1f* vec) {
	return x * vec->x;
}

float Vec1f::dot(Vec1f vec) {
	return x * vec.x;
}

Vec1f* Vec1f::mulScalar(float value) {
	x *= value;
	return this;
}

Vec1f* Vec1f::normalize() {
	x = 1;
	return this;
}

Vec1f* Vec1f::toLength(float value) {
	x = value;
	return this;
}

Vec1f* Vec1f::negate() {
	return mulScalar(-1.0f);
}



Vec1f* Vec1f::setX(float newX) {
	x = newX;
	return this;
}

Vec1f* Vec1f::setVec(Vec1f* vec) {
	x = vec->x;
	return this;
}

Vec1f* Vec1f::setVec(Vec1f vec) {
	x = vec.x;
	return this;
}

float Vec1f::getX() {
	return x;
}


Vecf* Vec1f::setN(int n, float value) {
	if(n == 0) x = value;
	return this;
}

float Vec1f::getN(int n) {
	if(n == 0) return x;
	return 0;
}

int Vec1f::getDim() {
	return 1;
}

Vec1f* Vec1f::copyInto(Vec1f* raw) {
	return raw->setVec(this);
}


void Vec1f::operator+=(Vec1f* vec) {
	addVec1f(vec);
}

void Vec1f::operator-=(Vec1f* vec) {
	subVec1f(vec);
}

void Vec1f::operator*=(Vec1f* vec) {
	mulVec1f(vec);
}

void Vec1f::operator/=(Vec1f* vec) {
	divVec1f(vec);
}


void Vec1f::operator+=(Vec1f vec) {
	addVec1f(vec);
}

void Vec1f::operator-=(Vec1f vec) {
	subVec1f(vec);
}

void Vec1f::operator*=(Vec1f vec) {
	mulVec1f(vec);
}

void Vec1f::operator/=(Vec1f vec) {
	divVec1f(vec);
}