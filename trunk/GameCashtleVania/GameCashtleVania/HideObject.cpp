#include "HideObject.h"
#include "TagClassName.h"

HideObject::HideObject()
{

}

HideObject::HideObject(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(1).c_str());
	this->_pos.x = atoi(arr.at(2).c_str());
	this->_pos.y = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(5).c_str());
	this->_width = atoi(arr.at(4).c_str());
}

void HideObject::setTypeHideObj(TypeHideObect _type)
{
	this->_typeHideObject = _type;
}

TypeHideObect HideObject::getTypeHideObject()
{
	return this->_typeHideObject;
}

std::string HideObject::className()
{
	return TagClassName::getInstance()->tagHideObject;
}