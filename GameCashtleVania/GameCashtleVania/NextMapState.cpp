#include "NextMapState.h"
#include <d3dx9.h>
#include "ManageTexture.h"
NextMapState::NextMapState()
{
	this->simon = SimonIntroState();
	this->startSimon = false;
	this->bat = BatIntroState();
	this->posSimon = BatIntroState();
}

NextMapState::~NextMapState()
{
}



void NextMapState::initStateGame()
{
	this->vxBackground = 120;
	this->_posBackground = D3DXVECTOR3(500, 150, 0);
	this->_typeState = TypeStateGame::NextMapGame;
	this->simon.init();
	this->simon.setPosAndDes(D3DXVECTOR3(0, 300, 0), D3DXVECTOR3(400, 300, 0));
	this->simon.vx = 120;

	this->bat.init();
	this->bat.setPosAndDes(D3DXVECTOR3(125, 245, 0), D3DXVECTOR3(125, 245, 0));
	this->bat._texture = ManageTexture::getInstance()->getTetureByKey(5003);
	this->bat._width = 32;
	this->bat._height = 26;

	this->posSimon.init();
	this->posSimon.setPosAndDes(D3DXVECTOR3(200, 285, 0), D3DXVECTOR3(200, 285, 0));
	this->posSimon._texture = ManageTexture::getInstance()->getTetureByKey(5004);
	this->posSimon._width = 16;
	this->posSimon._height = 17;
}
void NextMapState::updateStateGame(float deltaTime)
{
	if (startSimon == false)
	{
		if (this->_posBackground.x >= 0)
		{
			this->_posBackground.x -= this->vxBackground*deltaTime;
		}
		else
		{
			this->startSimon = true;
			this->simon.update(deltaTime);
			this->bat.update(deltaTime);
			this->posSimon.update(deltaTime);
		}
	}
	else
	{
		this->simon.update(deltaTime);
		this->bat.update(deltaTime);
		this->posSimon.update(deltaTime);
		if (this->simon.isFinish == true)
		{
			this->_isFinish = true;
		}
	}
     
		
}
void NextMapState::drawStateGame()
{	
	if (this->startSimon == true)
	{
		this->simon.draw(true);
		this->bat.draw();
		this->posSimon.draw();
	}
		
   
	
}
