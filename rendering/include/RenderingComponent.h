#ifndef RENDERING_COMPONENT_H_
#define RENDERING_COMPONENT_H_

#include "Component.h"


namespace cph {

struct RenderGeom;
struct Primitive;
struct RenderVertex;
struct RenderUniform;

enum RenderMode {
	POINTS, LINES, TRIANGLES
};

struct RenderingComponent : public Component {
	
	virtual RenderGeom* addLocalGeom() = 0;
	virtual RenderVertex* addLocalVertex() = 0;
	virtual RenderUniform* addLocalUniform() = 0;
	
	virtual void removeLocalGeom(RenderGeom* geom) = 0;
	virtual void removeLocalVertex(RenderVertex* vertex) = 0;
	virtual void removeLocalUniform(RenderUniform* uniform) = 0;

	virtual void setShader(const char* path) = 0;
	virtual void setViewport(int x, int y, int width, int height) = 0;
	virtual void setScissor(int x, int y, int width, int height) = 0;
	virtual void setRenderMode(RenderMode rendeMode) = 0;
	virtual void setVisible(bool visible) = 0;

	virtual bool isVisible() const = 0;

	virtual std::uint8_t getSysId() const = 0;
	virtual std::uint32_t getUniqueId() const = 0;

	virtual void destroy() = 0;

};

}

#endif