#include "DynamicObject.h"

DynamicObject::DynamicObject(void)
{
	this->_CanMoveL = false;
	this->_CanMoveR = false;
	this->_CanJum = 0;
	this->_Left = false;
	this->_vx = 0;
	this->_vy = 0;
	this->_High_Jumped = 0;
}

DynamicObject::~DynamicObject(void)
{
}

void DynamicObject::Move(float Delta_Time)
{
	if (this->_pos.x < this->_width / 2)
		this->_pos.x = this->_width / 2;

	if (this->_CanMoveL)
	{
		if (this->_vx < 0)
		{
			this->_pos.x += this->_vx * Delta_Time;
		}
	}

	if (this->_CanMoveR)
	{
		if (this->_vx > 0)
		{
			this->_pos.x += this->_vx * Delta_Time;
		}
	}

	this->_pos.y += this->_vy * Delta_Time;
	if (this->_pos.y < 0)
	{
		this->_isALive = false;//die
	}
}

char* DynamicObject::className()
{
	return "Dynamic Object";
}

Box DynamicObject::GetBox()
{
	this->_box = Box(this->_pos.x, this->_pos.y, this->_width, this->_height, this->_vx, this->_vy);
	return _box;
}

void DynamicObject::Update(float deltatime)
{

}

void DynamicObject::Update(float Delta_Time, std::list<ObjectGame*> *_ListObjectCollision)
{
	this->UpdatePostureMove(Delta_Time);
	this->Move(Delta_Time);
}

float DynamicObject::Collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime)
{
	return 0.0f;
}

float DynamicObject::Collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime)
{
	Box box = this->GetBox();
	Box staticBox = staticObject->GetBox();

	Box broadphaseBox = ICollision::GetInstance()->GetSweptBroadphaseBox(box, deltaTime);

	float moveX = 0;
	float moveY = 0;

	//kiem tra 2 box hien tai da va cham chua
	if (ICollision::GetInstance()->AABBCheck(box, staticBox))
	{
		//dich chuyen object
		return 0.0f;
	}else
	{
		//kiem tra 2 object co the va cham ko?
		if (ICollision::GetInstance()->AABB(broadphaseBox, staticBox, moveX, moveY))
		{
			float timeCol = ICollision::GetInstance()->SweptAABB(box, staticBox, normalx, normaly, deltaTime);
			return timeCol;
		}else
		{
			return 1.0;//khong co va cham
		}
	}
}