#include <gl\glew.h>
#include <gl\freeglut.h>
#include <iostream>

#include "FreeglutDisplay.h"


using namespace cph;

FreeglutDisplay* FreeglutDisplay::currentDisplay = 0;

const FreeglutDisplay* FreeglutDisplay::getCurrentDisplay() {
	return currentDisplay;
}

void FreeglutDisplay::setCurrentDisplay(Display* display) {
	currentDisplay = dynamic_cast<FreeglutDisplay*>(display);
}

void FreeglutDisplay::display_callback() {
	if(currentDisplay->renderCallback != 0) currentDisplay->renderCallback(0);
}

void FreeglutDisplay::close_callback() {
	currentDisplay->exitMainLoop();
}

void FreeglutDisplay::reshape_callback(int width, int height) {
	currentDisplay->window->setWidth(width);
	currentDisplay->window->setHeight(height);
	// should be in GLContext thread
	glViewport(0, 0, width, height);
	glScissor(0, 0, width, height);
}

void FreeglutDisplay::normalKeyPressed_callback(unsigned char key, int x, int y) {
	currentDisplay->pressedKeys.at(key) = true;
	setMouseCoords(x, y);
}

void FreeglutDisplay::normalKeyReleased_callback(unsigned char key, int x, int y) {
	currentDisplay->releasedKeys.at(key) = true;
	setMouseCoords(x, y);
}

void FreeglutDisplay::specialKeyPressed_callback(int key, int x, int y) {
	currentDisplay->setSpecialKey(key, &currentDisplay->pressedKeys);
	setMouseCoords(x, y);
}

void FreeglutDisplay::specialKeyReleased_callback(int key, int x, int y) {
	currentDisplay->setSpecialKey(key, &currentDisplay->releasedKeys);
	setMouseCoords(x, y);
}

void FreeglutDisplay::mouseKey_callback(int button, int state, int x, int y) {
	std::array<bool, 256>* mouseArray = state == GLUT_DOWN ? &currentDisplay->pressedKeys : &currentDisplay->releasedKeys;
	switch(button) {
	case GLUT_LEFT_BUTTON: mouseArray->at(Mouse::LEFT) = true; break;
	case GLUT_MIDDLE_BUTTON: mouseArray->at(Mouse::MIDDLE) = true; break;
	case GLUT_RIGHT_BUTTON: mouseArray->at(Mouse::RIGHT) = true; break;
	}
	setMouseCoords(x, y);
}

void FreeglutDisplay::mouseMotionDrag_callback(int x, int y) {
	currentDisplay->pressedKeys.at(Mouse::DRAG) = true;
	setMouseCoords(x, y);
}

void FreeglutDisplay::mouseMotionPassive_callback(int x, int y) {
	if(currentDisplay->pressedKeys.at(Mouse::DRAG)) currentDisplay->releasedKeys.at(Mouse::DRAG) = true;
	setMouseCoords(x, y);
}

void FreeglutDisplay::mouseWheel_callback(int wheel, int direction, int x, int y) {
	currentDisplay->mouseWheel = direction;
	setMouseCoords(x, y);
}

void FreeglutDisplay::setMouseCoords(int x, int y) {
	currentDisplay->mouseX = x;
	currentDisplay->mouseY = y;
}

FreeglutDisplay::FreeglutDisplay() :
	debug(false), initialized(false), running(false),
	pressedKeys(std::array<bool, 256>()), releasedKeys(std::array<bool, 256>()),
	mouseX(-1), mouseY(-1), mouseWheel(0),
	timeUnit(), printTimePassed(2000), mainCallback(0), renderCallback(0), window(0)
{

}

FreeglutDisplay::~FreeglutDisplay() {

}

void FreeglutDisplay::resetKeys() {
	for(std::array<bool, 256>::size_type i = 0; i < pressedKeys.size() && i < releasedKeys.size(); i++) {
		pressedKeys.at(i) = false;
		releasedKeys.at(i) = false;
	}
}

