#include <iostream>

#include "ObjectManager.h"
#include "Object.h"
#include "RenderingSystem.h"
#include "LogicSystem.h"
#include "Display.h"
#include "Window.h"
#include "Log.h"

#include "JuliaSetObject.h"

using namespace cph;

void mainCallback(double delta);
void renderCallback(double delta);

Display* display = 0;
Window* window = 0;

ObjectManager* scene1 = 0;
RenderingSystem* renderingSystem = 0;
LogicSystem* logicSystem = 0;

Log errorLog("error");
Log debugLog("debug");
Log looptimeLog("looptime");

JuliaSetObject juliaObj;

void handleJuliaInput(long delta);

int main(int argc, char* argv[]) {
	errorLog.setConsolePrintOnLog(true);
	errorLog.setWriteToBuffer(true);
	debugLog.setConsolePrintOnLog(true);
	looptimeLog.setConsolePrintOnLog(true);
	
	window = createWindow();
	display = createDisplay();

	window->setSize(400, 400);
	window->setPosition(500, 200);
	window->setTitle("Test");
	window->initWindow(&argc, argv);

	display->setMainFunc(mainCallback);
	display->setRenderFunc(renderCallback);
	display->initDisplay(window);

	display->setLog(&errorLog);
	display->setLog(&debugLog);
	display->setLog(&looptimeLog);
	display->setLooptimeLogTime(5000);

	renderingSystem = createRenderingSystem(0x01);
	logicSystem = createLogicSystem(0x02);

	renderingSystem->setLog(&errorLog);
	renderingSystem->setLog(&debugLog);

	logicSystem->setLog(&errorLog);
	logicSystem->setLog(&debugLog);

	scene1 = createObjectManager();
	scene1->setLog(&debugLog);
	// ################
	juliaObj.create(scene1, renderingSystem, logicSystem);
	// ################

	display->enterMainLoop();

	// ################
	juliaObj.destroy();
	// ################


	deleteRenderingSystem(renderingSystem);
	deleteLogicSystem(logicSystem);
	deleteObjectManager(scene1);

	deleteWindow(window);
	deleteDisplay(display);

	return 0;
}

void mainCallback(double delta) {
	if(display->isKeyReleased(Key::NUM_1)) {
		juliaObj.setVisible(true);
	}
	if(display->isKeyReleased(Key::NUM_2)) {
		juliaObj.setVisible(false);
	}
	if(juliaObj.isVisible()) handleJuliaInput(delta);
	logicSystem->execute(scene1, delta);
}

void renderCallback(double delta) {
	renderingSystem->execute(scene1, delta);
}

void handleJuliaInput(long delta) {
	float speed = 0.005f;
	float zoom = 1 - delta * 0.001f;

	if(display->isKeyPressed(Key::A)) juliaObj.move(-speed * delta, 0);
	if(display->isKeyPressed(Key::W)) juliaObj.move(0, speed * delta);
	if(display->isKeyPressed(Key::D)) juliaObj.move(speed * delta, 0);
	if(display->isKeyPressed(Key::S)) juliaObj.move(0, -speed * delta);
	if(display->isKeyPressed(Key::SPACE)) juliaObj.doZoom(zoom);
	if(display->isKeyPressed(Key::F)) juliaObj.doZoom(2 - zoom);
	if(display->isKeyReleased(Key::H)) juliaObj.switchConstant(0);
	if(display->isKeyReleased(Key::J)) juliaObj.switchConstant(1);
	if(display->isKeyReleased(Key::K)) juliaObj.switchConstant(2);
	if(display->isKeyReleased(Key::L)) juliaObj.switchConstant(3);

}
