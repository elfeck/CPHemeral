#include "Display.h"
#include "Window.h"
#include "Log.h"
#include "RenderingSystem.h"
#include "LogicSystem.h"
#include "SceneManager.h"
#include "ComponentAllocator.h"
#include "Unicellular.h"

#define VERSION "0.1a"


using namespace cph;

Display* display = 0;
Window* window = 0;

RenderingSystem* renderingSystem = 0;
LogicSystem* logicSystem = 0;

SceneManager scenes;
ComponentAllocator compAlloc;

Log errorLog("error");
Log debugLog("debug");
Log looptimeLog("looptime");

void mainCallback(long delta);
void renderCallback(long delta);

void initLogs(bool debug, bool looptime);
void initDisplay(int argc, char** argv);

void initRenderingSystem();
void initLogicSystem();

void initScenes();
void cleanup();

int main(int argc, char** argv) {
	initLogs(true, true);
	initDisplay(argc, argv);

	initRenderingSystem();
	initLogicSystem();
	initScenes();

	display->enterMainLoop();

	cleanup();
	system("pause");
}

void mainCallback(long delta) {
	if(scenes.getCurrentObjManager() != 0) logicSystem->execute(scenes.getCurrentObjManager(), delta);
}

void renderCallback(long delta) {
	if(scenes.getCurrentObjManager() != 0) renderingSystem->execute(scenes.getCurrentObjManager(), delta);
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
	window->setPosition(650, 0);
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
	renderingSystem = createRenderingSystem(0x01);
	renderingSystem->setLog(&errorLog);
	renderingSystem->setLog(&debugLog);
}

void initLogicSystem() {
	logicSystem = createLogicSystem(0x02);
	logicSystem->setLog(&errorLog);
	logicSystem->setLog(&debugLog);
}

void initScenes() {
	compAlloc.setRenderAlloc(renderingSystem);
	compAlloc.setLogicAlloc(logicSystem);
	scenes.init();
}

void cleanup() {
	scenes.destroy();
	deleteDisplay(display);
	deleteWindow(window);
	deleteRenderingSystem(renderingSystem);
	deleteLogicSystem(logicSystem);
}

ComponentAllocator& cph::getComponentAllocator() {
	return compAlloc;
}

void cph::setLog(ObjectManager* objectManager) {
	objectManager->setLog(&errorLog);
	objectManager->setLog(&debugLog);
}
