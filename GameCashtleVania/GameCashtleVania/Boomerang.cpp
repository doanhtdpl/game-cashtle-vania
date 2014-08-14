#include "Boomerang.h"
#include "Simon.h"

Boomerang::Boomerang()
{
	this->_SPACE_MAX = 200; 
	this->_totalSpace = 0;
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::Boomerang);
}

Boomerang::Boomerang(std::vector<std::string> arr) :Weapon(arr)
{
	this->_SPACE_MAX = 200; 
	this->_totalSpace = 0;
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::Boomerang);
}

void Boomerang::move(float delta_Time)
{
	if(this->_totalSpace >= this->_SPACE_MAX)
	{
		if(this->_Left)
		{
			this->_vx = this->_Vx_default;
		}
		else
		{
			this->_vx = -this->_Vx_default;
		}
		this->_pos.x += this->_vx * delta_Time;
		return;
	}
	else
	{
		if(this->_Left)
		{
			this->_vx = -this->_Vx_default;
			this->_totalSpace -= this->_vx * delta_Time;
		}
		else
		{
			this->_vx = this->_Vx_default;
			this->_totalSpace += this->_vx * delta_Time;
		}
		this->_pos.x += this->_vx * delta_Time;

	}
}



void Boomerang::handleCollisionWithGround(HideObject* hideObj)
{
	//this->_isALive = false;
}