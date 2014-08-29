#include "IntroState.h"
#include "Weapon.h"
IntroState::IntroState()
{
	this->_typeState = TypeStateGame::IntroGame;
	this->banner = BANNER();
	this->helicopter = Helicopter();
	this->bat1 = BatIntroState();
	this->bat2 = BatIntroState();
	this->simon = SimonIntroState();
	
}

IntroState::~IntroState()
{
}


void IntroState::initStateGame()
{
	this->helicopter.init();
	this->banner.init();	
	this->bat1.init();
	this->bat1.setPosAndDes(D3DXVECTOR3(70, 300, 0), D3DXVECTOR3(250, 200, 0));
	this->bat2.init();
	this->bat2.setPosAndDes(D3DXVECTOR3(90, 150, 0), D3DXVECTOR3(190, 220, 0));
	this->simon.init();
	this->_posBackground = D3DXVECTOR3(0, 80, 0);
	this->banner._countHeartSimon = 5;
	this->banner._hpEnemy = 16;
	this->banner._hpSimon = 16;
	this->banner._numberSimon = 5;
	this->banner._scene = 1;
	this->banner._score = 0;
	this->banner._time = 300;
	this->banner._typeWeapon = TypeWeapon::None;
	this->banner.textureWeapon = NULL;
}
void IntroState::updateStateGame(float deltaTime)
{
	this->helicopter.update(deltaTime);
	this->bat1.update(deltaTime);
	this->bat2.update(deltaTime);
	this->simon.update(deltaTime);
	this->_isFinish = this->simon.isFinish;
}
void IntroState::drawStateGame()
{
	this->banner.draw();
	this->helicopter.draw();
	this->bat1.draw();
	this->bat2.draw();
	this->simon.draw(false);
}
void IntroState::changeStateGame()
{
}