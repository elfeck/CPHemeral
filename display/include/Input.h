#ifndef INPUT_H_
#define INPUT_H_


namespace cph {

struct Input {

	virtual bool isKeyPressed(unsigned char keyId) const = 0;
	virtual bool isKeyReleased(unsigned char keyId) const = 0;
	virtual bool isMouseInWindow() const = 0;

	virtual int getMouseX() const = 0;
	virtual int getMouseY() const = 0;
	virtual int getMouseWheel() const = 0;

};

}


#endif