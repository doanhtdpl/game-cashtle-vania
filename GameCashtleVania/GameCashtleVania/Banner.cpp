#include "Banner.h"
#include "ManageGame.h"
#include "ManageSprite.h"
#include "ManageTexture.h"
#include "Item.h"
#include "Weapon.h"
BANNER::BANNER()
{
	this->_time = 0;

	//font
	this->_pFont = new Font();

	//setting position
	this->posBGBanner = D3DXVECTOR3(0, 30, 0);	
	this->posCountHeart = D3DXVECTOR3(460, 68, 0);	 
	this->posCurrentWeapon = D3DXVECTOR3(295, 65, 0);
	this->posHpEnemy = D3DXVECTOR3(110, 85, 0);
	this->posHpSimon = D3DXVECTOR3(110, 62, 0);	
	this->posNumberSimon = D3DXVECTOR3(458, 95, 0);
	this->posScene = D3DXVECTOR3(462, 40, 0);
	this->posScore = D3DXVECTOR3(120, 40, 0);
	this->posTime = D3DXVECTOR3(300, 40, 0);
}

void BANNER::init()
{
	//setting texture
	this->textureBGBanner = ManageTexture::getInstance()->getTetureByKey((int)TYPEBANNER::FullBanner);
	this->textureHpPlayer = ManageTexture::getInstance()->getTetureByKey((int)TYPEBANNER::HeathPlayer);
	this->textureHpEnemy = ManageTexture::getInstance()->getTetureByKey((int)TYPEBANNER::HeathEnemy);
	this->_pFont->image_font = ManageTexture::getInstance()->getTetureByKey((int)3003);

	this->_hpSimon = Simon::getInstance()->HP;
	this->_countHeartSimon = Simon::getInstance()->count_Heart;
	this->_numberSimon = ManageGame::getInstance()->countLifeSimon;
	//this->_typeWeapon = Simon::getInstance()->weaponCurr->_ID_Image;
	this->_score = Simon::getInstance()->coin;
	//this->_hpEnemy = ManageGame::getInstance()->boss->HP;
	this->_hpEnemy = ManageGame::HP_BOSS;
	this->_scene = ManageGame::_infoScene->iD_Scene;
	
}

void BANNER::update(float deltaTime)
{			
	this->_hpSimon = Simon::getInstance()->HP;
	this->_hpEnemy = ManageGame::HP_BOSS;
	this->_countHeartSimon = Simon::getInstance()->count_Heart;
	this->_numberSimon = ManageGame::getInstance()->countLifeSimon;
	this->_typeWeapon = Simon::getInstance()->_typeOfWeaponCurr;
	switch (this->_typeWeapon)
	{
	case TypeWeapon::Axe:
		this->textureWeapon = ManageTexture::getInstance()->getTetureByKey((int)TypeItem::Axe + 711);
		break;
	case TypeWeapon::Boomerang:
		this->textureWeapon = ManageTexture::getInstance()->getTetureByKey((int)TypeItem::Boomerang + 711);
		break;
	case TypeWeapon::Dagger:
		this->textureWeapon = ManageTexture::getInstance()->getTetureByKey((int)TypeItem::Dagger + 711);
		break;
	case TypeWeapon::FireBomb:
		this->textureWeapon = ManageTexture::getInstance()->getTetureByKey((int)TypeItem::FireBomb + 711);
		break;
	case TypeWeapon::Watch:
		this->textureWeapon = ManageTexture::getInstance()->getTetureByKey((int)TypeItem::Watch + 711);
		break;
	case TypeWeapon::None:
		this->textureWeapon = NULL;
		break;
	}

	this->_score = Simon::getInstance()->coin;
	//this->_hpEnemy = ManageGame::getInstance()->boss->HP;
	this->_scene = ManageGame::getInstance()->_infoScene->iD_Scene;
	this->_time += deltaTime;
}

void BANNER::draw()
{ 
		ManageSprite::createInstance()->_Sprite->draw(this->textureBGBanner, NULL, this->posBGBanner);
		if (this->textureWeapon != NULL)
		{
			ManageSprite::createInstance()->_Sprite->draw(this->textureWeapon, NULL, this->posCurrentWeapon);
		}	

		D3DXVECTOR3 positionHpSimon = this->posHpSimon;
		for (int i = 0; i < this->_hpSimon; i++)
		{			
			ManageSprite::createInstance()->_Sprite->draw(this->textureHpPlayer, NULL, positionHpSimon);
			positionHpSimon.x += 8;
		}
		
		D3DXVECTOR3 positionHpEnemy = this->posHpEnemy;
		for (int i = 0; i < this->_hpEnemy; i++)
		{
			ManageSprite::createInstance()->_Sprite->draw(this->textureHpEnemy, NULL, positionHpEnemy);
			positionHpEnemy.x += 8;
		}
		
		this->_pFont->drawFont(this->_countHeartSimon, this->posCountHeart.x,this->posCountHeart.y );
		this->_pFont->drawFont(this->_scene, this->posScene.x, this->posScene.y);
		this->_pFont->drawFont(this->_numberSimon, this->posNumberSimon.x, this->posNumberSimon.y);
		this->_pFont->drawFont(this->_score, this->posScore.x, this->posScore.y);
		this->_pFont->drawFont((int)this->_time, this->posTime.x, this->posTime.y);
}

BANNER::~BANNER()
{
}