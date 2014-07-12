#include "Input.h"

Input* Input::_Input_Instance = NULL;

Input::Input(void)
{
}

Input* Input::CreateInstance()
{
	if (_Input_Instance == NULL)
		_Input_Instance = new Input();

	return _Input_Instance;
}

Input::~Input(void)
{
}

int Input::InitInput(HINSTANCE hInstance)
{
	HRESULT result;

	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&_di, NULL);
	if(result != DI_OK)
		return 0;

	result = _di->CreateDevice(GUID_SysKeyboard, &_keyboard, NULL);
	if(result != DI_OK)
		return 0;

	return 1;
}

int Input::InitKeyboard(HWND hWnd)
{
	HRESULT result;
	result = _keyboard->SetDataFormat(&c_dfDIKeyboard);
	if(result != DI_OK)
		return 0;

	result = _keyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(result != DI_OK)
		return 0;

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize       = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj        = 0;
	dipdw.diph.dwHow        = DIPH_DEVICE;
	dipdw.dwData            = KEYBOARD_BUFFER_SIZE;
	_keyboard->SetProperty( DIPROP_BUFFERSIZE, &dipdw.diph );

	result = _keyboard->Acquire();
	if(result != DI_OK)
		return 0;

	return 1;
}

void Input::ProcessKeyboard()
{
	if(_keyboard->GetDeviceState(sizeof(_KeyStates), (LPVOID)_KeyStates) != DI_OK)
	{
		_keyboard->Acquire();
		_keyboard->GetDeviceState(sizeof(_KeyStates), (LPVOID)_KeyStates);
	}
}

//int Input::KeyDown(int KeyCode)
//{
//	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
//	HRESULT hr = _diddv->GetDeviceData( sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0 );
//
//	for( DWORD i = 0; i < dwElements; i++ ) 
//	{
//		int KeyCodeBuffer = _KeyEvents[i].dwOfs;
//		int KeyState = _KeyEvents[i].dwData;
//		if ( (KeyCode == KeyCodeBuffer) && ((KeyState & 0x80) > 0))
//			return 1;
//	}
//	return 0;
//}


void Input::Update()
{
	//poll state of the keyboard
	_keyboard->Poll();
	if (!SUCCEEDED(_keyboard->GetDeviceState(256,(LPVOID)&_KeyStates)))
	{
		//keyboard device lost, try to re-acquire
		_keyboard->Acquire();
	}
	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hr = _keyboard->GetDeviceData( sizeof(DIDEVICEOBJECTDATA), _KeyEvents, &dwElements, 0 );

	// Scan through all data, check if the key is pressed or released
	for( DWORD i = 0; i < dwElements; i++ ) 
	{
		int KeyCode = _KeyEvents[i].dwOfs;
		int KeyState = _KeyEvents[i].dwData;
		if ( (KeyState & 0x80) > 0)
			_KeyDown = KeyCode; 
		else 
			_KeyUP = KeyCode;
	}
}

int Input::IsKeyDown(int KeyCode)
{
	return (_KeyStates[KeyCode] & 0x80) > 0;
}

int Input::GetKeyDown()
{
	int tam = _KeyDown;
	_KeyDown = 0;
	return tam;
}
int Input::GetKeyUp()
{
	int tam = _KeyUP;
	_KeyUP = 0;
	return tam;
}