#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include <vector>
#include "CPHObject.h"
#include "EnvTile.h"


namespace cph {

class Environment {

private:
	int tileSize;
	std::vector<EnvTile> envTiles;

public:
	Environment();
	~Environment();

	void init(Camera& camera, ObjectAllocator* objAlloc);
	void destroy();

};

}


#endif