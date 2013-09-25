#include <gl\glew.h>
#include <gl\freeglut.h>
#include <iostream>

#include "FreeglutDisplay.h"

#include "FreeglutWindow.h"


using namespace cph;

FreeglutWindow::FreeglutWindow() :
	width(1), height(1), posX(0), posY(0), 
	fullscreen(false), initialized(false)
{

}

FreeglutWindow::~FreeglutWindow() {

}

void FreeglutWindow::initWindow(int* argc, char* argv[]) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(posX, posY);

	const char* newTitle = title.append(" using CPHemeral ").append(VERSION).c_str();
	glutCreateWindow(newTitle);
	if(fullscreen) glutFullScreen();
	initialized = true;
}

int FreeglutWindow::getWidth() const {
	return width;
}

int FreeglutWindow::getHeight() const {
	return height;
}

int FreeglutWindow::getPositionX() const {
	return posX;
}

int FreeglutWindow::getPositionY() const {
	return posY;
}

bool FreeglutWindow::isFullscreen() const {
	return fullscreen;
}

const char* FreeglutWindow::getTitle() const {
	return title.c_str();
}

void FreeglutWindow::setSize(int width, int height) {
	this->width = width;
	this->height = height;
	if(initialized) glutReshapeWindow(width, height);
}

void FreeglutWindow::setPosition(int x, int y) {
	posX = x;
	posY = y;
	if(initialized) glutPositionWindow(x, y);
}

void FreeglutWindow::setFullscreen(bool fullscreen) {
	this->fullscreen = fullscreen;
	if(initialized) {
		if(!this->fullscreen && fullscreen) glutFullScreen();
		else if(this->fullscreen && !fullscreen) glutLeaveFullScreen();
	}
}

void FreeglutWindow::setTitle(const char* title) {
	this->title = title;
	if(initialized) {
		const char* newTitle = this->title.append(" using CPHemeral ").append(VERSION).c_str();
		glutSetWindowTitle(newTitle);
	}
}

void FreeglutWindow::setIcon(const char* iconPath) {

}

bool FreeglutWindow::isInitialized() {
	return initialized;
}


void FreeglutWindow::setWidth(int width) {
	this->width = width;
}

void FreeglutWindow::setHeight(int height) {
	this->height = height;
}