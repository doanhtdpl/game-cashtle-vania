#include "BlackKnight.h"

BlackKnight::BlackKnight()
{

}

BlackKnight::BlackKnight(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Moves;
}

void BlackKnight::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
	if (this->_Left)
	{
		this->_pos.x += 3;
	}else
	{
		this->_pos.x -= 3;
	}
	this->_Left = !this->_Left;
}