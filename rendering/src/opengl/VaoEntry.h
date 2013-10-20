#ifndef VAO_ENTRY_H_
#define VAO_ENTRY_H_

#include <gl/glew.h>
#include <vector>
#include <cstdint>
#include <set>
#include "Rectf.h"
#include "../RenderUniformImpl.h"
#include "../RenderVertexImpl.h"
#include "../RenderGeomImpl.h"
#include "../RenderAllocator.h"
#include "AttributeFormat.h"


namespace cph {

class VaoEntry {

private:
	std::map<std::uint32_t, RenderVertexImpl*> vertices;
	std::map<std::uint32_t, RenderUniformImpl*> uniforms;
	std::map<std::uint32_t, RenderGeomImpl*> geoms;

	Rectf viewportRect, scissorRect;
	std::string shaderPath;
	GLenum mode;
	bool visible, added;
	int indexOffset;

	RenderAllocator* allocPtr;

public:
	VaoEntry();
	~VaoEntry();

	std::string getShaderPath() const;
	GLenum getMode() const;
	bool isAdded() const;

	void setViewportRect(int x, int y, int width, int height);
	void setScissorRect(int x, int y, int width, int height);
	void setShader(std::string path);
	void setMode(GLenum mode);
	void setVisible(bool visible);
	void setAdded(bool added);

	void viewportGL() const;
	void scissorGL() const;
	void uploadUniformsGL(GLuint programHandle) const;

	void fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset, const std::set<AttributeFormat>& format) const;
	void fetchIndexData(std::vector<GLushort>& buffer, unsigned int* offset) const;
	
	RenderGeomImpl* addLocalGeom();
	RenderVertexImpl* addLocalVertex();
	RenderUniformImpl* addLocalUniform();

	void removeLocalGeom(RenderGeom* geom);
	void removeLocalVertex(RenderVertex* vertex);
	void removeLocalUniform(RenderUniform* uniform);

	void setAllocPtr(RenderAllocator* allocPtr);

};

}


#endif