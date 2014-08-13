#include "Item.h"
#include "TagClassName.h"
#include "Simon.h"

Item::Item()
{

}

Item::Item(std::vector<std::string> arr)
{

}

void Item::move(float delta_Time)
{
	//huong di chuyen. Qua trai hay qua phai
	int dir = this->_Left ? 1 : -1;
	//
	this->_pos.x += this->_vx * delta_Time * dir;
	if (this->_pos.x >= maxX || this->_pos.x <= minX)
	{
		this->_Left = !this->_Left;
	}

	this->_pos.y += this->_vy * delta_Time;
}

void Item::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	for (int i = 0; i < _listObjectCollision.size(); i++)
	{
		ObjectGame* obj = _listObjectCollision.at(i);
		
		//doi tuong ground(nen)
		if (obj->className() == TagClassName::getInstance()->tagGroundObject)
		{
			//chuyen sang trang thai dung yen.
			this->_idle = true;
		}

		//neu object la simon thi effect
		if (obj->className() == TagClassName::getInstance()->tagSimon)
		{
			this->_isALive = false;
			effectSimon();
		}
	}
}

void Item::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	if (!this->_idle)
	{
		move(delta_Time);
	}else
	{
		//khi het thoi gian thi se bien mat
		this->timeLife -= delta_Time;
		if (timeLife <= 0)
		{
			this->_isALive = false;
		}
	}

	handleCollision(delta_Time, _listObjectCollision);
}

std::string Item::className()
{
	return TagClassName::getInstance()->tagItem;
}

void Item::appear(D3DXVECTOR2 posAppear)
{
	//add no vao map
	this->_pos = posAppear;
	this->maxX = this->_pos.x + disBound;
	this->minX = this->_pos.x - disBound;
	this->_isALive = true;
}

void Item::effectSimon()
{
	//thay doi vai gia tri cua simon
}