#ifndef DISPLAY_H_
#define DISPLAY_H_

#ifdef DISPLAY_EXPORTS
#define CPH_DISPLAY_DLL _declspec(dllexport)
#else
#define CPH_DISPLAY_DLL _declspec(dllimport)
#endif


namespace cph {

struct Window;
class Log;

struct Display {

	virtual void initDisplay(Window* window) = 0;
	virtual void setMainFunc(void (*mainFunc)(long)) = 0;
	virtual void setRenderFunc(void (*renderFunc)(long)) = 0;
	virtual void setWindow(Window* window) = 0;

	virtual void enterMainLoop() = 0;
	virtual void exitMainLoop() = 0;

	virtual bool isKeyPressed(unsigned char keyId) const = 0;
	virtual bool isKeyReleased(unsigned char keyId) const = 0;
	virtual bool isMouseInWindow() const = 0;

	virtual int getMouseX() const = 0;
	virtual int getMouseY() const = 0;
	virtual int getMouseWheel() const = 0;

	virtual void setLog(cph::Log* log, const char* target = 0) = 0;
	virtual void setLooptimeLogTime(int ms) = 0;

	virtual ~Display() = 0;

};

extern "C" {	
	CPH_DISPLAY_DLL Display* createDisplay();
	CPH_DISPLAY_DLL void deleteDisplay(Display* display);
}

enum Key {
	A = 'a', CAP_A = 'A',
	B = 'b', CAP_B = 'B',
	C = 'c', CAP_C = 'C',
	D = 'd', CAP_D = 'D',
	E = 'e', CAP_E = 'E',
	F = 'f', CAP_F = 'F',
	G = 'g', CAP_G = 'G',
	H = 'h', CAP_H = 'H',
	I = 'i', CAP_I = 'I',
	J = 'j', CAP_J = 'J',
	K = 'k', CAP_K = 'K',
	L = 'l', CAP_L = 'L',
	M = 'm', CAP_M = 'M',
	N = 'n', CAP_N = 'N',
	O = 'o', CAP_O = 'O',
	P = 'p', CAP_P = 'P',
	Q = 'q', CAP_Q = 'Q',
	R = 'r', CAP_R = 'R',
	S = 's', CAP_S = 'S',
	T = 't', CAP_T = 'T',
	U = 'u', CAP_U = 'U',
	V = 'v', CAP_V = 'V',
	W = 'w', CAP_W = 'W',
	X = 'x', CAP_X = 'X',
	Y = 'y', CAP_Y = 'Y',
	Z = 'z', CAP_Z = 'Z',

	CARET = '^',
	NUM_0 = '0', EQUALS = '=', BRACES_CLOSE = '}',
	NUM_1 = '1', EXCLAMATION = '!', 
	NUM_2 = '2', QUOTATION = '"',
	NUM_3 = '3', PARAGRAPH = '§',
	NUM_4 = '4', DOLLAR = '$',
	NUM_5 = '5', PERCENT = '%',
	NUM_6 = '6', AMPERSAND = '&',
	NUM_7 = '7', SLASH = '/', BRACES_OPEN = '{',
	NUM_8 = '8', PARENTHESES_OPEN = '(', BRACKET_OPEN = '[',
	NUM_9 = '9', PARENTHESES_CLOSE = ')', BRACKET_CLOSE = ']',
	
	QUEST = '?', BACKSLASH = 92,
	ACCENT_ACUTE = '´', ACCENT_GRAVE = '`',
	PLUS = '+', ASTERISK = '*', TILDE = '~',
	NUM = '#', APOSTROPHE = 39,
	LESS = '<', GREATER = '>', VERTICAL = '|',
	SPACE = ' ',
	COMMA = ',', SEMICOLON = ';', 
	DOT = '.', COLON = ':',
	HYPHEN = '-', UNDERSCORE = '_',

	ESCAPE = 27, TAB = 9, BACKSPACE = 8, ENTER = 13,

	ARROW_LEFT = 128,
	ARROW_UP = 129,
	ARROW_RIGHT = 130,
	ARROW_DOWN = 131,

	F1 = 132,
	F2 = 133,
	F3 = 134,
	F4 = 135,
	F5 = 136,
	F6 = 137,
	F7 = 138,
	F8 = 139,
	F9 = 140,
	F10 = 141,
	F11 = 142,
	F12 = 143,

	SHIFT_L = 144, SHIFT_R = 145,
	ALT_L = 146, ALT_R = 147
};

enum Mouse {
	LEFT = 200,
	MIDDLE = 201,
	RIGHT = 202,
	DRAG = 203
};

}

#endif