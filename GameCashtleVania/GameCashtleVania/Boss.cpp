#include "Boss.h"
#include "ManageGame.h"
#include "EnemyFactory.h"
#include "Bullet.h"
#include "FireBall.h"

Boss ::Boss ()
{

}

Boss ::~Boss ()
{
}
void Boss::setMovement(EnemyMovement movement)
{
	this->_moveMent = movement;
}
Boss ::Boss (std::vector<std::string> arr) : Enemy(arr)
{
	this->_moveMent = EnemyMovement::Idle;	
	this->dectPos = 0;
	this->timeChange = 0;
	this->isAtackSimon = false;

	this->timeFireCur = 0.0f;
	this->eslapseTimeFire = 5.0f;
	this->timeDelayAttack = 2.0f;
	this->timeDelayCur = 0.0f;
	this->attacking = true;
	this->countFire = 0;

}

void Boss ::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{

}

void Boss::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	Enemy::update(delta_Time, _listObjectCollision);
	if (this->_moveMent != EnemyMovement::Idle)
	{
		timeFireCur += delta_Time;
		if (timeFireCur >= eslapseTimeFire)
		{
			this->fire();
			this->attacking = true;
			this->countFire++;
			this->timeFireCur -= this->eslapseTimeFire;
			if (this->countFire >= 2)
			{
				this->countFire = 0;
			}
		}
	}
}

void Boss::fire()
{
	FireBall* fireBall = (FireBall*)EnemyFactory::getInstance()->createObj((int)TypeEnemy::FIRE_BALL);
	fireBall->appear(this->_pos,Simon::getInstance()->_pos);
	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBall);
}

void Boss ::move(float delta_Time)
{
	if (this->_moveMent != EnemyMovement::Idle)
	{
		this->timeChange += delta_Time;

		if (this->timeChange > MAX_TIME_CHANGE_POSITION_RANDOM && this->isAtackSimon == true)
		{
			this->timeChange = 0;
			this->dectPos = rand() % 6;
			this->isAtackSimon = !this->isAtackSimon;
		}
		else if (this->timeChange > MAX_TIME_CHANGE_POSITION_SIMON && this->isAtackSimon == false)
		{
			this->timeChange = 0;
			this->posSimon = Simon::getInstance()->_pos;
			this->isAtackSimon = !this->isAtackSimon;
		}


		if (this->isAtackSimon == true)
		{
			if (abs(this->_pos.x - this->posSimon.x) < 10 && abs(this->_pos.y - this->posSimon.y) < 10)
			{
				this->_vx = 0;
				this->_vy = 0;
				return;
			}
			else
			{
				if (this->_pos.x < this->posSimon.x) // di chuyen boss theo x
				{
					this->_vx = this->_Vx_default;
				}
				else if (this->_pos.x > this->posSimon.x)
				{
					this->_vx = -this->_Vx_default;
				}
				else
				{
					this->_vx = 0;
				}


				// di chuyen boss theo y
				if (this->_pos.y < this->posSimon.y)
				{
					this->_vy = this->_Vy_default;
				}
				else if (this->_pos.y > this->posSimon.y)
				{
					this->_vy = -this->_Vy_default;
				}
				else
				{
					this->_vy = 0;
				}
			}

		}

		else // di chuyen vi tri co dinh
		{
			if (abs(this->_pos.x - this->arrPos[this->dectPos].x) <10 && abs(this->_pos.y - this->arrPos[this->dectPos].y) <10)
			{
				this->_vx = 0;
				this->_vy = 0;
				return;
			}
			else
			{

				if (this->_pos.x < this->arrPos[this->dectPos].x)
				{
					this->_vx = this->_Vx_default;
				}
				else if (this->_pos.x > this->arrPos[this->dectPos].x)
				{
					this->_vx = -this->_Vx_default;
				}
				else
				{
					this->_vx = 0;					
				}

				if (this->_pos.y < this->arrPos[this->dectPos].y)
				{
					this->_vy = this->_Vy_default;
				}
				else if (this->_pos.y > this->arrPos[this->dectPos].y)
				{
					this->_vy = -this->_Vy_default;
				}
				else
				{
					this->_vy = 0;
				}
			}
		}

		this->_pos.x += this->_vx * delta_Time;
		this->_pos.y += this->_vy * delta_Time;

	}
	

}


void Boss ::animated(float deltaTime)
{
	switch (this->_moveMent)
	{
	case EnemyMovement::Idle:
		this->_curFrame = 0;
		break;
	case EnemyMovement::Moves:
		_beforeTimeOld += deltaTime;

		if (_beforeTimeOld > _elapseTimeSwitchFrame)
		{
			this->_curFrame++;
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