#include "TagClassName.h"

TagClassName* TagClassName::_instance = NULL;

TagClassName* TagClassName::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new TagClassName();
	}

	return _instance;
}

TagClassName::TagClassName()
{
	this->tagEnemy = "Enemy";
	this->tagGroundObject = "GroundObject";
}