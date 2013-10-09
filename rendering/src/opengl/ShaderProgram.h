#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_

#include <string>
#include <set>

#include "AttributeFormat.h"


namespace cph {

class ShaderProgram {

private:
	std::set<AttributeFormat> attribFormat;
	std::string vertSource, fragSource;

	void processVertexShader();

public:
	ShaderProgram(std::string shaderPath);
	~ShaderProgram();

};

}

#endif