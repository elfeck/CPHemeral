#ifndef WINDOW_H_
#define WINDOW_H_

#ifdef DISPLAY_EXPORTS
#define CPH_DISPLAY_DLL _declspec(dllexport)
#else
#define CPH_DISPLAY_DLL _declspec(dllimport)
#endif


namespace cph {

struct Window {
	
	virtual void initWindow(int* argc, char* argv[]) = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual int getPositionX() const = 0;
	virtual int getPositionY() const = 0;
	virtual bool isFullscreen() const = 0;
	virtual const char* getTitle() const = 0;

	virtual void setSize(int width, int height) = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual void setFullscreen(bool fullscreen) = 0;
	virtual void setTitle(const char* title) = 0;
	virtual void setIcon(const char* iconPath) = 0;

};

extern "C" {
	CPH_DISPLAY_DLL Window* createWindow();
	CPH_DISPLAY_DLL void deleteWindow(Window* window);
}

}

#endif