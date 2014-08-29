#ifndef __SIMON_INTRO_STATE_H_
#define __SIMON_INTRO_STATE_H_

#include "IAnimatedSprite.h"
#include <d3dx9.h>
#include "Texture.h"
class SimonIntroState : IAnimatedSprite
{
public:
	SimonIntroState();
	~SimonIntroState();
	virtual void animated(float deltaTime);
	void setPosAndDes(D3DXVECTOR3 pos, D3DXVECTOR3 des);
	void update(float deltaTime);
	void draw(bool isFlipX);
	void init();
	void move(float deltaTime);
	bool isFinish;
	int vx;
private:
	D3DXVECTOR3 _pos;
	D3DXVECTOR3 _des;
	Texture* _texture;
	RECT* _rect;
	
	int vy;
	int vxDefault;
	int vyDefault;
	int _width;
	int _height;
	
};


#endif // !__BAT_INTRO_STATE_H_
