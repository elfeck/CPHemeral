#include "Environment.h"


using namespace cph;

Environment::Environment(int sceneWidth, int sceneHeight) :
	tileSize(2000), envTiles()
{
	envTiles.push_back(EnvTile(0, 0, tileSize, sceneWidth, sceneHeight));
}

Environment::~Environment() {

}


void Environment::init(Camera& camera, ObjectAllocator* objAlloc) {
	for(std::vector<EnvTile>::iterator it = envTiles.begin(); it != envTiles.end(); ++it) {
		it->init(camera, objAlloc);
	}
}

void Environment::destroy() {
	for(std::vector<EnvTile>::iterator it = envTiles.begin(); it != envTiles.end(); ++it) {
		it->destroy();
	}
}
