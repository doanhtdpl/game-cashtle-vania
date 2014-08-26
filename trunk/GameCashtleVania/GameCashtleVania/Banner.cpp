#include "Banner.h"
#include "ManageGame.h"
#include "ManageSprite.h"
#include "ManageTexture.h"
BANNER::BANNER()
{
	//this->_hpSimon = ManageGame::getInstance()->simon->HP;
	//this->_countHeartSimon = ManageGame::getInstance()->simon->count_Heart;
	//this->_numberSimon = ManageGame::getInstance()->simon->numberSimon;
	//this->_typeWeapon = ManageGame::getInstance()->simon->_typeOfWeaponCurr;
	//this->_score = ManageGame::getInstance()->simon->coin;
	////this->_hpEnemy = ManageGame::getInstance()->boss->HP;
	//this->_scene = ManageGame::getInstance()->scene;
	//this->_time = ManageGame::getInstance()->_timeGame;

	

	//setting position
	this->posBGBanner = D3DXVECTOR3(0, 0, 0);	
}



void BANNER::update(float deltaTime)
{
	//if (this->_isActive == true)
	//{
	//	this->_hpSimon = ManageGame::getInstance()->simon->HP;
	//	this->_countHeartSimon = ManageGame::getInstance()->simon->count_Heart;
	//	this->_numberSimon = ManageGame::getInstance()->simon->numberSimon;
	//	this->_typeWeapon = ManageGame::getInstance()->simon->_typeOfWeaponCurr;
	//	this->_score = ManageGame::getInstance()->simon->coin;
	//	//this->_hpEnemy = ManageGame::getInstance()->boss->HP;
	//	this->_scene = ManageGame::getInstance()->scene;
	//	this->_time = ManageGame::getInstance()->_timeGame;
	//}
}

void BANNER::draw()
{ 
	//setting texture
	this->textureBGBanner = ManageTexture::getInstance()->getTetureByKey((int)TYPEBANNER::FullBanner);
	ManageSprite::createInstance()->_Sprite->draw(this->textureBGBanner, NULL, this->posBGBanner);
}

BANNER::~BANNER()
{
}

