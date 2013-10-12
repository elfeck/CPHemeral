#ifndef RENDERING_COMPONENT_H_
#define RENDERING_COMPONENT_H_

#include "Component.h"


namespace cph {

struct RenderingComponent : public Component {

	virtual void setShader(const char* path) = 0;
	virtual void setViewport(int x, int y, int width, int height) = 0;
	virtual void setScissor(int x, int y, int width, int height) = 0;
	virtual void setVisible(bool visible) = 0;

	virtual std::uint8_t getSysId() const = 0;
	virtual std::uint32_t getCompId() const = 0;

};

}

#endif