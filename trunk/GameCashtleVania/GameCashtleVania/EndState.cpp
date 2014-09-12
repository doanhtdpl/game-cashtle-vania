#include "EndState.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "ManageAudio.h"
void EndState::initStateGame()
{
	this->_posBackground = D3DXVECTOR3(0, 0, 0);
	this->_typeState = TypeStateGame::EndGame;

	this->textureCastle = ManageTexture::getInstance()->getTetureByKey((int)EndStateIdTexture::Castle);
	this->posCastle = D3DXVECTOR3(350, 120,0);

	this->textureBottomBG = ManageTexture::getInstance()->getTetureByKey((int)EndStateIdTexture::BottomBG);
	this->posBottomBG = D3DXVECTOR3(0, 180, 0);

	for (int i = 0; i < 11; i++)
	{
		this->textureText[i] = ManageTexture::getInstance()->getTetureByKey((int)EndStateIdTexture::Text1 + i);
	}
	this->posText = D3DXVECTOR3(35, 80, 0);
	this->currentText = -1;
	this->delay = 0;
	this->maxTimeDelay = 0.5;
}
void EndState::updateStateGame(float deltaTime)
{
	delay += deltaTime;	
	if (this->delay > this->maxTimeDelay)
	{
		if (this->posCastle.y < 200)
		{
			ManageAudio::getInstance()->playSound(TypeAudio::Falling);
			this->posCastle.y += 3;
			
		}
		else
		{
			this->maxTimeDelay = 3;
			ManageAudio::getInstance()->playSound(TypeAudio::Title_Theme_Prelude);
			this->currentText++;
			if (this->currentText > 11)
			{
				this->_isFinish = true;
			}
		}
		delay = 0;		
		return;
	}
}
void EndState::drawStateGame()
{
	ManageSprite::createInstance()->_Sprite->draw(this->textureCastle, NULL, this->posCastle);
	ManageSprite::createInstance()->_Sprite->draw(this->textureBottomBG, NULL, this->posBottomBG);
	if (this->currentText > -1 && this->currentText < 11)
	{
		ManageSprite::createInstance()->_Sprite->draw(this->textureText[this->currentText], NULL, this->posText);
	}
	
}
EndState::EndState()
{
	this->textureCastle = NULL;
}

EndState::~EndState()
{
}