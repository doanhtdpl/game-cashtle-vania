#include "StateGame.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
StateGame::StateGame()
{
	this->_isFinish = false;
	this->_posBackground = D3DXVECTOR3();
	this->_textureBackground = NULL;
}

StateGame::~StateGame()
{
}


void StateGame::update(float deltaTime)
{
	if (this->_isFinish == false)
	{
		this->updateStateGame(deltaTime);
		this->autoMove();
	}
	else
	{
		this->changeStateGame();
	}
	

}


void StateGame::updateStateGame(float deltaTime)
{
	//dinh nghia lop con
}

void StateGame::autoMove()
{
	//dinh nghia lop con
}

void StateGame::changeStateGame()
{
	//dinh nghia lop con
}


void StateGame::draw()
{
	ManageSprite::createInstance()->_Sprite->draw(this->_textureBackground, NULL, this->_posBackground);
	this->drawStateGame();
}

void StateGame::drawStateGame()
{
	//dinh nghia lop con
}


void StateGame::init()
{
	this->_posBackground = D3DXVECTOR3(0, 0, 0);
	this->initStateGame();
	this->_textureBackground = ManageTexture::getInstance()->getTetureByKey((int)this->_typeState);
	
}

void StateGame::initStateGame()
{
	//dinh nghia lop con
}

bool StateGame::isFinish()
{
	return this->_isFinish;
}