void FreeglutDisplay::setSpecialKey(int key, std::array<bool, 256>* keyArray) {
	switch(key) {
	case GLUT_KEY_LEFT: keyArray->at(Key::ARROW_LEFT) = true; break;
	case GLUT_KEY_UP: keyArray->at(Key::ARROW_UP) = true; break;
	case GLUT_KEY_RIGHT: keyArray->at(Key::ARROW_RIGHT) = true; break;
	case GLUT_KEY_DOWN: keyArray->at(Key::ARROW_DOWN) = true; break;

	case GLUT_KEY_F1: keyArray->at(Key::F1) = true; break;
	case GLUT_KEY_F2: keyArray->at(Key::F2) = true; break;
	case GLUT_KEY_F3: keyArray->at(Key::F3) = true; break;
	case GLUT_KEY_F4: keyArray->at(Key::F4) = true; break;
	case GLUT_KEY_F5: keyArray->at(Key::F5) = true; break;
	case GLUT_KEY_F6: keyArray->at(Key::F6) = true; break;
	case GLUT_KEY_F7: keyArray->at(Key::F7) = true; break;
	case GLUT_KEY_F8: keyArray->at(Key::F8) = true; break;
	case GLUT_KEY_F9: keyArray->at(Key::F9) = true; break;
	case GLUT_KEY_F10: keyArray->at(Key::F10) = true; break;
	case GLUT_KEY_F11: keyArray->at(Key::F11) = true; break;
	case GLUT_KEY_F12: keyArray->at(Key::F12) = true; break;
			
	case GLUT_KEY_SHIFT_L: keyArray->at(Key::SHIFT_L) = true; break;
	case GLUT_KEY_SHIFT_R: keyArray->at(Key::SHIFT_R) = true; break;
	case GLUT_KEY_ALT_L: keyArray->at(Key::ALT_L) = true; break;
	case GLUT_KEY_ALT_R: keyArray->at(Key::ALT_R) = true; break;
	}
}

void FreeglutDisplay::initDisplay(Window* window) {
	setWindow(window);
	glewExperimental = true;
	if(GLEW_OK != glewInit()) {
		if(debug) std::cout << "GL Context could not be initialized. Error with glew!" << std::endl;
		return;
	}
	glutDisplayFunc(display_callback);
	glutCloseFunc(close_callback);
	glutReshapeFunc(reshape_callback);

	glutKeyboardFunc(normalKeyPressed_callback);
	glutSpecialFunc(specialKeyPressed_callback);
	glutKeyboardUpFunc(normalKeyReleased_callback);
	glutSpecialUpFunc(specialKeyReleased_callback);

	glutMouseFunc(mouseKey_callback);
	glutMotionFunc(mouseMotionDrag_callback);
	glutPassiveMotionFunc(mouseMotionPassive_callback);
	glutMouseWheelFunc(mouseWheel_callback);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_SCISSOR_TEST);

	initialized = true;
}

void FreeglutDisplay::setMainFunc(void (*mainFunc)(long)) {
	mainCallback = mainFunc;
}

void FreeglutDisplay::setRenderFunc(void (*renderFunc)(long)) {
	renderCallback = renderFunc;
}

void FreeglutDisplay::setWindow(Window* window) {
	this->window = dynamic_cast<FreeglutWindow*>(window);
}

void FreeglutDisplay::enterMainLoop() {
	if(window != 0 && mainCallback != 0 && renderCallback != 0) {
		if(window->isInitialized() && initialized) {
			running = true;
			while(running) {
				timeUnit.enterStart(glutGet(GLUT_ELAPSED_TIME));
				
				glutMainLoopEvent();

				if(!running) break;
				mainCallback(timeUnit.getDelta());

				if(!running) break;
				glClear(GL_COLOR_BUFFER_BIT);
				renderCallback(timeUnit.getDelta());

				if(!running) break;
				glutSwapBuffers();
				resetKeys();
				
				timeUnit.enterEnd(glutGet(GLUT_ELAPSED_TIME));
				if(debug && printTimePassed >= 1000) {
						timeUnit.printAll();
						printTimePassed = 0;
				} else if(debug) {
					printTimePassed += timeUnit.getDelta();
				}
			}
		} else if(debug) std::cout << "Window or Display not initialized!" << std::endl;
	} else if(debug) std::cout << "Window or main/render callback not set!" << std::endl;
}

void FreeglutDisplay::exitMainLoop() {
	running = false;
}

bool FreeglutDisplay::isKeyPressed(unsigned char keyId) const {
	return pressedKeys[keyId];
}

bool FreeglutDisplay::isKeyReleased(unsigned char keyId) const {
	return releasedKeys[keyId];
}

int FreeglutDisplay::getMouseX() const {
	return mouseX;
}

int FreeglutDisplay::getMouseY() const {
	return mouseY;
}

int FreeglutDisplay::getMouseWheel() const {
	return mouseWheel;
}

void FreeglutDisplay::setDebug(bool debug) {
	this->debug = debug;
}

bool FreeglutDisplay::isDebug() const {
	return debug;
}