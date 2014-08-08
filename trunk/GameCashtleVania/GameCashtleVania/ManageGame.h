#ifndef __MANAGE_GAME___
#define __MANAGE_GAME___

#include "Game.h"
#include "Input.h"
#include "BackGround.h"
#include "Map.h"

class ManageGame : public Game
{
private:
	int levelCurrent;// level 1
	int iDScene;// scene 1
	void WinGame();
	void LoseGame();
	void RestartScene();
	void NextScene();
	void NextLevel();
public:
	static int _count_LifeMario;
	static int _score;
	BackGround* _mapBG;
	Map* _map;
	int level;
	int scene;

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
