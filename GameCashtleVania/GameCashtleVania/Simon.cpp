#include "Simon.h"
#include "utils.h"
#include "Input.h"
#include "IronRod.h"
#include "TagClassName.h"

Simon* Simon::_instance = NULL;

Simon* Simon::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Simon();
	}

	return _instance;
}

Simon* Simon::createInstance(std::vector<std::string> arr)
{
	if (_instance == NULL)
	{
		_instance = new Simon(arr);
	}

	return _instance;
}

Simon::Simon() : DynamicObject()
{

}

Simon::Simon(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_isAnimatedSprite = true;

	//doc tu map
	this->_pos.x = 60;
	this->_pos.y = 200;

	//IMove
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_JumH_Max = atoi(arr.at(7).c_str());

	//IAnimated
	this->_curFrame = 0;
	this->_coloumn = atoi(arr.at(8).c_str());
	this->_totalFrames = atoi(arr.at(9).c_str());
	this->_elapseTimeSwitchFrame = EslapseTimeSwitchFrame;
	this->_beforeTimeOld = 0.0f;

	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	_moveMent = SimonMove::Free;
	this->_CanJum = true;
	this->_CanMoveL = true;
	this->_CanMoveR = true;
	//this->_vx = this->_Vx_default;
	//this->_vy = this->_Vy_default;

	this->_Left = false;

	//nhay toi vi tri cao nhat thi dung lai 0.2. sau do moi roi
	this->_CanJum = true;
	this->delayJump = 0.15;//doc tu file luon.
	this->_timeDelayJumpCur = 0.0f;
}

