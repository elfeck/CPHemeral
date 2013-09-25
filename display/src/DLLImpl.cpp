#include "../include/Display.h"
#include "../include/Window.h"

#include "FreeglutDisplay.h"
#include "FreeglutWindow.h"



cph::Display* cph::createDisplay() {
	Display* display = new cph::FreeglutDisplay();
	FreeglutDisplay::setCurrentDisplay(display);
	return display;
}

void cph::deleteDisplay(cph::Display* display) {
	if(FreeglutDisplay::getCurrentDisplay() == display) FreeglutDisplay::setCurrentDisplay(0);
	delete display;
}

cph::Window* cph::createWindow() {
	return new cph::FreeglutWindow();
}

void cph::deleteWindow(cph::Window* window) {
	delete window;
}
