#include "Sprite.h"


Sprite::Sprite(LPD3DXSPRITE sprite)
{
	this->_SpriteHandel = sprite;
}


Sprite::~Sprite(void)
{
}

void Sprite::GetInfoDraw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor)
{
	this->_image = image;
	this->_RectRS = RectRS;
	this->_Pos = pos;
	this->_transcolor = transcolor;
}

void Sprite::Draw()
{
	this->_SpriteHandel->Draw(_image->Get_Texture(), _RectRS, NULL, &_Pos, _transcolor);
}

