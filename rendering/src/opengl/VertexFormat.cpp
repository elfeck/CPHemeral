#include "VertexFormat.h"


using namespace cph;

VertexFormat::VertexFormat() :
	attributes()
{

}

VertexFormat::~VertexFormat() {

}

void VertexFormat::computeOffsets() {
	int offset = 0;
	int stride = 0;
	for(std::map<GLuint, VertexAttribute>::iterator it = attributes.begin(); it != attributes.end(); ++it) {
		it->second.setOffset(offset);
		offset += it->second.getSize() * it->second.getByteSize();
		stride += it->second.getSize() * it->second.getByteSize();
	}
	for(std::map<GLuint, VertexAttribute>::iterator it = attributes.begin(); it != attributes.end(); ++it) {
		it->second.setStride(stride);
	}
}

void VertexFormat::addVertexAttribute(VertexAttribute attrib) {
	attributes.insert(std::make_pair(attrib.getIndex(), attrib));
	computeOffsets();
}

void VertexFormat::removeVertexAttribute(VertexAttribute attrib) {
	attributes.erase(attrib.getIndex());
	computeOffsets();
}