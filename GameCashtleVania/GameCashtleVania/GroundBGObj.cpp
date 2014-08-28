#include "GroundBGObj.h"
#include "TagClassName.h"

GroundBGObj::GroundBGObj() : DynamicObject()
{

}

GroundBGObj::GroundBGObj(std::vector<std::string> arr)
{
	this->_isALive = true;
	this->_ID		= atoi(arr[0].c_str());
	this->_ID_Image = atoi(arr[1].c_str());
	this->_width	= atoi(arr[3].c_str());
	this->_height	= atoi(arr[4].c_str());	
}

std::string GroundBGObj::className()
{
	return TagClassName::getInstance()->tagGroundObject;
}

void GroundBGObj::update(float deltaTime)
{

}

void GroundBGObj::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{

}
void GroundBGObj::move(float Delta_Time)
{

}
void GroundBGObj::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{

}
//float GroundBGObj::collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime)
//{
//
//}