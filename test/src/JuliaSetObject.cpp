#include "JuliaSetObject.h"


using namespace cph;

JuliaSetObject::JuliaSetObject() :
	object(0), render(0), zoom(0), center(0)
{

}

JuliaSetObject::~JuliaSetObject() {

}

void JuliaSetObject::create(ObjectManager* scene, RenderingSystem* sys) {
	object = scene->createObject();
	render = sys->createComponent();
	
	render->setRenderMode(TRIANGLES);
	render->setShader("D://Projects/C++/CPHemeral/test/res/juliaset");
	render->setViewport(20, 20, 360, 360);
	render->setScissor(20, 20, 360, 360);
	render->setVisible(true);

	RenderVertex* vert1 = render->addLocalVertex();
	RenderVertex* vert2 = render->addLocalVertex();
	RenderVertex* vert3 = render->addLocalVertex();
	RenderVertex* vert4 = render->addLocalVertex();

	RenderUniform* uni1 = render->addLocalUniform();
	RenderUniform* uni2 = render->addLocalUniform();

	RenderGeom* geom1 = render->addLocalGeom();
	RenderGeom* geom2 = render->addLocalGeom();

	vert1->addVec4f("vert_position", -1.0f, 1.0f, 0, 1);
	vert2->addVec4f("vert_position", 1.0f, 1.0f, 0, 1);
	vert3->addVec4f("vert_position", 1.0f, -1.0f, 0, 1);
	vert4->addVec4f("vert_position", -1.0f, -1.0f, 0, 1);

	zoom = uni1->addVec1f("zoom", 1.5f);
	center = uni2->addVec2f("c", -0.7f, 0.27015f);

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



