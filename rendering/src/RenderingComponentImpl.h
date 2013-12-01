#ifndef RENDERING_COMPONENT_IMPL_H_
#define RENDERING_COMPONENT_IMPL_H_

#include <string>
#include <vector>
#include <map>
#include "SingleIdAllocator.h"
#include "primitive/PrimitiveImpl.h"
#include "../include/RenderingComponent.h"
#include "opengl/VaoEntry.h"


namespace cph {

class RenderingSystemImpl;

class RenderingComponentImpl : public RenderingComponent {

private:
	const std::uint32_t uniqueId;
	std::uint8_t sysId;

	RenderingSystemImpl* system;
	VaoEntry vaoEntry;

public:
	RenderingComponentImpl(std::uint32_t id);
	~RenderingComponentImpl();

	virtual RenderGeom* addGeom();
	virtual RenderVertex* addVertex();
	virtual RenderUniform* addUniform();
	virtual void removeGeom(RenderGeom* geom);
	virtual void removeVertex(RenderVertex* vertex);
	virtual void removeUniform(RenderUniform* uniform);

	virtual void setShader(const char* path);
	virtual void setViewport(int x, int y, int width, int height);
	virtual void setScissor(int x, int y, int width, int height);
	virtual void setRenderMode(RenderMode rendeMode);
	virtual void setVisible(bool visible);

	virtual bool isVisible() const;

	virtual std::uint8_t getSysId() const;
	virtual std::uint32_t getUniqueId() const;
	
	virtual void destroy();

	void setSystem(RenderingSystemImpl* system);
	VaoEntry* getVaoEntry();

};

}

#endif