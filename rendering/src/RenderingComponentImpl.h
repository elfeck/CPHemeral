#ifndef RENDERING_COMPONENT_IMPL_H_
#define RENDERING_COMPONENT_IMPL_H_

#include <vector>

#include "../include/RenderingComponent.h"


namespace cph {

class RenderingComponentImpl : public RenderingComponent {

private:

public:
	RenderingComponentImpl();
	~RenderingComponentImpl();

	virtual Vertex* addVertex();
	virtual void removeVertex(Vertex* vertex);

	virtual Uniform* addUniform();
	virtual void removeUniform(Uniform* uniform);

	virtual void setShader(const char* path);
	virtual void setViewport(int x, int y, int width, int height);
	virtual void setScissor(int x, int y, int width, int height);

	virtual const char* getName() const;
	virtual void release();

};

}

#endif