#include "../include/Display.h"
#include "../include/Window.h"

#include "DisplayImpl.h"
#include "WindowImpl.h"



cph::Display* cph::createDisplay() {
	Display* display = new cph::DisplayImpl();
	DisplayImpl::setCurrentDisplay(display);
	return display;
}

void cph::deleteDisplay(cph::Display* display) {
	if(DisplayImpl::getCurrentDisplay() == display) DisplayImpl::setCurrentDisplay(0);
	delete display;
}

cph::Window* cph::createWindow() {
	return new cph::WindowImpl();
}

void cph::deleteWindow(cph::Window* window) {
	delete window;
}

cph::Display::~Display() {

}

cph::Window::~Window() {

}


