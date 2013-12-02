#include <gl\glew.h>
#include <gl\freeglut.h>
#include <iostream>
#include "DisplayImpl.h"


using namespace cph;

DisplayImpl* DisplayImpl::currentDisplay = 0;

const DisplayImpl* DisplayImpl::getCurrentDisplay() {
	return currentDisplay;
}

void DisplayImpl::setCurrentDisplay(Display* display) {
	currentDisplay = dynamic_cast<DisplayImpl*>(display);
}

void DisplayImpl::display_callback() {
	if(currentDisplay->renderCallback != 0) currentDisplay->renderCallback(0);
}

void DisplayImpl::close_callback() {
	currentDisplay->exitMainLoop();
}

void DisplayImpl::reshape_callback(int width, int height) {
	currentDisplay->window->setWidth(width);
	currentDisplay->window->setHeight(height);
	// should be in GLContext thread
	glViewport(0, 0, width, height);
	glScissor(0, 0, width, height);
}

void DisplayImpl::normalKeyPressed_callback(unsigned char key, int x, int y) {
	currentDisplay->pressedKeys.at(key) = true;
	setMouseCoords(x, y);
}

void DisplayImpl::normalKeyReleased_callback(unsigned char key, int x, int y) {
	currentDisplay->releasedKeys.at(key) = true;
	currentDisplay->pressedKeys.at(key) = false;
	setMouseCoords(x, y);
}

void DisplayImpl::specialKeyPressed_callback(int key, int x, int y) {
	currentDisplay->setSpecialKey(key, &currentDisplay->pressedKeys, true);
	setMouseCoords(x, y);
}

void DisplayImpl::specialKeyReleased_callback(int key, int x, int y) {
	currentDisplay->setSpecialKey(key, &currentDisplay->releasedKeys, true);
	currentDisplay->setSpecialKey(key, &currentDisplay->pressedKeys, false);
	setMouseCoords(x, y);
}

void DisplayImpl::mouseKey_callback(int button, int state, int x, int y) {
	if(state == GLUT_DOWN) {
		switch(button) {
		case GLUT_LEFT_BUTTON: currentDisplay->pressedKeys.at(Mouse::LEFT) = true; break;
		case GLUT_MIDDLE_BUTTON: currentDisplay->pressedKeys.at(Mouse::MIDDLE) = true; break;
		case GLUT_RIGHT_BUTTON: currentDisplay->pressedKeys.at(Mouse::RIGHT) = true; break;
		}
	} else {
		switch(button) {
		case GLUT_LEFT_BUTTON: 
			currentDisplay->releasedKeys.at(Mouse::LEFT) = true;
			currentDisplay->pressedKeys.at(Mouse::LEFT) = false; break;
		case GLUT_MIDDLE_BUTTON:
			currentDisplay->releasedKeys.at(Mouse::MIDDLE) = true;
			currentDisplay->pressedKeys.at(Mouse::MIDDLE) = false; break;
		case GLUT_RIGHT_BUTTON:
			currentDisplay->releasedKeys.at(Mouse::RIGHT) = true;
			currentDisplay->pressedKeys.at(Mouse::RIGHT) = false; break;
		}
	}
	setMouseCoords(x, y);
}

void DisplayImpl::mouseMotionDrag_callback(int x, int y) {
	currentDisplay->pressedKeys.at(Mouse::DRAG) = true;
	setMouseCoords(x, y);
}

void DisplayImpl::mouseMotionPassive_callback(int x, int y) {
	if(currentDisplay->pressedKeys.at(Mouse::DRAG)) {
		currentDisplay->releasedKeys.at(Mouse::DRAG) = true;
		currentDisplay->pressedKeys.at(Mouse::DRAG) = false;
	}
	setMouseCoords(x, y);
}

void DisplayImpl::mouseWheel_callback(int wheel, int direction, int x, int y) {
	currentDisplay->mouseWheel = direction;
	setMouseCoords(x, y);
}

void DisplayImpl::mouseEntry_callback(int state) {
	currentDisplay->mouseInWindow = state == GLUT_ENTERED;
}

void DisplayImpl::setMouseCoords(int x, int y) {
	currentDisplay->mouseX = x;
	currentDisplay->mouseY = y;
}

DisplayImpl::DisplayImpl() :
	initialized(false), running(false),
	pressedKeys(std::array<bool, 256>()), releasedKeys(std::array<bool, 256>()),
	mouseX(-1), mouseY(-1), mouseWheel(0), mouseInWindow(false),
	timeUnit(), printTimePassed(1000), looptimeLogTime(1000), mainCallback(0), renderCallback(0), window(0),
	errorLog("[ Display  ]"), debugLog("[ Display  ]"), looptimeLog("[ Looptime ]")
{
	errorLog.setLocalWriteToBuffer(true);
}

DisplayImpl::~DisplayImpl() {

}

void DisplayImpl::resetKeys() {
	for(std::array<bool, 256>::size_type i = 0; i < pressedKeys.size() && i < releasedKeys.size(); i++) {
		releasedKeys.at(i) = false;
	}
	mouseWheel = 0;
}

