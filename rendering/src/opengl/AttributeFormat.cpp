#include "AttributeFormat.h"


using namespace cph;

AttributeFormat::AttributeFormat(GLuint index, GLint size, GLenum type, std::string name, std::string originalName) :
	index(index), size(size), byteSize(type == GL_FLOAT ? sizeof(GLfloat) : 0), type(type), name(name), originalName(originalName)
{

}

AttributeFormat::~AttributeFormat() {

}

GLuint AttributeFormat::getIndex() const {
	return index;
}

GLint AttributeFormat::getSize() const {
	return size;
}

int AttributeFormat::getByteSize() const {
	return byteSize;
}

GLenum AttributeFormat::getType() const {
	return type;
}

std::string AttributeFormat::getName() const {
	return name;
}

std::string AttributeFormat::getOriginalName() const {
	return originalName;
}

bool AttributeFormat::operator<(const AttributeFormat& other) const {
	return index < other.index;
}