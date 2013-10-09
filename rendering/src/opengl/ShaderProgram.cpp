#include "ShaderProgram.h"
#include "GlobalUtils.h"
#include <iostream>


using namespace cph;

ShaderProgram::ShaderProgram(std::string shaderPath) :
	attribFormat(), vertSource(fileToString(shaderPath + ".vert")), fragSource(fileToString(shaderPath + ".frag"))
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
		if(!tokens.at(i).find("#") == 0	) processedSource.append(tokens.at(i));
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

	// create attribformats and asign index, type info and original name
	int vec1Count = 0;
	int vec2Count = 0;
	int vec3Count = 0;
	int vec4Count = 0;
	for(std::vector<std::string>::size_type i = 0; i < processedTokens.size(); i++) {
		if(processedTokens.at(i).find("float") == 0) {
			processedTokens.at(i).replace(0, 5, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 1, GL_FLOAT, "__attrib_fv1_" + intToString(vec1Count++), 
				stringUntil(processedTokens.at(i), ";")));
		} else if(processedTokens.at(i).find("vec2") == 0) {
			processedTokens.at(i).replace(0, 4, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 2, GL_FLOAT, "__attrib_fv2_" + intToString(vec2Count++),
				stringUntil(processedTokens.at(i), ";")));
		} else if(processedTokens.at(i).find("vec3") == 0) {
			processedTokens.at(i).replace(0, 4, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 3, GL_FLOAT, "__attrib_fv3_" + intToString(vec3Count++), 
				stringUntil(processedTokens.at(i), ";")));
		} else if(processedTokens.at(i).find("vec4") == 0) {
			processedTokens.at(i).replace(0, 4, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 4, GL_FLOAT, "__attrib_fv4_" + intToString(vec4Count++), 
				stringUntil(processedTokens.at(i), ";")));
		}
	}

	// replace names in vertSource
	for(std::set<AttributeFormat>::iterator it = attribFormat.begin(); it != attribFormat.end(); ++it) {
		vertSource = stringReplaceAll(vertSource, it->getOriginalName(), it->getName());
	}

	std::cout << vertSource << std::endl;
}

