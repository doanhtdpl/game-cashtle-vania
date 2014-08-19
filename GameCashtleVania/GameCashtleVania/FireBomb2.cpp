#include "FireBomb2.h"

FireBomb2::FireBomb2()
{

}

FireBomb2::FireBomb2(std::vector<std::string> arr) : Weapon(arr)
{
	this->_typeOfWeapon = TypeWeapon::FireBomb2;
	life_Time = atof(arr.at(10).c_str());
	this->_rect = this->getRect();
	this->_isAnimatedSprite = true;
	this->_curFrame = 0;
}

void FireBomb2::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	if (life_Time > 0)
	{
		life_Time -= delta_Time;
	}else
	{
		this->_isALive = false;
	}

	animated(delta_Time);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
	handleCollision(delta_Time, _listObjectCollision);
}