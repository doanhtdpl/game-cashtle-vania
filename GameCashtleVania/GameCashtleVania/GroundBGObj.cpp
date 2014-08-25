#include "GroundBGObj.h"
#include "TagClassName.h"

GroundBGObj::GroundBGObj() : StaticObject()
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