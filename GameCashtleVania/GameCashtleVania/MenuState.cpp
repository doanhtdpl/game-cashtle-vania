#include "MenuState.h"
#include "ManageTexture.h"
MenuState::MenuState() 
{
	this->_typeState = TypeStateGame::MenuGame;
	this->_pFont = new Font();
	this->currentTime = 0;
	this->isHideText = false;
	this->batAnimation = MenuAnimation();
}

MenuState::~MenuState()
{
}

void MenuState::initStateGame()
{
	this->_pFont->image_font = ManageTexture::getInstance()->getTetureByKey((int)3003);
	this->batAnimation.init();
}
void MenuState::updateStateGame(float deltaTime)
{
	this->currentTime += deltaTime;
	if ( this->currentTime > TIME_HIDE_TEXT)
	{
		this->currentTime = 0;
		this->isHideText = !this->isHideText;
	}
	this->batAnimation.update(deltaTime);
}

void MenuState::drawStateGame()
{
	this->batAnimation.draw();
	if (this->isHideText == false)
	{
		this->_pFont->drawFont("PUSH  ENTER  KEY", 160, 250);
	}		
}
void MenuState::changeStateGame()
{
}