// UPdate trang thai cua simon truoc. Sau do moi tinh cho no Move nhu the nao
void Simon::updateMovement(float delta_Time)
{
	switch (_moveMent)
	{
	case None:
		break;
	case Moves:
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
	case Stand:
		this->_CanMoveL = true;
		this->_CanMoveR = true;
		this->_High_Jumped = 0;
		this->_CanJum = true;
		this->_vx = 0.0f;
		this->_vy = 0.0f;
		break;
	case OnStair:
		break;
	case Jum:
		this->_vy = this->_Vy_default;
		this->_High_Jumped += this->_vy * delta_Time;
		this->_CanJum = false;

		//khi dang nhay thi khong the di chuyen. Chi dua vao van toc dau. Van toc dau > 0 thi co Jump and Move
		this->_CanMoveL = false;
		this->_CanMoveR = false;

		if (this->_vx != 0)
		{
			//co nen giam toc do cua vx ko?
			this->_pos.x += delta_Time * this->_vx;
		}

		//da dat toi nguong --> delay. rot xuong
		if (this->_High_Jumped >= this->_JumH_Max)
		{
			this->_vy = 0.0f;
			this->_timeDelayJumpCur += delta_Time;

			if (this->_timeDelayJumpCur >= delayJump)
			{
				//het thoi gian delay. Roi xuong thoi!!!
				this->_timeDelayJumpCur = 0.0f;
				this->_moveMent = SimonMove::Free;
			}
		}
		break;
	case Free:
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

void Simon::move(float delta_Time)
{
	if ((this->_CanMoveL && this->_vx < 0) || (this->_CanMoveR && this->_vx > 0))
	{
		//co the di qua ben trai va v
		this->_pos.x += this->_vx * delta_Time;
		this->_moveMent = SimonMove::Stand;
	}
	
	this->_pos.y += this->_vy * delta_Time;

}

void Simon::update(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	animated(deltatime);

	updateMovement(deltatime);

	move(deltatime);

	handleCollision(deltatime, _listObjectCollision);

	//updateMovement(deltatime);

	this->_box = this->getBox();
	/*for (int i = 0; i < _listObjectCollision.size(); i++)
	{
		ObjectGame* obj = _listObjectCollision.at(i);
		this->collision((StaticObject*)obj, normalX, normalY, deltatime);
	}*/


	IronRod::getInstance()->update(deltatime, NULL);
}

void Simon::update(float deltatime)
{
	move(deltatime);
	animated(deltatime);

	if (this->_moveMent == SimonMove::Moves)
	{
		this->_moveMent = SimonMove::Stand;
	}

	IronRod::getInstance()->update(deltatime, NULL);
}

void Simon::animated(float deltatime)
{
	this->_beforeTimeOld += deltatime;
	if (_beforeTimeOld > _elapseTimeSwitchFrame)
	{
		_beforeTimeOld -= _elapseTimeSwitchFrame;
		switch (_moveMent)
		{
		case None:
			break;
		case Moves:
			this->_curFrame ++;
			if (_curFrame > 3 )
			{
				_curFrame = 0;
			}
			break;
		case Stand:
			this->_curFrame = 0;
			break;
		case OnStair:
			break;
		case Jum:
			this->_curFrame = 4;
			break;
		case Free:
			this->_curFrame = 0;
			break;
		default:
			break;
		}
	}

	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

void Simon::processInput()
{
	Input::CreateInstance()->ProcessKeyboard();

	Input::CreateInstance()->Update();

	int key = Input::CreateInstance()->GetKeyDown();
	int key_up = Input::CreateInstance()->GetKeyUp();

	//de phim
	if (Input::CreateInstance()->IsKeyDown(DIK_RIGHT) && this->_CanMoveR)
	{
		this->_moveMent = SimonMove::Moves;
		this->_Left = false;
	}else
	{
		if (Input::CreateInstance()->IsKeyDown(DIK_LEFT) && this->_CanMoveL)
		{
			this->_moveMent = SimonMove::Moves;
			this->_Left = true;
		}
	}

	if (key == DIK_SPACE)
	{
		if (this->_CanJum)
		{
			this->_moveMent = SimonMove::Jum;
		}
	}

	if (key == DIK_Z)
	{
		IronRod::getInstance()->Use(this->_pos, this->_Left);
	}
}

void Simon::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//lay box collider khi bat dau xu ly va cham
	this->_box = this->getBox();
	float normalX = 0;
	float normalY = 0;
	float timeCollision;
	for (int i = 0; i < _listObjectCollision.size(); i++)
	{
		ObjectGame* obj = _listObjectCollision.at(i);
		if (obj->className() == TagClassName::getInstance()->tagGroundObject)
		{
			//va cham voi doi tuong nen
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, deltatime);
			if (timeCollision == 2.0f)
			{
				// bi va cham theo AABBCheck
				if (this->_moveMent == SimonMove::Free || this->_moveMent == SimonMove::Moves)
				{
					this->_moveMent = SimonMove::Stand;
					this->_pos.x += normalX;
					this->_pos.y += normalY;
					this->_vx = 0;
					this->_vy = 0;
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
					this->_pos.x += timeCollision * (deltatime * this->_vx);
					if (this->_moveMent == SimonMove::Jum)
					{
						this->_moveMent == SimonMove::Free;
					}
					this->_CanMoveL = false;
				}

				//Object dang di chuyen qua ben phai
				if (normalX == -1)
				{
					this->_pos.x += timeCollision * (deltatime * this->_vx);
					if (this->_moveMent == SimonMove::Jum)
					{
						this->_moveMent == SimonMove::Free;
					}
					this->_CanMoveR = false;
				}

				//Obj dang roi
				if (normalY == 1)
				{
					this->_pos.y += timeCollision * (deltatime * this->_vy);
 					this->_moveMent = SimonMove::Stand;
					
				}

				//obj dang nhay
				if (normalY == -1)
				{
					//ko lam gi ca
				}
			}
		}
	}
}

//implement method collision
float Simon::collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime)
{
	return 0.0f;
}

float Simon::collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime)
{
	Box box = this->getBox();
	Box staticBox = staticObject->getBox();

	Box broadphaseBox = ICollision::getInstance()->getSweptBroadphaseBox(box, deltaTime);

	float moveX = 0;
	float moveY = 0;

	//kiem tra 2 box hien tai da va cham chua
	if (ICollision::getInstance()->AABBCheck(box, staticBox))
	{
		if (ICollision::getInstance()->AABB(box, staticBox, moveX, moveY))
		{
			normalx = moveX;
			normaly = moveY;
			//this->_pos.x += moveX;
			//this->_pos.y += moveY;
		}
		return 2.0f;
	}else
	{
		//kiem tra 2 object co the va cham ko?
		if (ICollision::getInstance()->AABBCheck(broadphaseBox, staticBox))
		{
			float timeCol = ICollision::getInstance()->sweptAABB(box, staticBox, normalx, normaly, deltaTime);
			return timeCol;
			/*if (timeCol < 1.0f)
			{
				return timeCol;
			}else
			{
				return 1.0f;
			}*/
		}else
		{
			return 1.0;//khong co va cham
		}
	}

	return 0.0f;
}