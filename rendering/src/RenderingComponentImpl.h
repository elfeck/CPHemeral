#ifndef RENDERING_COMPONENT_IMPL_H_
#define RENDERING_COMPONENT_IMPL_H_

#include <string>
#include <vector>
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

	virtual PrmiVec4f* createVec4f(const char* name, float x, float y, float z, float w);

	virtual RenderGeom* createGeom();
	virtual RenderVertex* createVertex();
	virtual RenderUniform* createUniform();

	virtual void destroyPrimitive(Primitive* prmi);
	virtual void destroyGeom(RenderGeom* geom);
	virtual void destroyVertex(RenderVertex* vertex);
	virtual void destroyUniform(RenderUniform* uniform);

	virtual void setShader(const char* path);
	virtual void setViewport(int x, int y, int width, int height);
	virtual void setScissor(int x, int y, int width, int height);
	virtual void setVisible(bool visible);

	virtual std::uint8_t getSysId() const;
	virtual std::uint32_t getUniqueId() const;
	
	virtual void destroy();

	void setSystem(RenderingSystemImpl* system);
	void setSysId(std::uint8_t id);
	VaoEntry* getVaoEntry();

	void bla();

};

}

#endif