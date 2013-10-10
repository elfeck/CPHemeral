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

bool VertexFormat::isCompatible(const std::set<AttributeFormat>& attributeFormat) const {
	bool found = false;
	for(std::set<AttributeFormat>::iterator it1 = attributeFormat.begin(); it1 != attributeFormat.end(); ++it1) {
		found = false;
		for(std::map<GLuint, VertexAttribute>::const_iterator it2 = attributes.begin(); it2 != attributes.end(); ++it2) {
			found = found || it1->getName() == it2->second.getName();
		}
		if(!found) return false;
	}
	return true;
}

void VertexFormat::bindVertexAttributesGL() const {
	for(std::map<GLuint, VertexAttribute>::const_iterator it = attributes.begin(); it != attributes.end(); ++it) {
		it->second.bindVertexPointerGL();
	}
}