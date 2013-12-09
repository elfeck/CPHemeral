#include "EnvTile.h"
#include "../Unicellular.h"


using namespace cph;

EnvTile::EnvTile(int x, int y, int size, int sceneWidth, int sceneHeight) :
	x(x), y(y), size(size), sceneWidth(sceneWidth), sceneHeight(sceneHeight)
{

}

EnvTile::~EnvTile() {

}


void EnvTile::init(Camera& camera, ObjectAllocator* objAlloc) {
	object = objAlloc->createObject();
	renderingComp = getComponentAllocator().getRenderingAllocator()->createComponent();
	renderingComp->setShader(getAbsolutePath().append("/shader/EnvTile").c_str());
	renderingComp->setViewport(0, 0, sceneWidth, sceneHeight);
	renderingComp->setScissor(0, 0, sceneWidth, sceneHeight);
	renderingComp->setVisible(true);
	camera.addCameraAsUniform(renderingComp);
	camera.addMvpMatrixAsUniform(renderingComp);
	
	initGeom();

	object->addComponent(renderingComp);
}

void EnvTile::initGeom() {
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.push_back(renderingComp->addVertex());
	vertices.at(0)->addLocalVec4f("vert_position", (x - 0.5f) * size, (y + 0.5f) * size, 0.0f, 1.0f);
	vertices.at(1)->addLocalVec4f("vert_position", (x - 0.5f) * size, (y - 0.5f) * size, 0.0f, 1.0f);
	vertices.at(2)->addLocalVec4f("vert_position", (x + 0.5f) * size, (y - 0.5f) * size, 0.0f, 1.0f);
	vertices.at(3)->addLocalVec4f("vert_position", (x + 0.5f) * size, (y + 0.5f) * size, 0.0f, 1.0f);
	geoms.push_back(renderingComp->addGeom());
	geoms.push_back(renderingComp->addGeom());
	geoms.at(0)->addVertex(vertices.at(0));
	geoms.at(0)->addVertex(vertices.at(1));
	geoms.at(0)->addVertex(vertices.at(2));
	geoms.at(1)->addVertex(vertices.at(2));
	geoms.at(1)->addVertex(vertices.at(3));
	geoms.at(1)->addVertex(vertices.at(0));
}


void EnvTile::destroy() {
	renderingComp->destroy();
	object->destroy();
}
