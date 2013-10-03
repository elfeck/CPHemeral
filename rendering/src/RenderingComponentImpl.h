#ifndef RENDERING_COMPONENT_IMPL_H_
#define RENDERING_COMPONENT_IMPL_H_

#include <string>
#include <vector>
#include "SingleIdAllocator.h"

#include "../include/RenderingComponent.h"
#include "opengl/VaoEntry.h"

#include "VertexImpl.h"
#include "UniformImpl.h"


namespace cph {

class RenderingSystemImpl;

class RenderingComponentImpl : public RenderingComponent {

private:
	static SingleIdAllocator<VertexImpl> vertexAlloc;
	static SingleIdAllocator<UniformImpl> uniformAlloc;

	const int id;
	const std::string name;
	RenderingSystemImpl* system;

	VaoEntry vaoEntry;

public:
	RenderingComponentImpl(int id);
	~RenderingComponentImpl();

	virtual Vertex* addVertex();
	virtual Uniform* addUniform();
	virtual void removeVertex(Vertex* vertex);
	virtual void removeUniform(Uniform* uniform);

	virtual void setShader(const char* path);
	virtual void setViewport(int x, int y, int width, int height);
	virtual void setScissor(int x, int y, int width, int height);
	virtual void setVisible(bool visible);

	virtual const char* getName() const;
	virtual int getId() const;
	
	virtual void destroy();

	void setSystem(RenderingSystemImpl* system);

};

}

#endif