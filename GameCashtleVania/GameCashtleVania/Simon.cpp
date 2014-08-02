#include "Simon.h"
#include "utils.h"
#include "Input.h"

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
	this->_pos.x = 30;
	this->_pos.y = 34;

	//IMove
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_JumH_Max = atoi(arr.at(7).c_str());

	//IAnimated
	this->_curFrame = 12;
	this->_coloumn = atoi(arr.at(8).c_str());
	this->_totalFrames = atoi(arr.at(9).c_str());
	this->_elapseTimeSwitchFrame = EslapseTimeSwitchFrame;
	this->_beforeTimeOld = 0.0f;

	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	_moveMent = SimonMove::Stand;
	this->_CanJum = true;
	this->_CanMoveL = true;
	this->_CanMoveR = true;
	this->_vx = this->_Vx_default;
	this->_vy = this->_Vy_default;
}

void Simon::move(float delta_Time)
{
	switch (_moveMent)
	{
	case None:
		break;
	case Moves:
		if (this->_Left)//dang di chuyen qua ben trai
		{
			if (this->_CanMoveL)
			{
				this->_pos.x -= this->_vx * delta_Time;
			}else
			{
				_moveMent = SimonMove::Stand;
			}
		}else
		{
			if (this->_CanMoveR)
			{
				this->_pos.x += this->_vx * delta_Time;
			}else
			{
				_moveMent = SimonMove::Stand;
			}
		}
		break;
	case Stand:
		break;
	case OnStair:
		break;
	case Jum:
		this->_pos.y += this->_vy * delta_Time;
		this->_High_Jumped += this->_vy * delta_Time;
		if (this->_High_Jumped >= this->_JumH_Max)
		{
			//dam bao luc nao simon cung chi nhay khong vuot qua JumH_Max
			this->_pos.y -= this->_High_Jumped - this->_JumH_Max;
			this->_moveMent =  SimonMove::Free;
			this->_High_Jumped = false;
		}
		break;
	case Free:
		//khi nao cham dat thi dung
		this->_pos.y += this->_vy * delta_Time * 2;//chi can cho roi nhanh hon thoi. Khong can dung gia toc
		break;
	default:
		break;
	}
}

void Simon::update(float deltatime)
{
	move(deltatime);
	animated(deltatime);

	if (this->_moveMent == SimonMove::Moves)
	{
		this->_moveMent = SimonMove::Stand;
	}
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
			break;
		case Free:
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
	if (Input::CreateInstance()->IsKeyDown(DIK_RIGHT))
	{
		this->_moveMent = SimonMove::Moves;
		this->_Left = false;
	}else
	{
		if (Input::CreateInstance()->IsKeyDown(DIK_LEFT))
		{
			this->_moveMent = SimonMove::Moves;
			this->_Left = true;
		}
	}

	if (key == DIK_Z)
	{
		this->_moveMent = SimonMove::Jum;
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
			this->_pos.x += moveX;
			this->_pos.y += moveY;
		}
		return 0.0f;
	}else
	{
		//kiem tra 2 object co the va cham ko?
		if (ICollision::getInstance()->AABB(broadphaseBox, staticBox, moveX, moveY))
		{
			float timeCol = ICollision::getInstance()->sweptAABB(box, staticBox, normalx, normaly, deltaTime);
			return timeCol;
		}else
		{
			return 1.0;//khong co va cham
		}
	}
}