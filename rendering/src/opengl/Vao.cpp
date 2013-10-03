#include "Vao.h"


using namespace cph;

Vao::Vao() :
	vaoHandle(), vboHandle(), iboHandle(),
	usage(), mode()
{

}

Vao::~Vao() {

}

void Vao::drawGL(std::vector<VaoEntry*> entries) {

}
