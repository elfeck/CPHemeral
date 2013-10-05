#include "Vao.h"


using namespace cph;

Vao::Vao() :
	vaoHandle(), vboHandle(), iboHandle(),
	usage(), mode()
{

}

Vao::~Vao() {

}

void Vao::addVaoEntry(VaoEntry* entry) {

}

void Vao::removeVaoEntry(VaoEntry* entry) {

}

bool Vao::hasShader(std::string shaderPath) {
	return shaderPrograms.count(shaderPath) == 1;
}

void Vao::drawGL() {

}
