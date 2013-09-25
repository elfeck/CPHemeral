#ifndef FREEGLUT_WINDOW_H_
#define FREEGLUT_WINDOW_H_

#include <string>

#include "../include/Window.h"


namespace cph {

class FreeglutWindow : public Window {

private:
	int width, height, posX, posY;
	bool fullscreen, initialized;
	std::string title;

public:
	FreeglutWindow();
	~FreeglutWindow();

	virtual void initWindow(int* argc, char* argv[]);

	virtual int getWidth() const;
	virtual int getHeight() const;
	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual bool isFullscreen() const;
	virtual const char* getTitle() const;

	virtual void setSize(int width, int height);
	virtual void setPosition(int x, int y);
	virtual void setFullscreen(bool fullscreen);
	virtual void setTitle(const char* title);
	virtual void setIcon(const char* iconPath);

	bool isInitialized();
	void setWidth(int width);
	void setHeight(int height);
};

}

#endif