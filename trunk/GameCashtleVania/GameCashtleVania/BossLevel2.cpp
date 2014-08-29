#include "BossLevel2.h"
#include "ManageGame.h"
#include "Bullet.h"
#include "EnemyFactory.h"
BossLevel2::BossLevel2()
{	
}

BossLevel2::~BossLevel2()
{
}

void BossLevel2::move(float delta_Time)
{
	if (this->timeDelayChangMovement > 2)
	{
		Boss::move(delta_Time);
	}
	else
	{
		this->timeDelayChangMovement += delta_Time;
	}
}

void BossLevel2::animated(float deltaTime)
{
	switch (this->_moveMent)
	{
	case EnemyMovement::Idle:
		this->_curFrame = 5;
		break;
	case EnemyMovement::Moves:
		_beforeTimeOld += deltaTime;

		if (_beforeTimeOld > _elapseTimeSwitchFrame)
		{
			this->_curFrame++;
			if (this->_curFrame >= 4)
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


void BossLevel2::fire()
{
	Bullet* fireBall = (Bullet*)EnemyFactory::getInstance()->createObj((int)TypeEnemy::Bullet);
	fireBall->appear(this->_pos, Simon::getInstance()->_pos);
	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBall);
}
BossLevel2::BossLevel2(std::vector<std::string> arr) : Boss(arr)
{
	this->arrPos[0] = D3DXVECTOR3(100,150, 0);
	this->arrPos[1] = D3DXVECTOR3(300, 160, 0);
	this->arrPos[2] = D3DXVECTOR3(200, 140, 0);
	this->arrPos[3] = D3DXVECTOR3(150, 150, 0);
	this->arrPos[4] = D3DXVECTOR3(170, 160, 0);
	this->arrPos[5] = D3DXVECTOR3(255, 170, 0);	
	this->dectPos = 0;
	this->timeChange = 0;
	this->isAtackSimon = false;
	this->_moveMent = EnemyMovement::Idle;
	this->timeDelayChangMovement = 0;
}
