#include "Enemy.h"
#include "TagClassName.h"

Enemy::Enemy()
{

}

Enemy::Enemy(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(3).c_str());
	this->_Vx_default = atoi(arr.at(3).c_str());
	this->_Vy_default = atoi(arr.at(3).c_str());
	this->_coloumn = atoi(arr.at(3).c_str());
	this->_totalFrames = atoi(arr.at(3).c_str());
	this->_elapseTimeSwitchFrame = atoi(arr.at(3).c_str());
}

std::string Enemy::className()
{
	return TagClassName::getInstance()->tagEnemy;
}

void Enemy::move(float delta_Time)
{

}

void Enemy::updateMovement(float delta_Time)
{
	switch (this->_movement)
	{
	case EnemyMovement::None:
		break;
	case EnemyMovement::Idle:
		this->_CanMoveL = true;
		this->_CanMoveR = true;
		this->_High_Jumped = 0;
		this->_CanJum = true;
		this->_vx = 0.0f;
		this->_vy = 0.0f;
		break;
	case EnemyMovement::Moves:
		this->_CanJum = true;
		this->_CanMoveL = true;
		this->_CanMoveR = true;
		this->_High_Jumped = 0;
		this->_vy = 0;

		if (this->_Left)//dang di chuyen qua ben trai
		{
			this->_vx = -this->_Vx_default;
		}else
		{
			this->_vx = this->_Vx_default;
		}
		break;
	case EnemyMovement::Jump:
		if (!this->_Jumping)
		{
			this->_vy = this->_Vy_default;
		}else
		{
			this->_vy -= this->_ay * delta_Time;
			if (this->_vy <= 0)
			{
				this->_movement = EnemyMovement::Free;
			}
		}
		
		this->_High_Jumped += this->_vy * delta_Time;
		this->_CanJum = false;

		//khi dang nhay thi khong the di chuyen. Chi dua vao van toc dau. Van toc dau > 0 thi co Jump and Move
		this->_CanMoveL = false;
		this->_CanMoveR = false;

		//if (this->_vx != 0)
		//{
		//	//co nen giam toc do cua vx ko?
		//	this->_pos.x += delta_Time * this->_vx;
		//}
		
		if (this->_Left)//dang di chuyen qua ben trai
		{
			this->_vx = -this->_Vx_default;
		}else
		{
			this->_vx = this->_Vx_default;
		}

		//da dat toi nguong --> delay. rot xuong
		if (this->_High_Jumped >= this->_JumH_Max)
		{
			this->_vy = 0.0f;
			//this->_timeDelayJumpCur += delta_Time;

			//if (this->_timeDelayJumpCur >= delayJump)
			//{
			//	//het thoi gian delay. Roi xuong thoi!!!
			//	this->_timeDelayJumpCur = 0.0f;
			//	this->_moveMent = SimonMove::Free;
			//}
		}
		break;
	case EnemyMovement::Free:
		this->_vy = -this->_Vy_default * 2;
		this->_High_Jumped = 0;
		this->_CanJum = false;

		//khi dang nhay thi khong the di chuyen. Chi dua vao van toc dau. Van toc dau > 0 thi co Jump and Move
		this->_CanMoveL = false;
		this->_CanMoveR = false;

		if (this->_vx != 0)
		{
			//co nen giam toc do cua vx ko?
			this->_pos.x += delta_Time * this->_vx * 2;
		}
		break;
	default:
		break;
	}
}

void Enemy::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	for (int i = 0; i < _listObjectCollision.size(); i++)
	{
		//xu ly va cham voi doi tuong ground or doi tuong an
	}
}

void Enemy::animated(float deltaTime)
{
	IAnimatedSprite::animated(deltaTime);
}

void Enemy::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	animated(delta_Time);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	updateMovement(delta_Time);
	move(delta_Time);

	handleCollision(delta_Time, _listObjectCollision);
}