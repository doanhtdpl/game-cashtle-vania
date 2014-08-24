#include "FishMan.h"

FishMan::FishMan()
{

}

FishMan::FishMan(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Jump;
	this->_vy = this->_Vy_default;
	this->_vx = 0;
}

void FishMan::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}