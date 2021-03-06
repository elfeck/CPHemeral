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
	bool vertModified, geomModified;
	unsigned int indexOffset, indexCount, indexBufferOffset, vertexBufferOffset;

	RenderAllocator* allocPtr;

public:
	VaoEntry();
	~VaoEntry();

	static const std::string ERROR_PATH;

	std::string getShaderPath() const;
	GLenum getMode() const;
	bool isVisible() const;
	bool isAdded() const;

	bool wasVertModified() const;
	bool wasGeomModified() const;

	bool nextNeedsViewportChange(VaoEntry& next) const;
	bool nextNeedsScissorChange(VaoEntry& next) const;
	bool nextNeedsShaderChange(VaoEntry& next) const;

	void setViewportRect(int x, int y, int width, int height);
	void setScissorRect(int x, int y, int width, int height);
	void setShader(std::string path);
	void setMode(GLenum mode);
	void setVisible(bool visible);
	void setAdded(bool added);

	void viewportGL() const;
	void scissorGL() const;
	void uploadUniformsGL(GLuint programHandle) const;

	unsigned int getIndexOffset() const;
	unsigned int getIndexCount() const;
	unsigned int getIndexBufferOffset() const;

	void fetchVertexData(std::vector<GLfloat>& buffer, unsigned int* offset, const std::set<AttributeFormat>& format);
	void fetchIndexData(std::vector<GLushort>& buffer, unsigned int* indexOffs, unsigned int* indexBufferOffs);
	
	RenderGeomImpl* addGeom();
	RenderVertexImpl* addVertex();
	RenderUniformImpl* addUniform();

	void removeGeom(RenderGeom* geom);
	void removeVertex(RenderVertex* vertex);
	void removeUniform(RenderUniform* uniform);

	void setAllocPtr(RenderAllocator* allocPtr);

};

}


#endif