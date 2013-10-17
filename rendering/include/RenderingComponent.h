#ifndef RENDERING_COMPONENT_H_
#define RENDERING_COMPONENT_H_

#include "RenderGeom.h"
#include "Primitive.h"
#include "RenderVertex.h"
#include "RenderUniform.h"
#include "Component.h"
#include "PrmiVec1f.h"
#include "PrmiVec2f.h"
#include "PrmiVec3f.h"
#include "PrmiVec4f.h"
#include "PrmiMat2f.h"
#include "PrmiMat3f.h"
#include "PrmiMat4f.h"

namespace cph {

struct RenderingComponent : public Component {
	
	virtual PrmiVec1f* createVec1f(const char* name = "", float x = 0.0f) = 0;
	virtual PrmiVec2f* createVec2f(const char* name = "", float x = 0.0f, float y = 0.0f) = 0;
	virtual PrmiVec3f* createVec3f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f) = 0;
	virtual PrmiVec4f* createVec4f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f) = 0;

	virtual PrmiMat2f* createMat2f(const char* name = "") = 0;
	virtual PrmiMat3f* createMat3f(const char* name = "") = 0;
	virtual PrmiMat4f* createMat4f(const char* name = "") = 0;

	virtual RenderGeom* createGeom() = 0;
	virtual RenderVertex* createVertex() = 0;
	virtual RenderUniform* createUniform() = 0;

	virtual void destroyPrimitive(Primitive* prmi) = 0;
	virtual void destroyGeom(RenderGeom* geom) = 0;
	virtual void destroyVertex(RenderVertex* vertex) = 0;
	virtual void destroyUniform(RenderUniform* uniform) = 0;

	virtual void destroyAllGeomsRecursively() = 0;

	virtual void addGeom(RenderGeom* geom) = 0;
	virtual void addUniform(RenderUniform* uniform) = 0;

	virtual void removeGeom(RenderGeom* geom) = 0;
	virtual void removeUniform(RenderUniform* uniform) = 0;

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