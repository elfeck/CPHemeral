#include "Display.h"
#include "Window.h"
#include "Log.h"
#include "RenderingSystem.h"

#define VERSION "0.1a"

using namespace cph;

Display* display = 0;
Window* window = 0;
RenderingSystem* renderingSystem = 0;

Log errorLog("error");
Log debugLog("debug");
Log looptimeLog("looptime");

void mainCallback(long delta);
void renderCallback(long delta);

void initLogs(bool debug, bool looptime);
void initDisplay(int argc, char** argv);
void initRenderingSystem();

void cleanup();

int main(int argc, char** argv) {
	initLogs(true, true);
	initDisplay(argc, argv);
	initRenderingSystem();

	display->enterMainLoop();

	cleanup();
}

void mainCallback(long delta) {

}

void renderCallback(long delta) {

}

void initLogs(bool debug, bool looptime) {
	errorLog.setConsolePrintOnLog(true);
	errorLog.setWriteToBuffer(true);

	debugLog.setConsolePrintOnLog(debug);
	looptimeLog.setConsolePrintOnLog(looptime);
}

void initDisplay(int argc, char** argv) {
	window = createWindow();
	window->setSize(800, 600);
	window->setPosition(0, 0);
	window->setTitle(std::string("Unicellular ").append(VERSION).c_str());
	window->initWindow(&argc, argv);

	display = createDisplay();
	display->setMainFunc(mainCallback);
	display->setRenderFunc(renderCallback);
	display->setLog(&errorLog);
	display->setLog(&debugLog);
	display->setLog(&looptimeLog);
	display->setLooptimeLogTime(7000);
	display->initDisplay(window);
}

void initRenderingSystem() {
	renderingSystem = createRenderingSystem(0x1);
	renderingSystem->setLog(&errorLog);
	renderingSystem->setLog(&debugLog);
}

void cleanup() {
	deleteDisplay(display);
	deleteWindow(window);
	deleteRenderingSystem(renderingSystem);
}
