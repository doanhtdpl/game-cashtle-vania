#include "Weapon.h"
#include "TagClassName.h"
#include "Simon.h"
#include "ManageSprite.h"
#include "QNode.h"
#include "Light.h"
#include "QuadTreeObject.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_coloumn = atoi(arr.at(7).c_str());
	this->_totalFrames = atoi(arr.at(8).c_str());
	this->_elapseTimeSwitchFrame = atof(arr.at(9).c_str());
	this->_isAnimatedSprite = true;

	this->_isALive = false;
	this->_rect = this->getRect();

	this->_beforeTimeOld = 0.0f;
	_can_Use_Weapon = true;
}

std::string Weapon::className()
{
	return TagClassName::getInstance()->tagWeapon;
}

void Weapon::Use(D3DXVECTOR2 posSimon, bool Left)
{
	this->_isALive = true;
	this->_pos = posSimon;
	this->_Left = Left;

}

void Weapon::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	this->handleCollision(delta_Time, _listObjectCollision);
	this->move(delta_Time);
	this->animated(delta_Time);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	//kiem tra no da ra khoi man hinh chua
	if (!QNode::isBound(this->getRect(), ManageSprite::createInstance()->_camera->getScreen()))
	{
		completeAttack();
	}
}

void Weapon::move(float delta_Time)
{

}


bool Weapon::completeAttack()
{
	this->_isALive = false;
	this->_can_Use_Weapon = true;
	return true;
}

void Weapon::handleCollision(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	std::vector<ObjectGame*>::iterator it = _listObjectCollision.begin();
	ObjectGame* obj = NULL;
	HideObject* hideObj = NULL;
	float normalX = 0;
	float normalY = 0;
	float timeCollision;
	while(it != _listObjectCollision.end())
	{
		obj = *it;
		this->_box = this->getBox();
		if(obj->className() == TagClassName::getInstance()->tagEnemy)
		{
			Enemy* enemy = (Enemy*)obj;
			timeCollision = this->collision((DynamicObject*)obj, normalX, normalY, delta_Time);
			if((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				handleCollisionWithEnemy(enemy);
			}
		}
		else if(obj->className() == TagClassName::getInstance()->tagHideObject)
		{
			hideObj = (HideObject*)obj;
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, delta_Time);
			if((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				if(hideObj->getTypeHideObject() == TypeHideObect::Ground)
				{
					this->handleCollisionWithGround(hideObj);
				}
			}

		}

		if (obj->className() == TagClassName::getInstance()->tagLight)
		{
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, delta_Time);

			if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				//tao ra hieu ung.

				//goi ham effect cua light
				Light* light = (Light*)obj;
				light->_isALive = false;
				Item* item = light->effectWhenCollisionRod();
				QuadTreeObject::getInstance()->addObjectToQuadTree(item);
			}
		}
		++it;
	}
}

void Weapon::handleCollisionWithGround(HideObject* hideObj)
{

}

void Weapon::handleCollisionWithEnemy(Enemy* enemy)
{

}

void Weapon::setTypeOfWeapon(TypeWeapon typeOfWeapon)
{
	this->_typeOfWeapon = typeOfWeapon;
}

TypeWeapon Weapon::getTypeOfWeapon()
{
	return this->_typeOfWeapon;
}
