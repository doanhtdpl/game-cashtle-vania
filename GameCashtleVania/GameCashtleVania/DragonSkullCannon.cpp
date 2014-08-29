#include "DragonSkullCannon.h"
#include "FireBall.h"
#include "QuadTreeObject.h"
#include "EnemyFactory.h"

DragonSkullCannon::DragonSkullCannon()
{

}

DragonSkullCannon::DragonSkullCannon(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Idle;
	this->eslapseTimeFire = 2.0f;
	this->timeFireCur = 0.0f;
	this->_Left = true;
}

void DragonSkullCannon::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	if (!this->pause)
	{
		if (_timeDelayCur >= 0)
		{
			_timeDelayCur -= delta_Time;
		}
		else
		{
			timeFireCur += delta_Time;
			if (timeFireCur >= eslapseTimeFire)
			{
				fire();
				timeFireCur -= eslapseTimeFire;
			}
		}
	}
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

void DragonSkullCannon::fire()
{
	D3DXVECTOR2 posFire1 = D3DXVECTOR2(this->_pos.x, this->_pos.y + this->_height / 4);
	D3DXVECTOR2 posFire2 = D3DXVECTOR2(this->_pos.x, this->_pos.y - this->_height / 4);

	FireBall* fireBall1 = (FireBall*)EnemyFactory::getInstance()->createObj((int)TypeEnemy::FIRE_BALL);
	fireBall1->appear(posFire1, this->_Left);

	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBall1);

	FireBall* fireBall2 = (FireBall*)EnemyFactory::getInstance()->createObj((int)TypeEnemy::FIRE_BALL);
	fireBall2->appear(posFire2, !this->_Left);

	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBall2);
}