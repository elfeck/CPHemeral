#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_

#include <string>
#include <set>

#include "AttributeFormat.h"


namespace cph {

class ShaderProgram {

private:
	GLuint vertHandle, fragHandle, programHandle;
	bool initialized, linked;

	std::set<AttributeFormat> attribFormat;
	std::string shaderId, vertSource, fragSource;

	void processVertexShader();
	void compileShaderGL();
	void attachShaderGL();
	void linkShaderGL();
	void checkCompilationGL(int handle);
	void checkLinkageGL();

public:
	ShaderProgram(std::string shaderPath);
	ShaderProgram(const ShaderProgram& other);
	~ShaderProgram();

	std::string getShaderId() const;
	GLuint getProgramHandle() const;
	const std::set<AttributeFormat>& getAttritbuteFormat() const;
	bool isLinked() const;

	void bindGL();
	void unbindGL();

	void destroyGL();

};

}

#endif