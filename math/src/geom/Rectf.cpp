#include "../../include/Rectf.h"


using namespace cph;

Rectf::Rectf(float x, float y, float width, float height) :
	x(x), y(y), width(width), height(height)
{

}

Rectf::~Rectf() {

}

float Rectf::getX() {
	return x;
}

float Rectf::getY() {
	return y;
}

float Rectf::getWidth() {
	return width;
}

float Rectf::getHeight() {
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
