#ifndef RENDERING_COMPONENT_H_
#define RENDERING_COMPONENT_H_

#include "Component.h"
#include "Vertex.h"
#include "Uniform.h"


namespace cph {

struct RenderingComponent : public Component {

	virtual Vertex* addVertex() = 0;
	virtual Uniform* addUniform() = 0;

	virtual void removeVertex(Vertex* vertex) = 0;
	virtual void removeUniform(Uniform* uniform) = 0;

	virtual void setShader(const char* path) = 0;
	virtual void setViewport(int x, int y, int width, int height) = 0;
	virtual void setScissor(int x, int y, int width, int height) = 0;
	virtual void setVisible(bool visible) = 0;

	virtual const char* getName() const = 0;
	virtual int getId() const = 0;

};

}

#endif