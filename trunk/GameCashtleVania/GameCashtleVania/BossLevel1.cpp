#include "BossLevel1.h"
#include "ManageGame.h"
BossLevel1::BossLevel1()
{
}

BossLevel1::~BossLevel1()
{
}



BossLevel1::BossLevel1(std::vector<std::string> arr) : Enemy(arr)
{	
	this->_moveMent = EnemyMovement::Moves;	
	this->arrPos[0] = D3DXVECTOR3(1100, 230, 0);
	this->arrPos[1] = D3DXVECTOR3(1250, 240, 0);
	this->arrPos[2] = D3DXVECTOR3(1470, 250, 0);
	this->arrPos[3] = D3DXVECTOR3(1150, 170, 0);
	this->arrPos[4] = D3DXVECTOR3(1300, 190, 0);
	this->arrPos[5] = D3DXVECTOR3(1400, 180, 0);
	this->dectPos = 0;
	this->timeChange = 0;
	this->isAtackSimon = false;
}

void BossLevel1::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{

}

void BossLevel1::move(float delta_Time)
{
	this->timeChange += delta_Time;

	if (this->timeChange > MAX_TIME_CHANGE_POSITION_RANDOM && this->isAtackSimon == true)
	{
		this->timeChange = 0;		
	    this->dectPos = rand() % 6;		
		this->isAtackSimon = !this->isAtackSimon;
	}	
	else if(this->timeChange > MAX_TIME_CHANGE_POSITION_SIMON && this->isAtackSimon == false)
	{
		this->timeChange = 0;
		this->posSimon = Simon::getInstance()->_pos;
		this->isAtackSimon = !this->isAtackSimon;
	}


	if (this->isAtackSimon == true)
	{
		if (abs(this->_pos.x - this->posSimon.x) < 10 && abs( this->_pos.y - this->posSimon.y) < 10)
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

void BossLevel1::animated(float deltaTime)
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