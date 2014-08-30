#include "FireBall.h"

FireBall::FireBall()
{

}

FireBall::FireBall(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Moves;
	this->lifeTime = 6.0;
}

void FireBall::appear(D3DXVECTOR2 pos, bool dir)
{
	this->_pos = pos;
	this->_Left = dir;
	if (this->_Left)
	{
		this->_vx = -this->_Vx_default;
	}else
	{
		this->_vx = this->_Vx_default;
	}

	this->_vy = 0;
}

void FireBall::appear(D3DXVECTOR2 pos, D3DXVECTOR2 posSimon)
{
	this->_pos = pos;

	if (this->_pos.x < posSimon.x)
	{
		this->_vx = this->_Vx_default;
	}
	else
	{
		if (this->_pos.x > posSimon.x)
		{
			this->_vx = -this->_Vx_default;
		}
		else
		{
			this->_vx = 0;
		}
	}

	if (this->_pos.y < posSimon.y)
	{
		this->_vy = this->_Vy_default;
	}
	else
	{
		if (this->_pos.y > posSimon.y)
		{
			this->_vy = -this->_Vy_default;
		}
		else
		{
			this->_vy = 0;
		}
	}
}

void FireBall::move(float delta_Time)
{
	this->_pos.x += this->_vx * delta_Time;
	this->_pos.y += this->_vy * delta_Time;
}

void FireBall::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
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