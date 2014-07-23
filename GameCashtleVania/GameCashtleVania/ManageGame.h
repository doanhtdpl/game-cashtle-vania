#ifndef __MANAGE_GAME___
#define __MANAGE_GAME___

#include "Game.h"
#include "Input.h"
#include "BackGround.h"
#include "Brick.h"

class ManageGame : public Game
{
public:
	static int _Word_Map;
	static int _count_LifeMario;
	static int _score;
	BackGround* mapBG;
	Brick* brick;

	void gameUpdate(float DeltaTime);
	void gameDraw();
	void gameInit();
	void clear_Screen();
	void processInput();
	void delete_Memory_Game();
public:
	ManageGame(void);
	~ManageGame(void);
};

#endif // !__MANAGE_GAME___
