#include "ManageGame.h"
#include "MovingPlatform.h"
#include "HideObject.h"
#include "TagClassName.h"

MovingPlatform::MovingPlatform(std::vector<std::string> arr) : GroundBGObj(arr)
{ 
	this->isStanding = false;
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_Vx_default = atoi(arr.at(8).c_str());
	this->_Vy_default = atoi(arr.at(9).c_str());
	this->_CanMoveL = true;
	this->_isALive = true;
	this->_rect = this->getRect();
	this->_Left = true;
	this->_vx = -this->_Vx_default;

	if (ManageGame::_infoScene->level == 2 && ManageGame::_infoScene->iD_Scene == 4)
	{
		this->distanceX = 90 - 32;
	}else
	{
		this->distanceX = 60 - 32;
	}
	
}

MovingPlatform::MovingPlatform() 
{
}

MovingPlatform::~MovingPlatform()
{
}

void MovingPlatform::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	//handleCollision(delta_Time, _listObjectCollision);
	move(delta_Time);
}

void MovingPlatform::move(float Delta_Time)
{ 
	/*if (this->_CanMoveL == true)
	{
		this->_pos.x += this->_Vx_default;
	}
	else
	{
		this->_pos.x -= this->_Vx_default;
	}*/
	/*int dir = this->_Left ? -1 : 1;
	this->_vx = this->_Vx_default * dir;*/
	this->_pos.x += this->_vx * Delta_Time;
	if (this->_pos.x >= posDefault.x + distanceX)
	{
		this->_pos.x = posDefault.x + distanceX;
		this->_vx = - this->_Vx_default;
	}else
	{
		if (this->_pos.x <= posDefault.x - distanceX)
		{
			this->_vx = this->_Vx_default;
		}
	}
}

void MovingPlatform::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	for (std::vector<ObjectGame*>::iterator it = _listObjectCollision.begin(); it != _listObjectCollision.end(); it++)
	{
		//lay box collider khi bat dau xu ly va cham
		this->_box = this->getBox();
		float normalX = 0;
		float normalY = 0;
		float timeCollision;

		ObjectGame* obj = *it;
		if (obj->className() == TagClassName::getInstance()->tagHideObject)
		{
			HideObject* hideObj = (HideObject*)obj;
			if (hideObj->getTypeHideObject() == TypeHideObect::Ground || hideObj->getTypeHideObject() == TypeHideObect::GroundVertical)
			{
				timeCollision = this->collision((StaticObject*)obj, normalX, normalY, deltatime);

				if (timeCollision == 2.0f)
				{
					//if (normalX > 0)
					{
						
						if (this->_vx < 0)
						{
							if (normalX > 0)
							{
								this->_pos.x += normalX;
								this->_pos.x += 3;
								this->_vx = this->_Vx_default;
							}
							
						}
						else
						{
							if (normalX < 0)
							{
								this->_pos.x += normalX;
								this->_pos.x -= 3;
								this->_vx = -this->_Vx_default;
							}
							
						}
					}
 					
					//this->_pos.y += normalY;
					//this->_Left = !this->_Left;
					/*if (normalX != 0)
					{
					if (normalX > 0)
					{
					this->_CanMoveL = false;
					}
					else
					{
					this->_CanMoveL = true;
					}
					}*/
				}

				if (timeCollision < 1.0f && timeCollision > 0.0f)//co va cham
				{
					//Object dang di chuyen qua ben trai
					if (normalX == 1)
					{
						this->_pos.x += timeCollision * (this->_vx * deltatime);
						//this->_Left = false;
						this->_vx = this->_Vx_default;
						this->_CanMoveL = true;
					}

					//Object dang di chuyen qua ben phai
					if (normalX == -1)
					{
						this->_pos.x += timeCollision * (this->_vx * deltatime);
						//this->_Left = true;
						this->_vx = -this->_Vx_default;
						this->_CanMoveL = true;
					}

				}
			}

		}
	}
}