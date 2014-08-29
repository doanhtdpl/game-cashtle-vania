#include "BatIntroState.h"
#include "ManageSprite.h"
#include "ManageTexture.h"
BatIntroState::BatIntroState()
{
	this->_width = 16;
	this->_height = 16;

	//IAniamted Sprite
	this->_coloumn = 2;
	this->_totalFrames = 2;
	this->_elapseTimeSwitchFrame = 0.15;
	this->_curFrame = 0;
	this->_beforeTimeOld = 0.0f;


	this->_pos = D3DXVECTOR3();
	this->_texture = NULL;

	this->vxDefault = 15;
	this->vyDefault = 10;
}

BatIntroState::~BatIntroState()
{
}


void BatIntroState::init()
{
	this->_texture = ManageTexture::getInstance()->getTetureByKey((int)5001);
	this->_pos = D3DXVECTOR3(250, 150, 0);
	this->_des = D3DXVECTOR3(300, 100, 0);
}
void BatIntroState::update(float deltaTime)
{
	animated(deltaTime);
	this->move(deltaTime);
	this->_rect = this->updateRectRS(this->_width, this->_height);
}
void BatIntroState::draw()
{
	ManageSprite::createInstance()->_Sprite->draw(this->_texture, this->_rect, this->_pos);
}

void BatIntroState::move(float deltaTime)
{ 	
	if (this->_pos.x < this->_des.x)
	{
		this->vx = vxDefault;
	}
	else if (this->_pos.x > this->_des.x)
	{
		this->vx = -vxDefault;
	}
	else
	{
		this->vx = 0;
	}

	if (this->_pos.y < this->_des.y)
	{
		this->vy = vyDefault;
	}
	else if (this->_pos.y > this->_des.y)
	{
		this->vy = -vyDefault;
	}
	else
	{
		this->vy = 0;
	}

	this->_pos.x += this->vx*deltaTime;
	this->_pos.y += this->vy*deltaTime;
}

void BatIntroState::setPosAndDes(D3DXVECTOR3 pos, D3DXVECTOR3 des)
{
	this->_pos = pos;
	this->_des = des;
}