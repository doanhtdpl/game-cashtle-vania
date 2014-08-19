#include "Dagger.h"
#include "Simon.h"

Dagger::Dagger()
{
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::Dagger);
}

Dagger::Dagger(std::vector<std::string> arr) :Weapon(arr)
{
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
	this->setTypeOfWeapon(TypeWeapon::Dagger);
}

void Dagger::move(float delta_Time)
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

}

void Dagger::Use(D3DXVECTOR2 posSimon, bool Left)
{
	this->_isALive = true;
	this->_pos = posSimon;
	this->_Left = !Left;
}

void Dagger::handleCollisionWithGround(HideObject* hideObj)
{
	//this->_isALive = false;
}