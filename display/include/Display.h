#ifndef DISPLAY_H_
#define DISPLAY_H_

#ifdef DISPLAY_EXPORTS
#define CPH_DISPLAY_DLL _declspec(dllexport)
#else
#define CPH_DISPLAY_DLL _declspec(dllimport)
#endif

#include "Input.h"


namespace cph {

struct Window;
class Log;

struct Display : Input {

	virtual void initDisplay(Window* window) = 0;
	virtual void setMainFunc(void (*mainFunc)(long)) = 0;
	virtual void setRenderFunc(void (*renderFunc)(long)) = 0;
	virtual void setWindow(Window* window) = 0;

	virtual void enterMainLoop() = 0;
	virtual void exitMainLoop() = 0;

	virtual bool isKeyPressed(unsigned char keyId) const = 0;
	virtual bool isKeyReleased(unsigned char keyId) const = 0;
	virtual bool isMouseInWindow() const = 0;

	virtual int getMouseX() const = 0;
	virtual int getMouseY() const = 0;
	virtual int getMouseWheel() const = 0;

	virtual void setLog(cph::Log* log, const char* target = 0) = 0;
	virtual void setLooptimeLogTime(int ms) = 0;

	virtual ~Display() = 0;

};

extern "C" {	
	CPH_DISPLAY_DLL Display* createDisplay();
	CPH_DISPLAY_DLL void deleteDisplay(Display* display);
}

}

#endif