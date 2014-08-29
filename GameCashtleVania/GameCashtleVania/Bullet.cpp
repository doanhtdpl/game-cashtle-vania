#include "Bullet.h"

Bullet::Bullet(std::vector<std::string> arr) :Enemy(arr)
{
	this->_moveMent = EnemyMovement::Moves;
	this->lifeTime = 3.0;
	this->_Vx_default = 70;
	this->_Vy_default = 70;
}

Bullet::~Bullet()
{
}

void Bullet::appear(D3DXVECTOR2 pos,  D3DXVECTOR2 des)
{
	this->_pos = pos;
	this->_des = des;
}

void Bullet::updateMovement(float deltaTime)
{
}

void Bullet::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	if (!this->pause)
	{
		//this->updateMovement(delta_Time);
		this->move(delta_Time);
		lifeTime -= delta_Time;
		if (lifeTime <= 0)
		{
			this->_isALive = false;
		}
	}
}

void Bullet::move(float delta_Time)
{
	if (this->_pos.x < this->_des.x)
	{
		this->_vx = this->_Vx_default;
	}
	else if (this->_pos.x > this->_des.x)
	{
		this->_vx = -this->_Vx_default;
	}
	else
	{
		this->_vx = 0;
	}

	if (this->_pos.y < this->_des.y)
	{
		this->_vy = this->_Vy_default;
	}
	else if (this->_pos.y > this->_des.y)
	{
		this->_vy = -this->_Vy_default;
	}
	else
	{
		this->_vy = 0;
	}

	this->_pos.x += this->_vx*delta_Time;
	this->_pos.y += this->_vy*delta_Time;
}