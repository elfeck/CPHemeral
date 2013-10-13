#include <iostream>

#include "ObjectManager.h"
#include "Object.h"
#include "RenderingComponent.h"
#include "RenderingSystem.h"
#include "Display.h"
#include "Window.h"

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
	RenderingComponent* comp1 = renderingSystem->createComponent();

	RenderGeom* geom = comp1->createGeom();
	RenderVertex* vert = comp1->createVertex();
	RenderUniform* uni = comp1->createUniform();
	PrmiVec4f* vec4 = comp1->createVec4f("pos", 1.0f, 2.0f, 3.0f, 4.0f);

	uni->addUniformPrimitive(vec4);
	vert->addVertexPrimitive(vec4);

	geom->addVertex(vert);
	obj1->addComponent(comp1);
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