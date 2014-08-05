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

void DynamicObject::move(float Delta_Time)
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

std::string DynamicObject::className()
{
	return "Dynamic Object";
}

Box DynamicObject::getBox()
{
	this->_box = Box(this->_pos.x, this->_pos.y, this->_width, this->_height, this->_vx, this->_vy);
	return _box;
}

void DynamicObject::update(float deltatime)
{

}

void DynamicObject::update(float delta_Time, std::vector<ObjectGame*> listObjectCollision)
{
	this->updatePostureMove(delta_Time);
	this->move(delta_Time);
}

void DynamicObject::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{

}

float DynamicObject::collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime)
{
	return 0.0f;
}

float DynamicObject::collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime)
{
	Box box = this->getBox();
	Box staticBox = staticObject->getBox();

	Box broadphaseBox = ICollision::getInstance()->getSweptBroadphaseBox(box, deltaTime);

	float moveX = 0;
	float moveY = 0;

	//kiem tra 2 box hien tai da va cham chua
	if (ICollision::getInstance()->AABBCheck(box, staticBox))
	{
		//dich chuyen object
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