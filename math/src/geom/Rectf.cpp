#include "../../include/Rectf.h"


using namespace cph;

Rectf::Rectf(float x, float y, float width, float height) :
	x(x), y(y), width(width), height(height)
{

}

Rectf::~Rectf() {

}

float Rectf::getX() const {
	return x;
}

float Rectf::getY() const {
	return y;
}

float Rectf::getWidth() const {
	return width;
}

float Rectf::getHeight() const {
	return height;
}

void Rectf::setX(float x) {
	this->x = x;
}

void Rectf::setY(float y) {
	this->y = y;
}

void Rectf::setWidth(float width) {
	this->width = width;
}

void Rectf::setHeight(float height) {
	this->height = height;

}

void Rectf::setRect(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
