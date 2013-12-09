#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include <vector>
#include "CPHObject.h"
#include "EnvTile.h"


namespace cph {

class Environment {

private:
	int tileSize, sceneWidth, sceneHeight;
	std::vector<EnvTile> envTiles;

public:
	Environment(int sceneWidth, int sceneHeight);
	~Environment();

	void init(Camera& camera, ObjectAllocator* objAlloc);
	void destroy();

};

}


#endif