#ifndef __INPUT__H__
#define __INPUT__H__

#include <dinput.h>

#define KEYBOARD_BUFFER_SIZE 256
class Input
{
private:
	static Input* _Input_Instance;
	LPDIRECTINPUT8 _di;
	LPDIRECTINPUTDEVICE8 _keyboard;

	int Keyboard_Buffer_Size;
	BYTE  _KeyStates[256];
	DIDEVICEOBJECTDATA _KeyEvents[ KEYBOARD_BUFFER_SIZE ];
	int _KeyUP,_KeyDown;

public:
	Input(void);
	~Input(void);
	static Input* CreateInstance();
	int InitInput(HINSTANCE hInstance);
	int InitKeyboard(HWND hWnd);

	// Lấy trạng thái bàn phím
	void ProcessKeyboard();

	//// Xử lí keydown = buffer
	//int KeyDown(int KeyCode);

	//Update KeyState tu KeyEvents
	void Update();

	//Lay trang thai phim voi "key"
	BYTE GetKeyState(int key) { return _KeyStates[key]; }

	// Xử lí keydown
	int IsKeyDown(int KeyCode);

	int GetKeyDown();
	int GetKeyUp();

};

#endif // !__INPUT__H__