#include "FireBomb.h"
#include "Simon.h"
#include "FireBomb2.h"
#include "QuadTreeObject.h"
#include "WeaponFactory.h"
#include "ManageSprite.h"
#include "ManageAudio.h"
FireBomb::FireBomb()
{
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::FireBomb);
}

FireBomb::FireBomb(std::vector<std::string> arr) :Weapon(arr)
{
	this->_ay = 1000.0f;
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::FireBomb);

	life_Time = atof(arr.at(10).c_str());
	this->_rect = this->getRect();
	this->_isAnimatedSprite = true;
	this->_curFrame = 0;
	this->colGround = false;

}

void FireBomb::move(float delta_Time)
{
	if (!colGround)
	{
		if(this->_Left)
		{
			this->_vx = -this->_Vx_default;
		}
		else
		{
			this->_vx = this->_Vx_default;
		}
		this->_pos.x += this->_vx * delta_Time;

		this->_vy -= this->_ay * delta_Time; 
		this->_pos.y += this->_vy * delta_Time;
	}
	
}

void FireBomb::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	this->handleCollision(delta_Time, _listObjectCollision);
	this->move(delta_Time);
	this->animated(delta_Time);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	if (this->colGround)
	{
		if (life_Time > 0)
		{
			life_Time -= delta_Time;
		}else
		{
			this->_isALive = false;
			this->completeAttack();
		}
	}
	//kiem tra no da ra khoi man hinh chua
	if (!QNode::isBound(this->getRect(), ManageSprite::createInstance()->_camera->getScreen()))
	{
		completeAttack();
	}
}

void FireBomb::handleCollisionWithGround(HideObject* hideObj)
{
	//this->completeAttack();
	//Weapon* fireBomb2 =  WeaponFactory::getInstance()->createObj((int)TypeWeapon::FireBomb2);
	//fireBomb2->_isALive = true;
	//fireBomb2->_pos = this->_pos;
	//fireBomb2->_rect = this->getRect();
	//fireBomb2->_rectRS = fireBomb2->updateRectRS(fireBomb2->_width, fireBomb2->_height);
	//QuadTreeObject::getInstance()->addObjectToQuadTree(fireBomb2);
	if (!this->colGround)
	{

		ManageAudio::getInstance()->playSound(TypeAudio::Holy_Water);
		this->_pos.y = hideObj->getRect().top + this->_height / 2;
		this->colGround = true;
		this->_curFrame = 1;
	}
	
}

void FireBomb::animated(float deltaTime)
{
	if (!colGround)
	{
		this->_curFrame = 0;
	}else
	{
		_beforeTimeOld += deltaTime;

		if (_beforeTimeOld > _elapseTimeSwitchFrame)
		{
			this->_curFrame ++;
			if (this->_curFrame >= this->_totalFrames)
			{
				this->_curFrame = 1;
			}

			_beforeTimeOld -= _elapseTimeSwitchFrame;
		}
	}
}