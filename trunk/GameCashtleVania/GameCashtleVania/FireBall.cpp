#include "FireBall.h"

FireBall::FireBall()
{

}

FireBall::FireBall(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Moves;
}

void FireBall::appear(D3DXVECTOR2 pos, bool dir)
{
	this->_pos = pos;
	this->_Left = dir;
}

void FireBall::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	this->updateMovement(delta_Time);
	this->move(delta_Time);
}