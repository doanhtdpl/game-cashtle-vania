#ifndef __MANAGE_GAME___
#define __MANAGE_GAME___

#include "Game.h"
#include "Input.h"
#include "QuadTreeBackground.h"
#include "QuadTreeObject.h"
#include "Simon.h"

class ManageGame : public Game
{
private:
	static ManageGame* _instance;

	int levelCurrent;// level 1
	int iDScene;// scene 1
	void winGame();
	void loseGame();
	void restartScene();
	void nextScene();
	void nextLevel();
	void changeScene(float deltaTime);
public:
	//bien co cho khi simon dung item watch
  static	bool isUseWatchItem;
   int maxNumberSecondEffect;
 	int currentNumberSecondEffect;
	
 
   static int _score;
	
	QuadTreeBackground* quadTreeBG;
	QuadTreeObject* quadTreeObj;
	Simon* simon;
	RECT screen;
	int level;
	int scene;

	//khi simon va cham Hide Object change scene thi goi thang nay = true. --> ChangeScene()
	static bool isChangeScene;
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