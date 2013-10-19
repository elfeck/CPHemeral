#ifndef RENDERING_COMPONENT_H_
#define RENDERING_COMPONENT_H_

#include "RenderGeom.h"
#include "Primitive.h"
#include "RenderVertex.h"
#include "RenderUniform.h"
#include "Component.h"


namespace cph {

struct RenderingComponent : public Component {
	
	virtual RenderGeom* addGeom() = 0;
	virtual RenderVertex* addVertex() = 0;
	virtual RenderUniform* addLocalUniform() = 0;
	
	virtual void removeGeom(RenderGeom* geom) = 0;
	virtual void removeVertex(RenderVertex* vertex) = 0;
	virtual void removeLocalUniform(RenderUniform* uniform) = 0;

	virtual void setShader(const char* path) = 0;
	virtual void setViewport(int x, int y, int width, int height) = 0;
	virtual void setScissor(int x, int y, int width, int height) = 0;
	virtual void setVisible(bool visible) = 0;

	virtual std::uint8_t getSysId() const = 0;
	virtual std::uint32_t getUniqueId() const = 0;

	virtual void destroy() = 0;

};

}

#endif