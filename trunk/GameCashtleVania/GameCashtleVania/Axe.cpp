#include "Axe.h"
#include "Simon.h"

Axe::Axe()
{
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::Axe);
}

Axe::Axe(std::vector<std::string> arr) :Weapon(arr)
{
	this->_JumH_Max = 140;
	this->_ay = 1000.0f;
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::Axe);
}

void Axe::move(float delta_Time)
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


void Axe::handleCollisionWithGround(HideObject* hideObj)
{
	//this->_isALive = false;
}