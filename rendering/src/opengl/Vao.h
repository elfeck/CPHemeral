#ifndef VAO_H_
#define VAO_H_

#include <vector>
#include <map>
#include <gl/glew.h>

#include "VaoEntry.h"
#include "ShaderProgram.h"
#include "BufferFormat.h"


namespace cph {

class Vao {

private:
	GLuint vaoHandle, vboHandle, iboHandle;
	GLenum usage;

	bool modified;

	std::map<std::string, ShaderProgram> shaderPrograms;
	std::vector<VaoEntry*> entries;
	BufferFormat bufferFormat;

	void bindVboGL();
	void bindIboGL();

public:
	Vao();
	~Vao();

	void addVaoEntry(VaoEntry* entry, ShaderProgram* program = 0);
	void removeVaoEntry(VaoEntry* entry);

	bool hasShader(std::string shaderId) const;
	bool supportsShader(ShaderProgram& program) const;

	void initGL(ShaderProgram initialProgram);
	void updateGL();
	void drawGL() const;

};

}

#endif