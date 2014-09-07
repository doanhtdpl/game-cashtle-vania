#ifndef __END_STATE_H_
#define __END_STATE_H_

#include "StateGame.h"
#include <d3dx9.h>
enum EndStateIdTexture
{
	Castle = 5006,
	BottomBG = 5007,
	Text1 = 5008
};
class EndState : public StateGame
{
public:
	virtual void initStateGame();
	virtual void updateStateGame(float deltaTime);
	virtual void drawStateGame();
	EndState();
	~EndState();
	Texture *textureCastle;
	D3DXVECTOR3 posCastle;
	
	Texture *textureBottomBG;
	D3DXVECTOR3 posBottomBG;

	Texture *textureText[11];
	D3DXVECTOR3 posText;
	int currentText;

	float delay;
private:

};


#endif // !__END_STATE_H_
