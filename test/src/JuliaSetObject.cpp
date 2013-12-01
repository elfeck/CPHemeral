#include <iostream>
#include "JuliaSetObject.h"
#include "Display.h"
#include "RenderGeom.h"
#include "RenderVertex.h"
#include "RenderUniform.h"


using namespace cph;

JuliaSetObject::JuliaSetObject() :
	object(0), render(0), logic(0), zoom(0), c(0)
{

}

JuliaSetObject::~JuliaSetObject() {

}

void JuliaSetObject::doLogic(long delta) {

}

void JuliaSetObject::create(ObjectManager* scene, RenderingAllocator* renderSys, LogicAllocator* logicSys) {
	object = scene->createObject();
	
	render = renderSys->createComponent();
	logic = logicSys->createComponent();

	object->addComponent(render);
	object->addComponent(logic);
	
	logic->setLogicable(this);
	
	render->setRenderMode(TRIANGLES);
	render->setShader("D://Projects/C++/CPHemeral/test/res/juliaset");
	render->setViewport(0, 0, 400, 400);
	render->setScissor(0, 0, 400, 400);
	render->setVisible(true);

	RenderVertex* vert1 = render->addVertex();
	RenderVertex* vert2 = render->addVertex();
	RenderVertex* vert3 = render->addVertex();
	RenderVertex* vert4 = render->addVertex();

	RenderUniform* uni1 = render->addUniform();
	RenderUniform* uni2 = render->addUniform();
	RenderUniform* uni3 = render->addUniform();

	RenderGeom* geom1 = render->addGeom();
	RenderGeom* geom2 = render->addGeom();

	vert1->addLocalVec4f("vert_position", -1.0f, 1.0f, 0, 1);
	vert2->addLocalVec4f("vert_position", 1.0f, 1.0f, 0, 1);
	vert3->addLocalVec4f("vert_position", 1.0f, -1.0f, 0, 1);
	vert4->addLocalVec4f("vert_position", -1.0f, -1.0f, 0, 1);

	zoom = uni1->addLocalVec1f("zoom", 1.0f);
	c = uni2->addLocalVec2f("c", 0, 0);
	camera = uni3->addLocalVec2f("camera", 0, 0);

	geom1->addVertex(vert1);
	geom1->addVertex(vert2);
	geom1->addVertex(vert3);

	geom2->addVertex(vert1);
	geom2->addVertex(vert3);
	geom2->addVertex(vert4);
}

void JuliaSetObject::destroy() {
	render->destroy();
	logic->destroy();
	object->destroy();
}

bool JuliaSetObject::isVisible() {
	return render->isVisible();
}

void JuliaSetObject::setVisible(bool visible) {
	render->setVisible(visible);
}

void JuliaSetObject::move(float dx, float dy) {
	camera->wget()->addVec2f(dx * zoom->wget()->getX(), dy * zoom->wget()->getX());
}

void JuliaSetObject::doZoom(float margin) {
	zoom->wget()->mulScalar(margin);
}

void JuliaSetObject::switchConstant(int examp) {
	switch(examp) {
	case 0: camera->wget()->setXY(0, 0); zoom->wget()->setX(1.0f); c->wget()->setXY(0, 0); break;
	case 1: camera->wget()->setXY(0, 0); zoom->wget()->setX(1.0f); c->wget()->setXY(0.285f, 0.01f); break;
	case 2: camera->wget()->setXY(0, 0); zoom->wget()->setX(1.0f); c->wget()->setXY(-0.6f, 0.4f); break;
	case 3: camera->wget()->setXY(0, 0); zoom->wget()->setX(1.0f); c->wget()->setXY(-0.8f, 0.156f); break;
	}
}
