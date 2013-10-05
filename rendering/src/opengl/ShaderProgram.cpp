#include "ShaderProgram.h"
#include "GlobalUtils.h"


using namespace cph;

ShaderProgram::ShaderProgram(std::string shaderPath) :
	vertSource(fileToString(shaderPath + ".vert")), fragSource(fileToString(shaderPath + ".frag"))
{
	processVertexShader();
}

ShaderProgram::~ShaderProgram() {

}

void ShaderProgram::processVertexShader() {
	// extract all lines except lines with '#' in them
	std::vector<std::string> tokens = stringSplit(vertSource, '\n');
	std::string processedSource("");
	for(std::vector<std::string>::size_type i = 0; i < tokens.size(); i++) {
		if(tokens.at(i).find("#") == std::string::npos) processedSource.append(tokens.at(i));
	}
	processedSource = stringReplaceAll(processedSource, "\n", "");
	processedSource = stringReplaceAll(processedSource, "\t", "");

	// extract all lines starting with "in " and remove this prefix and all additional leading whitespace
	tokens = stringSplit(processedSource, ';');
	std::vector<std::string> processedTokens;
	for(std::vector<std::string>::size_type i = 0; i < tokens.size(); i++) {
		if(tokens.at(i).find("in ") == 0) {
			tokens.at(i).replace(0, 3, "");
			while(tokens.at(i).at(0) == ' ') tokens.at(i).replace(0, 1, "");
			processedTokens.push_back(tokens.at(i));
		}
	}

	for(std::vector<std::string>::size_type i = 0; i < processedTokens.size(); i++) {

	}
}

