#ifndef __MANAGE_GAME___
#define __MANAGE_GAME___

#include "Game.h"
#include "Input.h"
#include "QuadTreeBackground.h"
#include "QuadTreeObject.h"
#include "Simon.h"
#include "Gate.h"
#include "MapLoader.h"
#include "Banner.h"

class ManageGame : public Game
{
private:
	static ManageGame* _instance;

	//int levelCurrent;// level 1
	//int iDScene;// scene 1
	void winGame();
	void loseGame();
	void restartScene();
	void nextScene(int increaseScene);
	void nextLevel();
	void changeScene(float deltaTime);
	bool changeSceneWithGate(float deltaTime);
	void changeSceneTop();
	void changeSceneDown();
	bool pauseGame(float deltaTime);
	bool openGate;
public:
	
	static bool isUseWatchItem;
	float maxNumberSecondEffect;
 	float currentNumberSecondEffect;
	//bien quan ly banner
	BANNER* _banner;

	static int _score;
	float _timeGame;

	QuadTreeBackground* quadTreeBG;
	QuadTreeObject* quadTreeObj;
	Simon* simon;
	bool finish_simon_automove;
	RECT screen;
	InfoScene* _infoScene;
	int level;
	int scene;
	Gate* gate;
	float _timePause;

	//khi simon va cham Hide Object change scene thi goi thang nay = true. --> ChangeScene()
	static bool isChangeScene;
	static bool isChangeTop;
	static bool isChangeDown;
	bool recentlyChangeScene;
	bool acting;


	void gameUpdate(float DeltaTime);
	void gameDraw();
	void gameInit();
	void clear_Screen();
	void processInput();
	void delete_Memory_Game();
public:
	static ManageGame* getInstance();
	ManageGame();
	~ManageGame(void);
};

#endif // !__MANAGE_GAME___