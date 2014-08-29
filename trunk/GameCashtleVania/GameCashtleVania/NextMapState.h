#ifndef __NEXT_MAP_STATE_H_
#define __NEXT_MAP_STATE_H_

#include "StateGame.h"
#include "SimonIntroState.h"
#include "BatIntroState.h"
class NextMapState : public StateGame
{

public:
	virtual void initStateGame();
	virtual void updateStateGame(float deltaTime);	
	virtual void drawStateGame();
	NextMapState();
	~NextMapState();
private:
	int vxBackground;
	bool startSimon;
	BatIntroState bat;
	BatIntroState posSimon;
	SimonIntroState simon;
	
};


#endif // !__NEXT_MAP_STATE_H_
