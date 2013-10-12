#ifndef VAO_ENTRY_H_
#define VAO_ENTRY_H_

#include <gl/glew.h>
#include <vector>
#include "Rectf.h"


namespace cph {

class VaoEntry {

private:

	Rectf viewportRect, scissorRect;
	std::string shaderPath;
	GLenum mode;
	bool visible, added;

	int indexOffset;

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

};

}


#endif