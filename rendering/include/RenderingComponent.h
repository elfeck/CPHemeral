#ifndef RENDERING_COMPONENT_H_
#define RENDERING_COMPONENT_H_

#include "Component.h"


namespace cph {

struct RenderingComponent : public Component {

	virtual const char* getName() const = 0;

	virtual void release() = 0;

};

}

#endif