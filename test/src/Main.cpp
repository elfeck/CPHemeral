#include <iostream>

#include "ObjectManager.h"
#include "Object.h"
#include "RenderingComponent.h"
#include "RenderingSystem.h"
#include "Display.h"
#include "Window.h"

#include "Vec1f.h"

using namespace cph;

void mainCallback(long delta);
void renderCallback(long delta);

Display* display = 0;
Window* window = 0;

ObjectManager* scene1 = 0;
RenderingSystem* renderingSystem = 0;

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

	scene1 = createObjectManager();
	renderingSystem = createRenderingSystem(0x01);
	
	// ################
	Object* obj1 = scene1->createObject();
	RenderingComponent* ren1 = renderingSystem->createComponent();
	ren1->setShader("D:/Projects/newCPHemeral/test/res/test1");
	ren1->setRenderingMode(TRIANGLES);
	obj1->addComponent(ren1);

	Object* obj2 = scene1->createObject();
	RenderingComponent* ren2 = renderingSystem->createComponent();
	ren2->setShader("D:/Projects/newCPHemeral/test/res/test2");
	ren2->setRenderingMode(LINES);
	obj2->addComponent(ren2);
	// ################

	display->enterMainLoop();

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