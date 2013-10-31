#ifndef DISPLAY_IMPL_H_
#define DISPLAY_IMPL_H_

#define VERSION "0.0.1"

#include <string>
#include <array>
#include "TimeUnit.h"

#include "../include/Display.h"
#include "Logger.h"
#include "WindowImpl.h"


namespace cph {

class DisplayImpl : public Display {

private:
	bool initialized, running;

	std::array<bool, 256> pressedKeys;
	std::array<bool, 256> releasedKeys;
	bool mouseInWindow;
	int mouseX, mouseY, mouseWheel;

	TimeUnit timeUnit;
	int printTimePassed;

	void (*mainCallback)(long);
	void (*renderCallback)(long);
	WindowImpl* window;

	cph::Logger errorLog, debugLog, looptimeLog;

	void resetKeys();
	void setSpecialKey(int key, std::array<bool, 256>* keyArray, bool value);
	
	static DisplayImpl* currentDisplay;
	
	static void display_callback();
	static void close_callback();
	static void reshape_callback(int width, int height);

	static void normalKeyPressed_callback(unsigned char key, int x, int y);
	static void normalKeyReleased_callback(unsigned char key, int x, int y);
	static void specialKeyPressed_callback(int key, int x, int y);
	static void specialKeyReleased_callback(int key, int x, int y);
	
	static void mouseKey_callback(int button, int state, int x, int y);
	static void mouseMotionDrag_callback(int x, int y);
	static void mouseMotionPassive_callback(int x, int y);
	static void mouseWheel_callback(int wheel, int direction, int x, int y);
	static void mouseEntry_callback(int state);

	static void setMouseCoords(int x, int y);

public:
	DisplayImpl();
	~DisplayImpl();

	virtual void initDisplay(Window* window);
	virtual void setMainFunc(void (*)(long));
	virtual void setRenderFunc(void (*)(long));	
	virtual void setWindow(Window* window);

	virtual void enterMainLoop();
	virtual void exitMainLoop();

	virtual bool isKeyPressed(unsigned char keyId) const;
	virtual bool isKeyReleased(unsigned char keyId) const;
	virtual bool isMouseInWindow() const;
	
	virtual int getMouseX() const;
	virtual int getMouseY() const;
	virtual int getMouseWheel() const;

	virtual void setLog(cph::Log* log, const char* target);

	static const DisplayImpl* getCurrentDisplay();
	static void setCurrentDisplay(Display* display);
};

};


#endif