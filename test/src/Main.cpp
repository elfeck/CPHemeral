#include <iostream>

#include "ObjectManager.h"
#include "Object.h"
#include "RenderingComponent.h"
#include "RenderingSystem.h"
#include "Display.h"
#include "Window.h"

#include "JuliaSetObject.h"

using namespace cph;

void mainCallback(long delta);
void renderCallback(long delta);

Display* display = 0;
Window* window = 0;

ObjectManager* scene1 = 0;
RenderingSystem* renderingSystem = 0;

JuliaSetObject juliaObj;

int main(int argc, char* argv[]) {
	window = createWindow();
	display = createDisplay();

	window->setSize(400, 400);
	window->setPosition(500, 200);
	window->setTitle("Test");
	window->initWindow(&argc, argv);

	display->setDebug(true);
	display->setMainFunc(mainCallback);
	display->setRenderFunc(renderCallback);
	display->initDisplay(window);

	renderingSystem = createRenderingSystem(0x01);
	scene1 = createObjectManager();
	
	// ################
	juliaObj.create(scene1, renderingSystem);
	// ################

	display->enterMainLoop();

	// ################
	juliaObj.destroy();
	// ################


	deleteRenderingSystem(renderingSystem);
	deleteObjectManager(scene1);

	deleteWindow(window);
	deleteDisplay(display);

	return 0;
}

void mainCallback(long delta) {

}

void renderCallback(long delta) {
	renderingSystem->execute(scene1, delta);
}