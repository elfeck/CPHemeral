#include "ObjectManager.h"
#include "Object.h"
#include "RenderingComponent.h"
#include "Display.h"
#include "Window.h"


using namespace cph;

void mainCallback(long delta);
void renderCallback(long delta);

int main(int argc, char* argv[]) {
	Window* window = createWindow();
	Display* display = createDisplay();

	window->setSize(480, 360);
	window->setPosition(1000, 200);
	window->setTitle("Test");
	window->initWindow(&argc, argv);

	display->setDebug(true);
	display->setMainFunc(mainCallback);
	display->setRenderFunc(renderCallback);
	display->initDisplay(window);

	display->enterMainLoop();

	deleteWindow(window);
	deleteDisplay(display);

	/*
	ObjectManager* objectManager = createObjectManager(10);
	Object* o1 = objectManager->registerObject();
	Object* o2 = objectManager->registerObject();
	o1->release();
	o2->release();
	deleteObjectManager(objectManager);
	*/

	return 0;
}

void mainCallback(long delta) {

}

void renderCallback(long delta) {

}