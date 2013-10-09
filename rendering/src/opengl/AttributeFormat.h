#ifndef ATTRIBUTE_FORMAT_H_
#define ATTRIBUTE_FORMAT_H_

#include <string>
#include <gl\glew.h>


namespace cph {

class AttributeFormat {

private:
	const GLuint index;
	const GLint size;
	const int byteSize;
	const GLenum type;
	const std::string name, originalName;

public:
	AttributeFormat(GLuint index, GLint size, GLenum type, std::string name, std::string originalName);
	~AttributeFormat();

	GLuint getIndex() const;
	GLint getSize() const;
	int getByteSize() const;
	GLenum getType() const;
	std::string getName() const;
	std::string getOriginalName() const;

	bool operator<(const AttributeFormat& other) const;

};

}

#endif