#include "ManageGame.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ManageGame game;
	game.Init(hInstance);
	game.GameRun();
	game.GameEnd();
	return 0;
}