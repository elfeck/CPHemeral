#ifndef ENV_TILE_H_
#define ENV_TILE_H

#include "CPHObject.h"
#include "CPHRendering.h"
#include "../Camera.h"


namespace cph {

class EnvTile {

private:
	Object* object;
	RenderingComponent* renderingComp;
	std::vector<RenderGeom*> geoms;
	std::vector<RenderVertex*> vertices;
	Camera* camera;

	int x, y, size, sceneWidth, sceneHeight;

	void initGeom();

public:
	EnvTile(int x, int y, int size, int sceneWidth, int sceneHeight);
	~EnvTile();

	void init(Camera& camera, ObjectAllocator* objAlloc);
	void destroy();

};

}


#endif