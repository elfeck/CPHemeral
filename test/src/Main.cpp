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

	renderingSystem = createRenderingSystem(0x01);
	scene1 = createObjectManager();
	
	// ################
	Object* obj = scene1->createObject();
	RenderingComponent* comp = renderingSystem->createComponent();
	obj->addComponent(comp);

	comp->setShader("D://Projects/C++/CPHemeral/test/res/test1");
	comp->setViewport(0, 0, 240, 320);
	comp->setScissor(0, 0, 240, 320);
	comp->setVisible(true);

	RenderVertex* vert1 = comp->addLocalVertex();
	RenderVertex* vert2 = comp->addLocalVertex();
	RenderVertex* vert3 = comp->addLocalVertex();
	RenderVertex* vert4 = comp->addLocalVertex();

	PrmiVec4f* vec1 = vert1->addVec4f("vert_position", -0.5f, 0.5f, 0, 1);
	PrmiVec4f* vec2 = vert2->addVec4f("vert_position", 0.5f, 0.5f, 0, 1);
	PrmiVec4f* vec3 = vert3->addVec4f("vert_position", 0.5f, -0.5f, 0, 1);
	PrmiVec4f* vec4 = vert4->addVec4f("vert_position", -0.5f, -0.5f, 0, 1);

	RenderGeom* geom1 = comp->addLocalGeom();
	RenderGeom* geom2 = comp->addLocalGeom();

	geom1->addVertex(vert1);
	geom1->addVertex(vert2);
	geom1->addVertex(vert3);

	geom2->addVertex(vert1);
	geom2->addVertex(vert3);
	geom2->addVertex(vert4);
	// ################

	display->enterMainLoop();

	comp->destroy();
	obj->destroy();

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