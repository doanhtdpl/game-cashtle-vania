#ifndef __GAME__H__
#define __GAME__H__

#include <d3d9.h>
#include <d3dx9.h>
#include "Input.h"

class Game
{
protected:
	HWND		_hWnd;
	LPDIRECT3D9	_d3d;
	LPDIRECT3DDEVICE9 _d3ddv;
	LPDIRECT3DSURFACE9 _BackBuffer;
	LPD3DXSPRITE SpriteHandle;

	Input* _Input;

	int _FrameRate; 
	DWORD _DeltaTime;		// Time between the last frame and current frame

	bool Init_Window(HINSTANCE );
	bool Init_Direct3D();
	virtual void gameUpdate(float DeltaTime) = 0;
	virtual void gameDraw() = 0;
	virtual void gameInit() = 0;
	virtual void clear_Screen() = 0;
	virtual void processInput() = 0;
	virtual void delete_Memory_Game() = 0;
	void Render();

	static LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
public:
	Game();
	HWND getWindowHandle();
	LPDIRECT3DDEVICE9 getD3DDEVICE();

	bool Init(HINSTANCE );
	void GameRun();
	void GameEnd();
	~Game(void);
};

#endif // !__GAME__H__