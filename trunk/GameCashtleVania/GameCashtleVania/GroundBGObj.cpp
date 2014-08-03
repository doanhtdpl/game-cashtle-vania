#include "GroundBGObj.h"
#include "TagClassName.h"

GroundBGObj::GroundBGObj() : StaticObject()
{

}

GroundBGObj::GroundBGObj(std::vector<std::string> arr)
{
	this->_ID		= atoi(arr[0].c_str());
	this->_ID_Image = atoi(arr[1].c_str());
	this->_ID_BG	= atoi(arr[2].c_str());
	this->_width	= atoi(arr[4].c_str());
	this->_height	= atoi(arr[5].c_str());
}

std::string GroundBGObj::className()
{
	return TagClassName::getInstance()->tagGroundObject;
}