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

	ObjectManager* objectManager = createObjectManager();
	RenderingSystem* renderingSystem = createRenderingSystem();
	objectManager->addSystem(renderingSystem);

	Object* o1 = objectManager->createObject();
	RenderingComponent* rcomp1 = renderingSystem->createComponent();
	o1->addComponent(rcomp1);
	Vertex* v1 = rcomp1->addVertex();
	Uniform* u1 = rcomp1->addUniform();
	v1->addAttributeVec("bla", 0);
	u1->addUniformVec("bla", 0);
	v1->destroy();
	u1->destroy();
	o1->removeComponent(rcomp1);
	rcomp1->destroy();
	o1->destroy();
	
	display->enterMainLoop();

	deleteObjectManager(objectManager);
	deleteWindow(window);
	deleteDisplay(display);

	return 0;
}

void mainCallback(long delta) {

}

void renderCallback(long delta) {

}