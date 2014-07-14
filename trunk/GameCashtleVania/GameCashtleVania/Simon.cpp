#include "Simon.h"

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
	this->_pos.z = 0;

	//IMove
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_JumH_Max = atoi(arr.at(7).c_str());

	//IAnimated
	this->_curFrame = 12;
	this->_coloumn = atoi(arr.at(8).c_str());
	this->_totalFrames = atoi(arr.at(9).c_str());

	this->_rectRS = this->UpdateRectRS(this->_width, this->_height);
}

void Simon::Move(DWORD Delta_Time)
{

}

void Simon::Update(DWORD deltatime)
{

}

void Simon::Animated()
{

}