#ifndef __SPRITE__H__
#define __SPRITE__H__

#include <d3dx9.h>
#include "Texture.h"

class Sprite
{
protected:
	Texture* _image;
	LPD3DXSPRITE _SpriteHandel;
	D3DXVECTOR3 _Pos; // possition vẽ trên màn hình
	RECT *_RectRS; // rect Resource
	D3DCOLOR _transcolor;

public:
	Sprite(LPD3DXSPRITE spriteHandle);
	~Sprite(void);
	void GetInfoDraw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor);//vị trí đưa vào là vị trí của thế giới thực, nhưng vị trí vẽ là vị trí đã được transform thành vị trí trên màn hình
	void Draw();
};

#endif // !__SPRITE__H__