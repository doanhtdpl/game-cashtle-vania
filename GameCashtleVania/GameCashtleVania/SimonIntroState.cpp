#include "SimonIntroState.h"
#include "ManageSprite.h"
#include "ManageTexture.h"
SimonIntroState::SimonIntroState()
{
	this->_width = 60;
	this->_height = 66;

	//IAniamted Sprite
	this->_coloumn = 8;
	this->_totalFrames = 18;
	this->_elapseTimeSwitchFrame = 0.15;
	this->_curFrame = 0;
	this->_beforeTimeOld = 0.0f;


	this->_pos = D3DXVECTOR3();
	this->_texture = NULL;

	this->vxDefault = 50;

	this->isFinish = false;
}

SimonIntroState::~SimonIntroState()
{
}


void SimonIntroState::init()
{
	this->_texture = ManageTexture::getInstance()->getTetureByKey((int)1001);
	this->_pos = D3DXVECTOR3(500, 450, 0);
	this->_des = D3DXVECTOR3(250, 450, 0);
	this->isFinish = false;
}


void SimonIntroState::animated(float deltaTime)
{
	this->_beforeTimeOld += deltaTime;	
    
	if (this->isFinish == true)
	{
		_curFrame = 9;
	}
	else
	{
		if (_beforeTimeOld > _elapseTimeSwitchFrame)
		{
			_beforeTimeOld -= _elapseTimeSwitchFrame;

			this->_curFrame++;
			if (_curFrame > 3)
			{
				_curFrame = 0;
			}
		}
	}
  	
	this->_rect = this->updateRectRS(this->_width, this->_height);
}
void SimonIntroState::update(float deltaTime)
{	
	this->move(deltaTime);
	animated(deltaTime);
	this->_rect = this->updateRectRS(this->_width, this->_height);
}
void SimonIntroState::draw(bool isFlipX)
{
	if (isFlipX == true)
	{
		ManageSprite::createInstance()->_Sprite->drawFlipX(this->_texture, this->_rect, this->_pos);
	}
	else
	{
		ManageSprite::createInstance()->_Sprite->draw(this->_texture, this->_rect, this->_pos);
	}
	
}


void SimonIntroState::move(float deltaTime)
{	
	if (this->isFinish == false)
	{
		if (abs(this->_pos.x - this->_des.x) <= 10)
		{
			this->isFinish = true;
			this->vx = 0;
		}
		else if (this->_pos.x < this->_des.x)
		{
			this->vx = vxDefault;
		}
		else if (this->_pos.x > this->_des.x)
		{
			this->vx = -vxDefault;
		}				
		this->_pos.x += this->vx*deltaTime;
	}
	
		
}

void SimonIntroState::setPosAndDes(D3DXVECTOR3 pos, D3DXVECTOR3 des)
{
	this->_pos = pos;
	this->_des = des;
}