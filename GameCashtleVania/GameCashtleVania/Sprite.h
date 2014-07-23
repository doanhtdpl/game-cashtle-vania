#ifndef __SPRITE__H__
#define __SPRITE__H__

#include <d3dx9.h>
#include "Texture.h"

class Sprite
{
protected:
//	Texture* _image;
	LPD3DXSPRITE _SpriteHandel;
	//D3DXVECTOR3 _Pos; // possition vẽ trên màn hình
	//RECT *_RectRS; // rect Resource
	//D3DCOLOR _transcolor;

public:
	Sprite(LPD3DXSPRITE spriteHandle);
	~Sprite(void);
	//ve texture tai vi tri mac dinh la chinh giua
	void draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);
	
	//ve texture tai vi tri mac dinh la chinh giua voi scale
	void draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scale, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);

	//ve texture tai vi tri mac dinh la chinh giua.
	//va lap theo chieu ngang
	void drawFlipX(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);
	
	//ve texture tai vi tri mac dinh la chinh giua.
	//va lap theo chieu doc
	void drawFlipY(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF, bool isCenter = true);
};

#endif // !__SPRITE__H__