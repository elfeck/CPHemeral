#include <iostream>

#include "ObjectManager.h"
#include "Object.h"
#include "RenderingComponent.h"
#include "Display.h"
#include "Window.h"

using namespace cph;

void mainCallback(long delta);
void renderCallback(long delta);

Display* display = 0;
Window* window = 0;

int main(int argc, char* argv[]) {
	window = createWindow();
	display = createDisplay();

	window->setSize(480, 320);
	window->setPosition(500, 200);
	window->setTitle("Test");
	window->initWindow(&argc, argv);

	display->setDebug(true);
	display->setMainFunc(mainCallback);
	display->setRenderFunc(renderCallback);
	display->initDisplay(window);


	ObjectManager* objectManager = createObjectManager(10);
	Object* o1 = objectManager->createObject();
	Object* o2 = objectManager->createObject();
	o1->release();
	o2->release();
	deleteObjectManager(objectManager);
	
	display->enterMainLoop();

	deleteWindow(window);
	deleteDisplay(display);

	return 0;
}

void mainCallback(long delta) {

}

void renderCallback(long delta) {

}