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
	virtual void GameUpdate(DWORD DeltaTime) = 0;
	virtual void GameDraw() = 0;
	virtual void GameInit() = 0;
	virtual void Clear_Screen() = 0;
	virtual void ProcessInput() = 0;
	virtual void Delete_Memory_Game() = 0;
	void Render();

	static LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
public:
	Game();
	HWND GetWindowHandle();
	LPDIRECT3DDEVICE9 GetD3DDEVICE();

	bool Init(HINSTANCE );
	void GameRun();
	void GameEnd();
	~Game(void);
};

#endif // !__GAME__H__