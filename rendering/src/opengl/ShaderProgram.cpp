#include "ShaderProgram.h"
#include "GlobalUtils.h"
#include "../SystemLog.h"


using namespace cph;

ShaderProgram::ShaderProgram(std::string shaderPath) :
	vertHandle(0), fragHandle(0), programHandle(0), initialized(false), linked(false),
	attribFormat(), shaderId(shaderPath), vertSource(fileToString(shaderPath + ".vert")), 
	fragSource(fileToString(shaderPath +".frag"))
{
	processVertexShader();
}

ShaderProgram::ShaderProgram(const ShaderProgram& other) :
	vertHandle(other.vertHandle), fragHandle(other.fragHandle), programHandle(other.programHandle), initialized(other.initialized), linked(other.linked),
	attribFormat(other.attribFormat), shaderId(other.shaderId), vertSource(other.vertSource), fragSource(other.fragSource)
{

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
			attribFormat.insert(AttributeFormat(i, 1, GL_FLOAT, "_attrib_fv1_" + intToString(vec1Count++), 
				stringUntil(processedTokens.at(i), ";")));
		} else if(processedTokens.at(i).find("vec2") == 0) {
			processedTokens.at(i).replace(0, 4, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 2, GL_FLOAT, "_attrib_fv2_" + intToString(vec2Count++),
				stringUntil(processedTokens.at(i), ";")));
		} else if(processedTokens.at(i).find("vec3") == 0) {
			processedTokens.at(i).replace(0, 4, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 3, GL_FLOAT, "_attrib_fv3_" + intToString(vec3Count++), 
				stringUntil(processedTokens.at(i), ";")));
		} else if(processedTokens.at(i).find("vec4") == 0) {
			processedTokens.at(i).replace(0, 4, "");
			while(processedTokens.at(i).at(0) == ' ') processedTokens.at(i).replace(0, 1, "");
			attribFormat.insert(AttributeFormat(i, 4, GL_FLOAT, "_attrib_fv4_" + intToString(vec4Count++), 
				stringUntil(processedTokens.at(i), ";")));
		}
	}

	// replace names in vertSource
	for(std::set<AttributeFormat>::iterator it = attribFormat.begin(); it != attribFormat.end(); ++it) {
		vertSource = stringReplaceAll(vertSource, it->getOriginalName(), it->getName());
	}
}

std::string ShaderProgram::getShaderId() const {
	return shaderId;
}

GLuint ShaderProgram::getProgramHandle() const {
	return programHandle;
}

const std::set<AttributeFormat>& ShaderProgram::getAttritbuteFormat() const {
	return attribFormat;
}

bool ShaderProgram::isLinked() const {
	return linked;
}

void ShaderProgram::bindGL() {
	if(!initialized) {
		compileShaderGL();
		attachShaderGL();
		linkShaderGL();
	}
	glUseProgram(programHandle);
}

void ShaderProgram::unbindGL() {
	glUseProgram(0);
}

void ShaderProgram::compileShaderGL() {
	vertHandle = glCreateShader(GL_VERTEX_SHADER);
	const char* vertSrc = vertSource.c_str();
	glShaderSource(vertHandle, 1, &vertSrc, 0);
	glCompileShader(vertHandle);
	checkCompilationGL(vertHandle);
		
	fragHandle = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragSrc = fragSource.c_str();
	glShaderSource(fragHandle, 1, &fragSrc, 0);
	glCompileShader(fragHandle);
	checkCompilationGL(fragHandle);
}

void ShaderProgram::attachShaderGL() {
	programHandle = glCreateProgram();
	glAttachShader(programHandle, vertHandle);
	glAttachShader(programHandle, fragHandle);
}

void ShaderProgram::linkShaderGL() {
	glLinkProgram(programHandle);
	checkLinkageGL();
	glValidateProgram(programHandle);
	initialized = true;
}

void ShaderProgram::checkCompilationGL(int handle) {
	GLint status = 0;
	glGetShaderiv(handle, GL_COMPILE_STATUS, &status);
	if(status == GL_FALSE) {
		getErrorLog().pre() << "Error compiling shader: " << cutFilepath(shaderId) << std::endl;
		GLint infoLogLength = 0;
		glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* infoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(handle, infoLogLength, 0, infoLog);
		getDebugLog() << infoLog << std::endl;
		delete[] infoLog;
	} else {
		getDebugLog().pre() << "No errors compiling shader: " << cutFilepath(shaderId) << std::endl;
	}
}

void ShaderProgram::checkLinkageGL() {
	GLint status = 0;
	glGetProgramiv(programHandle, GL_LINK_STATUS, &status);
	if(status == GL_FALSE) {
		getErrorLog().pre() << "Error linking shader: " << cutFilepath(shaderId) << std::endl;
		GLint infoLogLength;
		glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* infoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(programHandle, infoLogLength, 0, infoLog);
		getDebugLog() << infoLog << std::endl;
		delete[] infoLog;
	} else {
		getDebugLog().pre() << "No errors linking shader: " << cutFilepath(shaderId) << std::endl;
		linked = true;
	}
}

void ShaderProgram::destroyGL() {
	glDeleteShader(vertHandle);
	glDeleteShader(fragHandle);
	glDeleteProgram(programHandle);
}