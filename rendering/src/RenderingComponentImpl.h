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
	
	const std::uint32_t compId;
	std::uint8_t sysId;
	RenderingSystemImpl* system;

	VaoEntry vaoEntry;

public:
	RenderingComponentImpl(std::uint32_t id);
	~RenderingComponentImpl();

	virtual Vertex* addVertex();
	virtual Uniform* addUniform();
	virtual void removeVertex(Vertex* vertex);
	virtual void removeUniform(Uniform* uniform);

	virtual void setShader(const char* path);
	virtual void setViewport(int x, int y, int width, int height);
	virtual void setScissor(int x, int y, int width, int height);
	virtual void setVisible(bool visible);

	virtual std::uint8_t getSysId() const;
	virtual std::uint32_t getCompId() const;
	
	virtual void destroy();

	void setSystem(RenderingSystemImpl* system);
	void setSysId(std::uint8_t id);
	VaoEntry* getVaoEntry();

};

}

#endif