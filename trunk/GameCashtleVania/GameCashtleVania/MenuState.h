#ifndef __MENU_STATE_H_
#define __MENU_STATE_H_

#include "Font.h"
#include "StateGame.h"
#include "MenuAnimation.h"
#define TIME_HIDE_TEXT 0.5
class MenuState : public StateGame
{
protected:
	//font
	float currentTime;
	bool isHideText;
	Font* _pFont;
	MenuAnimation batAnimation;
public:
	virtual void initStateGame();
	virtual void updateStateGame(float deltaTime);
	virtual void drawStateGame();
	virtual void changeStateGame();
	MenuState();
	~MenuState();

private:

};


#endif // !__MENU_STATE_H_
