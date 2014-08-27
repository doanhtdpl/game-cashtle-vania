#include "Font.h"
#include "ManageSprite.h"

Font::Font(void)
{
	this->_height = 32;
	this->_width = 32;
	this->_coloumn = 16;

}

void Font::drawFont(char* s, float x, float y)
{
	D3DXVECTOR3 pos;
	pos.x = x;
	pos.y = y;
	pos.z = 0;
	int num = strlen(s);
	for(int i = 0;i< num;i++)
	{
		if(s[i]!=' ')
		{
			this->_curFrame = (int)s[i]-32;
			if (this->_curFrame <= 0)
			{
				this->_curFrame +=43;
			}
			//sprite->_camera->update(;
			//D3DXVECTOR3 pos_Draw = sprite->_camera->getPointTransform(pos.x, pos.y);

			this->_rectRS = this->updateRectRS(this->_width, this->_height);
			ManageSprite::createInstance()->_Sprite->draw(this->image_font, _rectRS, D3DXVECTOR3(pos.x, pos.y, 0));
			//sprite->_Sprite(this->image_font, _rectRS, D3DXVECTOR3(x, y, 0));
			//sprite->draw(sprite->_image->_Font, _rectRS, pos_Draw, D3DCOLOR_XRGB(255, 255, 255));
			pos.x += _width - 18;
		}
		else
		{
			pos.x += 13;
		}

	}
}

void Font::drawFont(int number, float x, float y)
{
	char chuoi[10];
	sprintf_s(chuoi,"%d",number);
	drawFont(chuoi,x,y);
}

Font::~Font(void)
{
}
