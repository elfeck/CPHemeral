#ifndef VAO_ENTRY_H_
#define VAO_ENTRY_H_

#include <vector>
#include <gl/glew.h>
#include "Rectf.h"

#include "../VertexImpl.h"
#include "../UniformImpl.h"


namespace cph {

class VaoEntry {

private:
	std::vector<VertexImpl*> vertices;
	std::vector<UniformImpl*> uniforms;

	Rectf viewportRect, scissorRect;
	std::string shaderPath;
	bool visible, added;

	int indexOffset;

public:
	VaoEntry();
	~VaoEntry();

	void addVertex(VertexImpl* vertex);
	void removeVertex(VertexImpl* vertex);

	void addUniform(UniformImpl* uniform);
	void removeUniform(UniformImpl* uniform);

	std::string getShaderPath();
	bool isAdded();

	void setViewportRect(int x, int y, int width, int height);
	void setScissorRect(int x, int y, int width, int height);
	void setShader(std::string path);
	void setVisible(bool visible);
	void setAdded(bool added);

	void viewportGL();
	void scissorGL();
	void uploadUniformsGL(GLuint programHandle);

};

}


#endif