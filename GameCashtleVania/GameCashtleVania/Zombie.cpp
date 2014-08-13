#include "Zombie.h"

Zombie::Zombie()
{

}

Zombie::Zombie(std::vector<std::string> arr) : Enemy(arr)
{

}

void Zombie::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
	if (this->_moveMent == EnemyMovement::Moves || this->_moveMent == EnemyMovement::Idle)
	{
		if (this->_Left)
		{
			//dang di qua ben trai
			if (this->getRect().right <= hideObj->getRect().right)
			{
				this->_moveMent = EnemyMovement::Free;
			}
		}
		else
		{
			//dang di qua ben phai
			if (this->getRect().left >= this->getRect().left)
			{
				this->_moveMent = EnemyMovement::Free;
			}
		}
	}
}