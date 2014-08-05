#include "HideObject.h"
#include "TagClassName.h"

HideObject::HideObject()
{

}

HideObject::HideObject(std::vector<std::string> arr)
{

}

TypeHideObect HideObject::getTypeHideObject()
{
	return this->_typeHideObject;
}

std::string HideObject::className()
{
	return TagClassName::getInstance()->tagHideObject;
}