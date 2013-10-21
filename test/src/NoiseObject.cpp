#include "NoiseObject.h"


using namespace cph;

NoiseObject::NoiseObject() :
	object(0), render(0)
{

}

NoiseObject::~NoiseObject() {

}

void NoiseObject::create(ObjectManager* scene, RenderingSystem* sys) {
	object = scene->createObject();
	render = sys->createComponent();
	
	render->setRenderMode(TRIANGLES);
	render->setShader("D://Projects/C++/CPHemeral/test/res/simplexnoise");
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

	// uniforms

	geom1->addVertex(vert1);
	geom1->addVertex(vert2);
	geom1->addVertex(vert3);

	geom2->addVertex(vert1);
	geom2->addVertex(vert3);
	geom2->addVertex(vert4);

	object->addComponent(render);
}

void NoiseObject::destroy() {

}
