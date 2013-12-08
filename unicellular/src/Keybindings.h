#ifndef KEYBINDINGS_H_
#define KEYBINDINGS_H_

#include <unordered_map>
#include "CPHDisplay.h"
#include "CPHUtils.h"


namespace cph {

enum Bindings {
	CAMERA_UP, CAMERA_LEFT, CAMERA_DOWN, CAMERA_RIGHT, 
	PLAYER_MOVE
};

class Keybindings {

private:
	Input* input;
	std::unordered_map<unsigned int, unsigned char> bindingMap;

public:
	Keybindings();
	~Keybindings();

	void setInput(Input* input);

	bool isKeyPressed(unsigned int bind) const;
	bool isKeyReleased(unsigned int bind) const;
	bool isMouseInWindow() const;

	int getMouseX() const;
	int getMouseY() const;
	int getMouseWheel() const;

	void setBinding(unsigned int bind, unsigned char key);

};



};


#endif