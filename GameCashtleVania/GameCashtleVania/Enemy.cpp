#include "Enemy.h"
#include "TagClassName.h"
#include "QuadTreeObject.h"
#include "ItemManager.h"
#include "ManageAudio.h"
#include "Simon.h"
Enemy::Enemy()
{

}

Enemy::Enemy(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_coloumn = atoi(arr.at(7).c_str());
	this->_totalFrames = atoi(arr.at(8).c_str());
	this->_elapseTimeSwitchFrame = atof(arr.at(9).c_str());
	this->_ay = atof(arr.at(10).c_str());
	this->_hp = atoi(arr.at(11).c_str());
	this->_beforeTimeOld = 0.0f;
	this->_Left = true;
	this->_CanMoveL = true;
	this->_CanMoveR = true;

	this->TimeDelay = 0.2f;
	this->_timeDelayCur = 0.0f;

	this->_isALive = true;
	this->_isAnimatedSprite = true;
	this->_rect = this->getRect();
	this->_typeEnemy = TypeEnemy(this->_ID);

	this->_canFree = false;
	//QuadTreeObject::eraseObject()
	this->pause = false;
}

std::string Enemy::className()
{
	return TagClassName::getInstance()->tagEnemy;
}

void Enemy::move(float delta_Time)
{
	//int dir = this->_Left? -1 : 1;
	//this->_vx = dir * this->_Vx_default;
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
		this->_vy -= this->_ay * delta_Time;
		if (this->_vy <= 0)
		{
			this->_moveMent = EnemyMovement::Free;
		}
		
		//if (this->_Left)//dang di chuyen qua ben trai
		//{
		//	this->_vx = -this->_Vx_default;
		//}else
		//{
		//	this->_vx = this->_Vx_default;
		//}
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
			if (hideObj->getTypeHideObject() == TypeHideObect::Ground && 
				this->_typeEnemy != TypeEnemy::MEDUSA && 
					this->_typeEnemy != TypeEnemy::VAMPIRE_BAT && !this->_canFree)
			{
				if (timeCollision == 2.0f)
				{
					// bi va cham theo AABBCheck
					if (this->_moveMent == EnemyMovement::Free && normalY > 0)
					{
						//dang roi
						if (this->getRect().bottom > hideObj->getRect().bottom)
						{
							this->_moveMent = EnemyMovement::Moves;
							this->_pos.x += normalX;
							this->_pos.y += normalY;
							//this->_vx = 0;
							this->_vy = 0;
						}

					}

					if (this->_moveMent == EnemyMovement::Moves && normalX != 0)
					{
						this->_moveMent = EnemyMovement::Moves;
						this->_pos.x += normalX;
						this->_pos.y += normalY;
						this->_Left = !this->_Left;
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
							this->_vx = 0;
							this->_Left = false;
						}

					}

					//Object dang di chuyen qua ben phai
					if (normalX == -1)
					{
						/*if (this->_moveMent == EnemyMovement::Jump)
						{
							this->_moveMent == EnemyMovement::Free;
						}*/

						if (this->_moveMent == EnemyMovement::Moves)
						{
							this->_pos.x += timeCollision * (deltatime * this->_vx) - 0.5f;
							this->_vx = 0;
							this->_Left = true;
						}
					}

					//Obj dang roi
					if (normalY == 1)
					{
						if (this->_moveMent == EnemyMovement::Free)
						{
							this->_pos.y += timeCollision * (deltatime * this->_vy);
							this->_moveMent = EnemyMovement::Moves;
							//this->_vx = 0;
							this->_vy = 0;
							if (this->_typeEnemy == TypeEnemy::BLACK_LEOPARD)
							{
								//doi nguoi huong khi roi xuong cua con cho.
								this->_Left = !this->_Left;
							}
						}

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
					if (abs(this->getRect().bottom - hideObj->getRect().bottom) < 5)
					{
						handleCollisionWithFreeObject(deltatime, hideObj);
					}
				}
			}
		}

#pragma region Collision With Weapon

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

#pragma endregion

	}
}

void Enemy::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	if (this->_moveMent == EnemyMovement::Moves)
	{
		//vi tri tuong doi khong cach nhau qua 5 pixel
		if ( abs(this->_pos.x - hideObj->_pos.x) < 5 && abs(this->getRect().bottom - hideObj->getRect().bottom) < 5)
		{
			this->_canFree = true;
			this->_moveMent = EnemyMovement::Free;
			this->_vx = 0;
		}else
		{
			this->_canFree = false;
		}
		////va cham theo chieu x
		//if (normalX != 0)
		//{
		//	_canFree = true;
		//	//this->_moveMent = SimonMove::Free;
		//}
	}
	//
	if (this->_pos.y < hideObj->getRect().bottom)
	{
		this->_canFree = false;
	}
}

void Enemy::isAttack()
{
	if (this->_timeDelayCur <= 0)
	{
		ManageAudio::getInstance()->playSound(TypeAudio::Hit);		
		this->_hp --;
		if (_hp <= 0)
		{
			//chet roi
			this->_isALive = false;
			Simon::getInstance()->addCoin(100);
			Item* item = ItemManager::getInstance()->appearItemEnemyDie(this->_pos);
			if (item != NULL)
			{
				QuadTreeObject::getInstance()->addObjectToQuadTree(item);
			}
		}

		_timeDelayCur =  TimeDelay;
	}
}

RECT Enemy::getRect()
{
	this->_rect.top = _pos.y + this->_height / 2;
	this->_rect.bottom = this->_rect.top - this->_height;

	this->_rect.left = _pos.x - this->_width / 2;
	this->_rect.right = this->_rect.left + this->_width;

	return this->_rect;
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
	}
	else
	{
		if (this->pause == false)
		{
			animated(delta_Time);

			updateMovement(delta_Time);

			handleCollision(delta_Time, _listObjectCollision);

			move(delta_Time);
		}
		
	}
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}
