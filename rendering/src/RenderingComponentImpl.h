#ifndef RENDERING_COMPONENT_IMPL_H_
#define RENDERING_COMPONENT_IMPL_H_

#include <string>
#include <vector>

#include "../include/RenderingComponent.h"

#include "VertexImpl.h"
#include "UniformImpl.h"


namespace cph {

class RenderingSystemImpl;

class RenderingComponentImpl : public RenderingComponent {

private:
	std::string name;
	RenderingSystemImpl* system;

	std::vector<VertexImpl*> vertices;
	std::vector<UniformImpl*> uniforms;

public:
	RenderingComponentImpl();
	~RenderingComponentImpl();

	virtual Vertex* addVertex();
	virtual Uniform* addUniform();

	virtual void setShader(const char* path);
	virtual void setViewport(int x, int y, int width, int height);
	virtual void setScissor(int x, int y, int width, int height);

	virtual const char* getName() const;
	virtual void destroy();

	void removeVertex(VertexImpl* vertex);
	void removeUniform(UniformImpl* uniform);

	void setSystem(RenderingSystemImpl* system);

};

}

#endif