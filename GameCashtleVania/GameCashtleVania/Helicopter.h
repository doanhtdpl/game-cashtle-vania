#ifndef __HELICOPTER_H_
#define __HELICOPTER_H_

#include "IAnimatedSprite.h"
#include <d3dx9.h>
#include "Texture.h"

class Helicopter
{
public:
	Helicopter();
	~Helicopter();
	void update(float deltaTime);
	void draw();
	void init();
private:
	D3DXVECTOR3 _pos;
	int desX;
	int widthMoving;
	Texture* _texture;
	int vx;
};


#endif // !__HELICOPTER_H_
