#include "Light.h"
#include "TagClassName.h"
#include "ItemManager.h"

Light::Light()
{

}

Light::Light(std::vector<std::string> arr) : StaticObject(arr)
{
	this->_ID		= atoi(arr[0].c_str());
	this->_ID_Image = atoi(arr[1].c_str());
	this->_width	= atoi(arr[3].c_str());
	this->_height	= atoi(arr[4].c_str());

	//IAniamted Sprite
	this->_coloumn = atoi(arr[5].c_str());
	this->_totalFrames = atoi(arr[6].c_str());
	this->_elapseTimeSwitchFrame = atof(arr[7].c_str());
	this->_curFrame = 0;
	this->_beforeTimeOld = 0.0f;

	this->_isALive = true;
	this->_isAnimatedSprite = true;

	this->_typeLight = (TypeLight)this->_ID;
}

std::string Light::className()
{
	return TagClassName::getInstance()->tagLight;
}

void Light::update(float deltaTime)
{
	animated(deltaTime);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

Item* Light::effectWhenCollisionRod()
{
	Item* item = NULL;
	switch (this->_typeLight)
	{
	case TypeLight::BigLightDagger:
		item = ItemManager::getInstance()->appearItem(Dagger, this->_pos);
		break;
	case TypeLight::BigLightHeart:
		item = ItemManager::getInstance()->appearItem(TypeItem::LargeHeart, this->_pos);
		break;
	case TypeLight::BigLightRod:
		item = ItemManager::getInstance()->appearItem(TypeItem::MorningStar, this->_pos);
		break;
	case TypeLight::SmallLightAxe:
		item = ItemManager::getInstance()->appearItem(TypeItem::Axe, this->_pos);
		break;
	case TypeLight::SmallLightBoomerang:
		item = ItemManager::getInstance()->appearItem(TypeItem::Boomerang, this->_pos);
		break;
	case TypeLight::SmallLightCross:
		item = ItemManager::getInstance()->appearItem(TypeItem::Cross, this->_pos);
		break;
	case TypeLight::SmallLightFireBomb:
		item = ItemManager::getInstance()->appearItem(TypeItem::FireBomb, this->_pos);
		break;
	case TypeLight::SmallLightRandom:
		item = ItemManager::getInstance()->appearItem(this->_pos);
		break;
	default:
		break;
	};

	return item;
}