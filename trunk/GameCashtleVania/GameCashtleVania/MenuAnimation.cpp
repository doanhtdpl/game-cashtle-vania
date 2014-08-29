#include "MenuAnimation.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
MenuAnimation::MenuAnimation()
{
	this->_width = 144;
	this->_height = 112;

	//IAniamted Sprite
	this->_coloumn = 5;
	this->_totalFrames = 15;
	this->_elapseTimeSwitchFrame = 0.2;
	this->_curFrame = 0;
	this->_beforeTimeOld = 0.0f;


	this->_pos = D3DXVECTOR3();
	this->_texture = NULL;	
}

MenuAnimation ::~MenuAnimation()
{
}

void MenuAnimation::init()
{
	this->_texture = ManageTexture::getInstance()->getTetureByKey((int)5002);
	this->_pos = D3DXVECTOR3(430, 290, 0);
}
void MenuAnimation::update(float deltaTime)
{
	animated(deltaTime);
	this->_rect = this->updateRectRS(this->_width, this->_height);
}
void MenuAnimation::draw()
{
	ManageSprite::createInstance()->_Sprite->draw(this->_texture, this->_rect, this->_pos);
}
