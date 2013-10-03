#include "UniformImpl.h"


using namespace cph;

UniformImpl::UniformImpl(int id) :
	id(id), vecUniforms(), matUniforms(), locations()
{

}

UniformImpl::~UniformImpl() {

}

void UniformImpl::addUniformVec(const char* name, Vecf* vec) {
	vecUniforms.insert(std::pair<std::string, Vecf*>(name, vec));
	locations.insert(std::pair<std::string, GLint>(name, 0));
}

void UniformImpl::addUniformMat(const char* name, Matf* mat) {
	matUniforms.insert(std::pair<std::string, Matf*>(name, mat));
	locations.insert(std::pair<std::string, GLint>(name, 0));
}

void UniformImpl::removeUniform(const char* name) {
	vecUniforms.erase(name);
	matUniforms.erase(name);
	locations.erase(name);
}

int UniformImpl::getId() const {
	return id;
}

void UniformImpl::uploadGL(GLuint programHandle) {
	for(std::map<std::string, Vecf*>::iterator it = vecUniforms.begin(); it != vecUniforms.end(); ++it) {
		if(locations.at(it->first) == 0) locations.at(it->first) = glGetUniformLocation(programHandle, it->first.c_str());
		switch(it->second->getDim()) {
		case 1: glUniform1f(locations.at(it->first), it->second->getN(0)); break;
		case 2: glUniform2f(locations.at(it->first), it->second->getN(0), it->second->getN(1)); break;
		case 3: glUniform3f(locations.at(it->first), it->second->getN(0), it->second->getN(1), it->second->getN(2)); break;
		case 4: glUniform4f(locations.at(it->first), 
					it->second->getN(0), it->second->getN(1), it->second->getN(2), it->second->getN(3)); break;
		}
	}
	for(std::map<std::string, Matf*>::iterator it = matUniforms.begin(); it != matUniforms.end(); ++it) {
		if(locations.at(it->first) == 0) locations.at(it->first) = glGetUniformLocation(programHandle, it->first.c_str());
		switch(it->second->getDim()) {
		case 2: {
			GLfloat raw[4] = { 0.0f };
			glUniformMatrix2fv(locations.at(it->first), 1, GL_FALSE, it->second->toArray(raw)); 
			break;
		}
		case 3: {
			GLfloat raw[9] = { 0.0f };
			glUniformMatrix2fv(locations.at(it->first), 1, GL_FALSE, it->second->toArray(raw)); 
			break;
		}
		case 4: {
			GLfloat raw[16] = { 0.0f };
			glUniformMatrix2fv(locations.at(it->first), 1, GL_FALSE, it->second->toArray(raw)); 
			break;
		}
		}
	}
}
