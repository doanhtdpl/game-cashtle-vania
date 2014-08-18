#include "Item.h"
#include "TagClassName.h"
#include "Simon.h"
#include "HideObject.h"

Item::Item()
{

}

Item::Item(std::vector<std::string> arr)
{
	this->_isALive = true;
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_coloumn = atoi(arr.at(7).c_str());
	this->_totalFrames = atoi(arr.at(8).c_str());

	this->_vx = this->_Vx_default;
	this->_vy = -this->_Vy_default;
	this->disBound = DisBound;
	this->_typeItem = (TypeItem)this->_ID;

	this->_rect = this->getRect();

	this->_idle = false;
	this->timeLife = 3.0f;
}

Box Item::getBox()
{
	this->_box = Box(this->_pos.x, this->_pos.y, this->_width, this->_height + 25, this->_vx, this->_vy);
	return _box;
}

void Item::move(float delta_Time)
{
	//huong di chuyen. Qua trai hay qua phai
	int dir = this->_Left ? 1 : -1;
	//
	this->_pos.x += this->_vx * delta_Time * dir;
	if (this->_pos.x >= maxX || this->_pos.x <= minX)
	{
		this->_vx = - this->_vx;
		//this->_Left = !this->_Left;
	}

	this->_pos.y += this->_vy * delta_Time;
}

void Item::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	float normalX = 0;
	float normalY = 0;
	float timeCollision;
	std::vector<ObjectGame*>::iterator it = _listObjectCollision.begin();
	ObjectGame* obj = NULL;
	while (it != _listObjectCollision.end())
	{
		obj = *it++;

		//doi tuong ground(nen)
		if (obj->className() == TagClassName::getInstance()->tagHideObject)
		{
			HideObject* hideObj = (HideObject*)obj;
			if (hideObj->getTypeHideObject() == TypeHideObect::Ground)
			{
				//chuyen sang trang thai dung yen.
				timeCollision = this->collision((StaticObject*)obj, normalX, normalY, deltatime);
				/*if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
				{
					this->_idle = true;
				}*/
				if (timeCollision == 2.0f)
				{
					if (normalY != 0)
					{
						this->_pos.y += normalY;
						this->_idle = true;
					}
				}else
				{
					if (timeCollision > 0.0f && timeCollision < 1.0f)
					{
						if (normalY == 1)
						{
							//dang roi
							this->_pos.y += timeCollision * this->_vy * deltatime;
							this->_idle = true;
						}
					}
				}
			}
		}

		////neu object la simon thi effect
		//if (obj->className() == TagClassName::getInstance()->tagSimon)
		//{
		//	timeCollision = this->collision((StaticObject*)obj, normalX, normalY, deltatime);
		//	if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
		//	{
		//		this->_isALive = false;
		//		effectSimon();
		//	}

		//}
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