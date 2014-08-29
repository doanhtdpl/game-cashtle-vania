#ifndef __BAT_INTRO_STATE_H_
#define __BAT_INTRO_STATE_H_

#include "IAnimatedSprite.h"
#include <d3dx9.h>
#include "Texture.h"
class BatIntroState : IAnimatedSprite
{
public:
	BatIntroState();
	~BatIntroState();
	void update(float deltaTime);
	void draw();
	void init();
	void move(float deltaTime);
	void setPosAndDes(D3DXVECTOR3 pos, D3DXVECTOR3 des);
	Texture* _texture;
	int _width;
	int _height;
private:	
	D3DXVECTOR3 _pos;
	D3DXVECTOR3 _des;
	
	RECT* _rect;
	int vx;
	int vy;
	int vxDefault;
	int vyDefault;
		
};


#endif // !__BAT_INTRO_STATE_H_
