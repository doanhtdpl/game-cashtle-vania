#include "FireBomb.h"
#include "Simon.h"
#include "FireBomb2.h"
#include "QuadTreeObject.h"
#include "WeaponFactory.h"

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
}

void FireBomb::move(float delta_Time)
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


void FireBomb::handleCollisionWithGround(HideObject* hideObj)
{
	this->completeAttack();
	Weapon* fireBomb2 =  WeaponFactory::getInstance()->createObj((int)TypeWeapon::FireBomb2);
	fireBomb2->_isALive = true;
	fireBomb2->_pos = this->_pos;
	fireBomb2->_rect = this->getRect();
	fireBomb2->_rectRS = fireBomb2->updateRectRS(fireBomb2->_width, fireBomb2->_height);
	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBomb2);
}