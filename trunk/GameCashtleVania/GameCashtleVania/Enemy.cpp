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

	this->TimeDelay = 0.2f;
	this->_timeDelayCur = 0.0f;
	this->_hp = 1;
}

std::string Enemy::className()
{
	return TagClassName::getInstance()->tagEnemy;
}

void Enemy::move(float delta_Time)
{
	if ((this->_CanMoveL && this->_vx < 0) || (this->_CanMoveR && this->_vx > 0))
	{
		//co the di qua ben trai va v
		this->_pos.x += this->_vx * delta_Time;
	}

	this->_pos.y += this->_vy * delta_Time;
}

void Enemy::updateMovement(float delta_Time)
{
	switch (this->_moveMent)
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
				this->_moveMent = EnemyMovement::Free;
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
			//	this->_moveMent = SimonMove::Freee;
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
	//chi va cham voi doi tuong Free
	for (int i = 0; i < _listObjectCollision.size(); i++)
	{
		//lay box collider khi bat dau xu ly va cham
		this->_box = this->getBox();
		float normalX = 0;
		float normalY = 0;
		float timeCollision;

		ObjectGame* obj = _listObjectCollision.at(i);
		if (obj->className() == TagClassName::getInstance()->tagHideObject)
		{
			HideObject* hideObj = (HideObject*)obj;
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, deltatime);

#pragma region HideObject = Ground
			if (hideObj->getTypeHideObject() == TypeHideObect::Ground)
			{
				if (timeCollision == 2.0f)
				{
					// bi va cham theo AABBCheck
					if (this->_moveMent == EnemyMovement::Free && normalY >= 0)
					{
						//dang roi
						if (this->getRect().bottom > hideObj->getRect().bottom)
						{
							this->_moveMent = EnemyMovement::Idle;
							this->_pos.x += normalX;
							this->_pos.y += normalY;
							//this->_vx = 0;
							this->_vy = 0;
						}

					}

					if (this->_moveMent == EnemyMovement::Moves && normalX != 0)
					{
						this->_moveMent = EnemyMovement::Idle;
						this->_pos.x += normalX;
						this->_pos.y += normalY;
						this->_vx = 0;
					}
				}else
				{
					//truong hop duoi
				}
				if (timeCollision < 1.0f)//co va cham
				{
					//Object dang di chuyen qua ben trai
					if (normalX == 1)
					{


						if (this->_moveMent == EnemyMovement::Jump)
						{
							this->_moveMent == EnemyMovement::Free;
						}

						if (this->_moveMent == EnemyMovement::Moves)
						{
							this->_pos.x += timeCollision * (deltatime * this->_vx) + 0.5f;
							this->_moveMent = EnemyMovement::Idle;
							this->_vx = 0;
							this->_CanMoveL = false;
						}

					}

					//Object dang di chuyen qua ben phai
					if (normalX == -1)
					{

						if (this->_moveMent == EnemyMovement::Jump)
						{
							this->_moveMent == EnemyMovement::Free;
						}

						if (this->_moveMent == EnemyMovement::Moves)
						{
							this->_pos.x += timeCollision * (deltatime * this->_vx) - 0.5f;
							this->_moveMent = EnemyMovement::Idle;
							this->_vx = 0;
							this->_CanMoveR = false;
						}
					}

					//Obj dang roi
					if (normalY == 1)
					{
						if (this->_moveMent == EnemyMovement::Free)
						{
							this->_pos.y += timeCollision * (deltatime * this->_vy);
							this->_moveMent = EnemyMovement::Idle;
							//this->_vx = 0;
							this->_vy = 0;
						}

					}

					//obj dang nhay
					if (normalY == -1)
					{
						//ko lam gi ca
					}
				}
			}
#pragma endregion

			//gap doi tuong an Free thi quay dau lai
			if (hideObj->getTypeHideObject() == TypeHideObect::Free)
			{
				//co va cham
				if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
				{
					//xu ly voi doi tuong hide object = Free
					handleCollisionWithHideObject(deltatime, hideObj);
				}
			}
		}

		if (obj->className() == TagClassName::getInstance()->tagWeapon)
		{
			timeCollision = this->collision((DynamicObject*)obj, normalX, normalY, deltatime);
			//co va cham
			if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				_hp --;
				if (_hp <= 0)
				{
					//die
					this->_isALive = false;
				}

				_timeDelayCur = TimeDelay;
			}
		}
	}
}

void Enemy::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{

}

void Enemy::animated(float deltaTime)
{
	IAnimatedSprite::animated(deltaTime);
}

void Enemy::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	if (_timeDelayCur >= 0)
	{
		_timeDelayCur -= delta_Time;
	}else
	{
		animated(delta_Time);
		this->_rectRS = this->updateRectRS(this->_width, this->_height);

		updateMovement(delta_Time);

		handleCollision(delta_Time, _listObjectCollision);

		move(delta_Time);
	}
}