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
}

void FireBall::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	if (!this->pause)
	{
		this->updateMovement(delta_Time);
		this->move(delta_Time);

		lifeTime -= delta_Time;
		if (lifeTime <= 0)
		{
			this->_isALive = false;
		}
	}
	
}