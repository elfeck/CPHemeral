#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_

#include <string>


namespace cph {

class ShaderProgram {

private:
	std::string vertSource, fragSource;

	void processVertexShader();

public:
	ShaderProgram(std::string shaderPath);
	~ShaderProgram();

};

}

#endif