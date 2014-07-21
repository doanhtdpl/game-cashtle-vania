#include "Brick.h"

Brick::Brick() : StaticObject()
{
	this->_ID = 301;
	this->_pos.x = 80;
	this->_pos.y = 16;
	this->_width = this->_height = 32;
	this->_ID_Image = 1028;
	this->_isAnimatedSprite = false;
	this->_isALive = true;
}