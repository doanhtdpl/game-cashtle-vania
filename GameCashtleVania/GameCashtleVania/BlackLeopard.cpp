#include "BlackLeopard.h"

BlackLeopard::BlackLeopard()
{

}

BlackLeopard::BlackLeopard(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Moves;
}

void BlackLeopard::animated(float deltaTime)
{
	switch (this->_moveMent)
	{
	case EnemyMovement::Idle:
		this->_curFrame = 0;
		break;
	case EnemyMovement::Free:
		this->_curFrame = 3;
		break;
	case EnemyMovement::Jump:
		this->_curFrame = 3;
		break;
	case EnemyMovement::Moves:
		_beforeTimeOld += deltaTime;

		if (_beforeTimeOld > _elapseTimeSwitchFrame)
		{
			this->_curFrame ++;
			if (this->_curFrame >= 3)
			{
				this->_curFrame = 1;
			}

			_beforeTimeOld -= _elapseTimeSwitchFrame;
		}
		break;
	default:
		break;
	}
}

void BlackLeopard::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
	if (this->_moveMent == EnemyMovement::Moves)
	{
		//vi tri tuong doi khong cach nhau qua 5 pixel
		if ( abs(this->_pos.x - hideObj->_pos.x) < 5 && abs(this->getRect().bottom - hideObj->getRect().bottom) < 5)
		{
			this->_moveMent = EnemyMovement::Jump;
			this->_vy = this->_Vy_default;
		}
		
	}
	
}