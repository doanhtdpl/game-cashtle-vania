#include "Effect.h"
#include "TagClassName.h"

Effect::Effect()
{
	
}

Effect::~Effect()
{
	
}

Effect::Effect(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_coloumn = atoi(arr.at(5).c_str());
	this->_totalFrames = atoi(arr.at(6).c_str());
	this->_elapseTimeSwitchFrame = atof(arr.at(7).c_str());
	this->lifeTime = atof(arr.at(8).c_str());

	this->_isAnimatedSprite = true;
	this->_isALive = true;
	this->_curFrame = 0;
	this->_beforeTimeOld = 0.0f;
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	this->_typeEffect = (TypeEffect)this->_ID;
}

void Effect::animated(float deltaTime)
{
	IAnimatedSprite::animated(deltaTime);
}

void Effect::update(float deltaTime)
{
	lifeTime -= deltaTime;
	if (lifeTime <= 0)
	{
		this->_isALive = false;
	}

	animated(deltaTime);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

std::string Effect::className()
{
	return TagClassName::getInstance()->tagEffect;
}