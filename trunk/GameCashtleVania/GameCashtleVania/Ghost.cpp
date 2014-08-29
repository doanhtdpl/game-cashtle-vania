#include "Ghost.h"
#include "Simon.h"

Ghost::Ghost()
{

}

Ghost::Ghost(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Moves;
}

void Ghost::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}

void Ghost::move(float delta_Time)
{
	posTarget = Simon::getInstance()->_pos;
	int disX = posTarget.x - this->_pos.x;
	if (disX < 0)
	{
		this->_Left = true;
		this->_vx = - this->_Vx_default;
	}else
	{
		this->_Left = false;
		this->_vx = this->_Vx_default;
	}

	int disY = posTarget.y - this->_pos.y;
	if (disY > 0)
	{
		this->_vy = this->_Vy_default;
	}else
	{
		this->_vy = -this->_Vy_default;
	}

	this->_pos.x += this->_vx * delta_Time;
	this->_pos.y += this->_vy * delta_Time;
}