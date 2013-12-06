#include <algorithm>
#include "Keybindings.h"


using namespace cph;

Keybindings::Keybindings() :
	input(), bindingMap()
{
	bindingMap.insert(std::make_pair(CAMERA_UP, Key::W));
	bindingMap.insert(std::make_pair(CAMERA_LEFT, Key::A));
	bindingMap.insert(std::make_pair(CAMERA_DOWN, Key::S));
	bindingMap.insert(std::make_pair(CAMERA_RIGHT, Key::D));
	bindingMap.insert(std::make_pair(PLAYER_MOVE, Mouse::LEFT));
}

Keybindings::~Keybindings() {

}

void Keybindings::setInput(Input* input) {
	this->input = input;
}

bool Keybindings::isKeyPressed(unsigned int bind) const {
	return input->isKeyPressed(bindingMap.at(bind));
}

bool Keybindings::isKeyReleased(unsigned int bind) const {
	return input->isKeyReleased(bindingMap.at(bind));
}

bool Keybindings::isMouseInWindow() const {
	return input->isMouseInWindow();
}

int Keybindings::getMouseX() const {
	return input->getMouseX();
}

int Keybindings::getMouseY() const {
	return input->getMouseY();
}

int Keybindings::getMouseWheel() const {
	return input->getMouseWheel();
}

void Keybindings::setBinding(unsigned int bind, unsigned char key) {
	bindingMap.at(bind) = key;
}