void DisplayImpl::setSpecialKey(int key, std::array<bool, 256>* keyArray, bool value) {
	switch(key) {
	case GLUT_KEY_LEFT: keyArray->at(Key::ARROW_LEFT) = value; break;
	case GLUT_KEY_UP: keyArray->at(Key::ARROW_UP) = value; break;
	case GLUT_KEY_RIGHT: keyArray->at(Key::ARROW_RIGHT) = value; break;
	case GLUT_KEY_DOWN: keyArray->at(Key::ARROW_DOWN) = value; break;

	case GLUT_KEY_F1: keyArray->at(Key::F1) = value; break;
	case GLUT_KEY_F2: keyArray->at(Key::F2) = value; break;
	case GLUT_KEY_F3: keyArray->at(Key::F3) = value; break;
	case GLUT_KEY_F4: keyArray->at(Key::F4) = value; break;
	case GLUT_KEY_F5: keyArray->at(Key::F5) = value; break;
	case GLUT_KEY_F6: keyArray->at(Key::F6) = value; break;
	case GLUT_KEY_F7: keyArray->at(Key::F7) = value; break;
	case GLUT_KEY_F8: keyArray->at(Key::F8) = value; break;
	case GLUT_KEY_F9: keyArray->at(Key::F9) = value; break;
	case GLUT_KEY_F10: keyArray->at(Key::F10) = value; break;
	case GLUT_KEY_F11: keyArray->at(Key::F11) = value; break;
	case GLUT_KEY_F12: keyArray->at(Key::F12) = value; break;
			
	case GLUT_KEY_SHIFT_L: keyArray->at(Key::SHIFT_L) = value; break;
	case GLUT_KEY_SHIFT_R: keyArray->at(Key::SHIFT_R) = value; break;
	case GLUT_KEY_ALT_L: keyArray->at(Key::ALT_L) = value; break;
	case GLUT_KEY_ALT_R: keyArray->at(Key::ALT_R) = value; break;
	}
}

void DisplayImpl::initDisplay(Window* window) {
	setWindow(window);
	glewExperimental = true;
	if(GLEW_OK != glewInit()) {
		errorLog.logMessage("GL Context could not be initialized. Error with glew!");
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
	glutEntryFunc(mouseEntry_callback);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_SCISSOR_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	initialized = true;
}

void DisplayImpl::setMainFunc(void (*mainFunc)(double)) {
	mainCallback = mainFunc;
}

void DisplayImpl::setRenderFunc(void (*renderFunc)(double)) {
	renderCallback = renderFunc;
}

void DisplayImpl::setWindow(Window* window) {
	this->window = dynamic_cast<WindowImpl*>(window);
}

void DisplayImpl::enterMainLoop() {
	if(window != 0 && mainCallback != 0 && renderCallback != 0) {
		if(window->isInitialized() && initialized) {
			running = true;
			while(running) {
				timeUnit.start();

				glutMainLoopEvent();

				if(!running) break;
				mainCallback(timeUnit.getDelta());

				if(!running) break;
				glClear(GL_COLOR_BUFFER_BIT);
				renderCallback(timeUnit.getDelta());

				if(!running) break;
				glutSwapBuffers();
				resetKeys();
				
				timeUnit.end();
				if(printTimePassed >= looptimeLogTime) {
						looptimeLog.pre() << timeUnit.getDelta() << "ms -- " << timeUnit.getAverage() << "ms" << std::endl;
						printTimePassed = 0;
				} else {
					printTimePassed += timeUnit.getDelta();
				}
			}
		} else errorLog.logMessage("Window or Display not initialized!");
	} else errorLog.logMessage("Window or main/render callback not set!");
}

void DisplayImpl::exitMainLoop() {
	running = false;
}

bool DisplayImpl::isKeyPressed(unsigned char keyId) const {
	return pressedKeys[keyId];
}

bool DisplayImpl::isKeyReleased(unsigned char keyId) const {
	return releasedKeys[keyId];
}

bool DisplayImpl::isMouseInWindow() const {
	return mouseInWindow;
}

int DisplayImpl::getMouseX() const {
	return mouseX;
}

int DisplayImpl::getMouseY() const {
	return mouseY;
}

int DisplayImpl::getMouseWheel() const {
	return mouseWheel;
}

void DisplayImpl::setLog(Log* log, const char* target) {
	if(log != 0) {
		if(log->getTarget() == "error") {
			errorLog.setLogPtr(log);
			timeUnit.setLog(log, "error", "[ Looptime ]");
		}
		if(log->getTarget() == "debug") debugLog.setLogPtr(log);
		if(log->getTarget() == "looptime") looptimeLog.setLogPtr(log);
	} else if(target != 0) {
		if(strcmp(target, "error") == 0) {
			errorLog.setLogPtr(0);
			timeUnit.setLog(0, target);
		}
		if(strcmp(target, "debug") == 0) debugLog.setLogPtr(0);
		if(strcmp(target, "looptime") == 0) looptimeLog.setLogPtr(0);
	}
}

void DisplayImpl::setLooptimeLogTime(int ms) {
	this->printTimePassed = ms;
	this->looptimeLogTime = ms;
}

