#include "FishMan.h"
#include "QuadTreeObject.h"
#include "EnemyFactory.h"
#include "FireBall.h"

FishMan::FishMan()
{

}

FishMan::FishMan(std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Jump;
	this->_vy = this->_Vy_default;
	this->_vx = 0;

	this->timeFireCur = 0.0f;
	this->eslapseTimeFire = 1.0f;
	this->timeDelayAttack = 2.0f;
	this->timeDelayCur = 0.0f;
	this->attacking = true;
	this->countFire = 0;
}

void FishMan::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
	this->_moveMent = EnemyMovement::Free;
}

void FishMan::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	Enemy::update(delta_Time, _listObjectCollision);
	timeFireCur += delta_Time;
	if (timeFireCur >= eslapseTimeFire)
	{
		fire();
		this->attacking = true;
		this->countFire ++;
		timeFireCur -= eslapseTimeFire;
		if (this->countFire >= 2)
		{
			this->countFire = 0;
			this->_Left = !this->_Left;
		}
	}
}

void FishMan::fire()
{
	FireBall* fireBall = (FireBall*)EnemyFactory::getInstance()->createObj((int)TypeEnemy::FIRE_BALL);
	fireBall->appear(D3DXVECTOR2(this->_pos.x, this->_pos.y + this->_height / 2), this->_Left);
	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBall);
}

void FishMan::animated(float deltaTime)
{
	switch (this->_moveMent)
	{
	case EnemyMovement::Free:
		this->_curFrame = 2;
		break;
	case EnemyMovement::Jump:
		this->_curFrame = 2;
		break;
	case EnemyMovement::Moves:
		_beforeTimeOld += deltaTime;

		if (_beforeTimeOld > _elapseTimeSwitchFrame)
		{
			if (this->attacking)
			{
				this->_curFrame = 0;
				this->timeDelayCur += deltaTime;
				if (timeDelayCur > timeDelayAttack)
				{
					this->attacking = false;
					timeDelayCur -= timeDelayAttack;
				}
				
			}else
			{
				this->_curFrame ++;
				if (this->_curFrame >= this->_totalFrames)
				{
					this->_curFrame = 1;
				}

				_beforeTimeOld -= _elapseTimeSwitchFrame;
			}
			
		}
		break;
	case EnemyMovement::Idle:
		this->_curFrame = 2;
		break;
	default:
		break;
	}
}