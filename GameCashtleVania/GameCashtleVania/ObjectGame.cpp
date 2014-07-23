#include "ObjectGame.h"
using namespace std;

ObjectGame::ObjectGame(void)
{
	//_ID = 0;
	_isALive = true;
	_rectRS = NULL;
	_isAnimatedSprite = false;
	this->_height = 0;
	this->_width = 0;

}

ObjectGame::ObjectGame(std::vector<std::string> arr)
{

}

void ObjectGame::updateRect()
{
	this->_rect.top = _pos.y + this->_height / 2;
	this->_rect.bottom = this->_rect.top - this->_height;

	this->_rect.left = _pos.x - this->_width / 2;
	this->_rect.right = this->_rect.left + this->_width;
}

ObjectGame::~ObjectGame(void)
{
}

char* ObjectGame::className()
{
	return "Object Game";
}

Box ObjectGame::getBox()
{
	this->_box = Box(_pos.x, _pos.y, _width, _height);
	return _box;
}