#ifndef __STATE_GAME_H_
#define __STATE_GAME_H_

#include "Texture.h"
#include <d3dx9.h>

enum TypeStateGame
{
	IntroGame = 4001,
	MenuGame = 4002,
	NextMapGame = 4003,	
	EndGame = 4004,
	PlayGame = 4005
};

class StateGame
{
public:
	virtual bool isFinish();
	void init();
	void update(float deltaTime);
	void draw();
	StateGame();
	~StateGame();

protected:
	TypeStateGame _typeState;
	D3DXVECTOR3 _posBackground;	
	Texture* _textureBackground;
	bool _isFinish;

	virtual void initStateGame();
	virtual void updateStateGame(float deltaTime);
	virtual void autoMove();
	virtual void drawStateGame();
	virtual void changeStateGame();

};


#endif // !__StateGame_H_
