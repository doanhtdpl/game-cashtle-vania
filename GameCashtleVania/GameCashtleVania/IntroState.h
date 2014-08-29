#ifndef __INTRO_STATE_H_
#define __INTRO_STATE_H_

#include "StateGame.h"
#include "Banner.h"
#include "Helicopter.h"
#include "BatIntroState.h"
#include "SimonIntroState.h"
class IntroState : public StateGame
{
public:
	IntroState();
	~IntroState();
private:
	Helicopter helicopter;
	BANNER banner;
	BatIntroState bat1;
	BatIntroState bat2;
	SimonIntroState simon;
	virtual void initStateGame();
	virtual void updateStateGame(float deltaTime);
	virtual void drawStateGame();
	virtual void changeStateGame();
};

#endif // !__INTRO_STATE_H_
