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

	std::map<std::uint32_t, RenderGeomImpl*> geoms;
	std::map<std::uint32_t, RenderUniformImpl*> uniforms;

	RenderingSystemImpl* system;
	VaoEntry vaoEntry;

public:
	RenderingComponentImpl(std::uint32_t id);
	~RenderingComponentImpl();
	
	virtual PrmiVec1f* createVec1f(const char* name = "", float x = 0.0f);
	virtual PrmiVec2f* createVec2f(const char* name = "", float x = 0.0f, float y = 0.0f);
	virtual PrmiVec3f* createVec3f(const char* name = "", float x = 0.0f, float y = 0.0f, float z = 0.0f);
	virtual PrmiVec4f* createVec4f(const char* name, float x, float y, float z, float w);
	
	virtual PrmiMat2f* createMat2f(const char* name = "");
	virtual PrmiMat3f* createMat3f(const char* name = "");
	virtual PrmiMat4f* createMat4f(const char* name = "");
	
	virtual RenderGeom* createGeom();
	virtual RenderVertex* createVertex();
	virtual RenderUniform* createUniform();

	virtual void destroyPrimitive(Primitive* prmi);
	virtual void destroyGeom(RenderGeom* geom);
	virtual void destroyVertex(RenderVertex* vertex);
	virtual void destroyUniform(RenderUniform* uniform);
	
	virtual void destroyAllGeomsRecursively();

	virtual void addGeom(RenderGeom* geom);
	virtual void addUniform(RenderUniform* uniform);

	virtual void removeGeom(RenderGeom* geom);
	virtual void removeUniform(RenderUniform* uniform);

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