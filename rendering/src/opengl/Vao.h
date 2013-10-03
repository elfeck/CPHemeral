#ifndef VAO_H_
#define VAO_H_

#include <vector>
#include <map>
#include <gl/glew.h>

#include "VaoEntry.h"
#include "ShaderProgram.h"


namespace cph {

class Vao {

private:
	GLuint vaoHandle, vboHandle, iboHandle;
	GLenum usage, mode;

	std::map<std::string, ShaderProgram> shaderPrograms;

public:
	Vao();
	~Vao();

	void drawGL(std::vector<VaoEntry*> entries);

};

}

#endif