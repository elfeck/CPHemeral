#include <gl\glew.h>
#include <gl\freeglut.h>
#include <iostream>

#include "DisplayImpl.h"

#include "WindowImpl.h"


using namespace cph;

WindowImpl::WindowImpl() :
	width(1), height(1), posX(0), posY(0), 
	fullscreen(false), initialized(false)
{

}

WindowImpl::~WindowImpl() {

}

void WindowImpl::initWindow(int* argc, char* argv[]) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(posX, posY);

	const char* newTitle = title.append(" using CPHemeral ").append(VERSION).c_str();
	glutCreateWindow(newTitle);
	if(fullscreen) glutFullScreen();
	initialized = true;
}

int WindowImpl::getWidth() const {
	return width;
}

int WindowImpl::getHeight() const {
	return height;
}

int WindowImpl::getPositionX() const {
	return posX;
}

int WindowImpl::getPositionY() const {
	return posY;
}

bool WindowImpl::isFullscreen() const {
	return fullscreen;
}

const char* WindowImpl::getTitle() const {
	return title.c_str();
}

void WindowImpl::setSize(int width, int height) {
	this->width = width;
	this->height = height;
	if(initialized) glutReshapeWindow(width, height);
}

void WindowImpl::setPosition(int x, int y) {
	posX = x;
	posY = y;
	if(initialized) glutPositionWindow(x, y);
}

void WindowImpl::setFullscreen(bool fullscreen) {
	this->fullscreen = fullscreen;
	if(initialized) {
		if(!this->fullscreen && fullscreen) glutFullScreen();
		else if(this->fullscreen && !fullscreen) glutLeaveFullScreen();
	}
}

void WindowImpl::setTitle(const char* title) {
	this->title = title;
	if(initialized) {
		const char* newTitle = this->title.append(" using CPHemeral ").append(VERSION).c_str();
		glutSetWindowTitle(newTitle);
	}
}

void WindowImpl::setIcon(const char* iconPath) {

}

bool WindowImpl::isInitialized() {
	return initialized;
}


void WindowImpl::setWidth(int width) {
	this->width = width;
}

void WindowImpl::setHeight(int height) {
	this->height = height;
}