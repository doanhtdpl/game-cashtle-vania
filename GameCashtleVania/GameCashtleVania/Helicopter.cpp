#include "Helicopter.h"
#include "ManageSprite.h"
#include "ManageTexture.h"
Helicopter::Helicopter()
{
	
}

Helicopter::~Helicopter()
{
}

void Helicopter::init()
{
	this->vx = 15;
	this->_pos = D3DXVECTOR3(400, 210, 0);
	this->desX =  -100 + this->_pos.x;
	this->_texture = ManageTexture::getInstance()->getTetureByKey((int)5005);

}
void Helicopter::update(float deltaTime)
{
	if (this->_pos.x < this->desX)
	{	
		this->vx = abs(this->vx);
	}
	else if (this->_pos.x > this->desX)
	{
		this->vx = -abs(this->vx);
	}
	else
	{
		if (this->vx > 0)
		{
			this->desX -= 100;
		}
		else
		{
			this->desX += 100;
		}
	}

	this->_pos.x += this->vx*deltaTime * 0.3;
}
void Helicopter::draw()
{
	ManageSprite::createInstance()->_Sprite->draw(this->_texture, NULL, this->_pos);
}
