#include "utils.h"
#include "Game.h"

Game::Game()
{
	this->_d3d = NULL;
	this->_d3ddv = NULL;
	this->_hWnd = NULL;
	this->_BackBuffer = NULL;

	this->_FrameRate = Frame_Rate;
}

Game::~Game(void)
{
	if (!_d3d)
		_d3d->Release();

	if (_d3ddv != NULL)
		_d3ddv->Release();

	if(!SpriteHandle)
	{
		SpriteHandle->Release();
	}
}

HWND Game::getWindowHandle()
{
	return _hWnd;
}

LPDIRECT3DDEVICE9 Game::getD3DDEVICE()
{
	return _d3ddv;
}

/*************************
	Init_Window
	Acess: private
*************************/
bool Game::Init_Window(HINSTANCE hInstance)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)Game::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = ClassName;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	_hWnd = 
		CreateWindow(
			ClassName,
			ClassName,
			WS_OVERLAPPEDWINDOW, 
			CW_USEDEFAULT,
			CW_USEDEFAULT, 
			Screen_Width,
			Screen_Height,
			NULL,
			NULL,
			hInstance,
			NULL);
	
	if (!_hWnd) 
	{ 
		return false;
	}

	ShowWindow(_hWnd,SW_SHOWNORMAL);
	UpdateWindow(_hWnd);

	return true;
}


bool Game::Init_Direct3D()
{
	_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp; 

	ZeroMemory( &d3dpp, sizeof(d3dpp) );

	d3dpp.Windowed = TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8; 
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = Screen_Height;
	d3dpp.BackBufferWidth = Screen_Width;

	_d3d->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			_hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&_d3ddv);

	if (_d3ddv==NULL) 
	{
		return false;
	}
	
	D3DXCreateSprite(_d3ddv, &SpriteHandle);
	_d3ddv->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&_BackBuffer);
	return true;
}

bool Game::Init(HINSTANCE hInstance)
{
	if (!Init_Window(hInstance))
		return false;

	if (!Init_Direct3D())
		return false;
	
	_Input = Input::CreateInstance();

	if(!_Input->InitInput(hInstance))
	{
		return false;
	}

	if(!_Input->InitKeyboard(_hWnd))
	{
		return false;
	}

	gameInit();
	return true;
}

void Game::GameRun()
{
	MSG msg;
	int done = 0;
	DWORD frame_start = GetTickCount();
	
	DWORD tick_per_frame = 1000 / _FrameRate;

	while (!done) 
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT) done=1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);			
		}

		DWORD now = GetTickCount();//Xem lai sau
		_DeltaTime = (now - frame_start); 
		if (_DeltaTime >= tick_per_frame)
		{
			frame_start = now;
			processInput();
			float delta_time = (float)_DeltaTime / 1000;
			gameUpdate(delta_time);
			Render();
		}
	}
}

void Game::GameEnd()
{
	this->delete_Memory_Game();

	if (_d3ddv!=NULL) _d3ddv->Release();
	if (_d3d!=NULL) _d3d->Release();

	if(SpriteHandle)
	{
		SpriteHandle->Release();
	}
}

void Game::Render()
{
	_d3ddv->BeginScene();//bat dau render
	clear_Screen();
	//xoa man hinh
	SpriteHandle->Begin(D3DXSPRITE_ALPHABLEND);//render 2D
	gameDraw();//render game 2D
	SpriteHandle->End();

	_d3ddv->EndScene();
	_d3ddv->Present(NULL, NULL, NULL, NULL);
}

void Game::gameDraw()
{

}

void Game::gameUpdate(float deltatime)
{

}

LRESULT CALLBACK Game::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
		case WM_DESTROY: 
			PostQuitMessage(0);
			break;
		default: 
			return DefWindowProc(hWnd, message, wParam,lParam);
	}

	return 0;
}


