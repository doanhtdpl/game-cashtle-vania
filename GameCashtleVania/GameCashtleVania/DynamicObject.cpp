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

void DynamicObject::Update(float deltatime)
{

}

void DynamicObject::Update(float Delta_Time, std::list<ObjectGame*> *_ListObjectCollision)
{
	this->UpdatePostureMove(Delta_Time);
	this->Move(Delta_Time);
}