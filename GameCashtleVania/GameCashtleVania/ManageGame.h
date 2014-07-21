#ifndef __MANAGE_GAME___
#define __MANAGE_GAME___

#include "Game.h"
#include "Input.h"

#include "Brick.h"

class ManageGame : public Game
{
public:
	static int _Word_Map;
	static int _count_LifeMario;
	static int _score;

	Brick* brick;

	void GameUpdate(float DeltaTime);
	void GameDraw();
	void GameInit();
	void Clear_Screen();
	void ProcessInput();
	void Delete_Memory_Game();
public:
	ManageGame(void);
	~ManageGame(void);
};

#endif // !__MANAGE_GAME___
