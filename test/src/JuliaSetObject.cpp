#include <iostream>
#include "JuliaSetObject.h"
#include "Display.h"


using namespace cph;

JuliaSetObject::JuliaSetObject() :
	object(0), render(0), zoom(0), c(0)
{

}

JuliaSetObject::~JuliaSetObject() {

}

void JuliaSetObject::create(ObjectManager* scene, RenderingSystem* sys) {
	object = scene->createObject();
	render = sys->createComponent();
	
	render->setRenderMode(TRIANGLES);
	render->setShader("D://Projects/C++/CPHemeral/test/res/juliaset");
	render->setViewport(0, 0, 400, 400);
	render->setScissor(0, 0, 400, 400);
	render->setVisible(true);

	RenderVertex* vert1 = render->addLocalVertex();
	RenderVertex* vert2 = render->addLocalVertex();
	RenderVertex* vert3 = render->addLocalVertex();
	RenderVertex* vert4 = render->addLocalVertex();

	RenderUniform* uni1 = render->addLocalUniform();
	RenderUniform* uni2 = render->addLocalUniform();
	RenderUniform* uni3 = render->addLocalUniform();

	RenderGeom* geom1 = render->addLocalGeom();
	RenderGeom* geom2 = render->addLocalGeom();

	vert1->addVec4f("vert_position", -1.0f, 1.0f, 0, 1);
	vert2->addVec4f("vert_position", 1.0f, 1.0f, 0, 1);
	vert3->addVec4f("vert_position", 1.0f, -1.0f, 0, 1);
	vert4->addVec4f("vert_position", -1.0f, -1.0f, 0, 1);

	zoom = uni1->addVec1f("zoom", 1.0f);
	c = uni2->addVec2f("c", 0, 0);
	camera = uni3->addVec2f("camera", 0, 0);

	geom1->addVertex(vert1);
	geom1->addVertex(vert2);
	geom1->addVertex(vert3);

	geom2->addVertex(vert1);
	geom2->addVertex(vert3);
	geom2->addVertex(vert4);

	object->addComponent(render);
}

void JuliaSetObject::destroy() {
	render->destroy();
	object->destroy();
}

bool JuliaSetObject::isVisible() {
	return render->isVisible();
}

void JuliaSetObject::setVisible(bool visible) {
	render->setVisible(visible);
}

void JuliaSetObject::move(float dx, float dy) {
	camera->get()->addVec2f(dx * zoom->get()->getX(), dy * zoom->get()->getX());
}

void JuliaSetObject::doZoom(float margin) {
	zoom->get()->mulScalar(margin);
}

void JuliaSetObject::switchConstant(int examp) {
	switch(examp) {
	case 0: camera->get()->setXY(0, 0); zoom->get()->setX(1.0f); c->get()->setXY(0, 0); break;
	case 1: camera->get()->setXY(0, 0); zoom->get()->setX(1.0f); c->get()->setXY(0.285f, 0.01f); break;
	case 2: camera->get()->setXY(0, 0); zoom->get()->setX(1.0f); c->get()->setXY(-0.6f, 0.4f); break;
	case 3: camera->get()->setXY(0, 0); zoom->get()->setX(1.0f); c->get()->setXY(-0.8f, 0.156f); break;
	}
}
