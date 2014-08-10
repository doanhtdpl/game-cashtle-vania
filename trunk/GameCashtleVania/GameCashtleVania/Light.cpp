#include "Light.h"
#include "TagClassName.h"

Light::Light()
{

}

Light::Light(std::vector<std::string> arr) : StaticObject(arr)
{
	this->_ID		= atoi(arr[0].c_str());
	this->_ID_Image = atoi(arr[1].c_str());
	this->_width	= atoi(arr[3].c_str());
	this->_height	= atoi(arr[4].c_str());

	//IAniamted Sprite
	this->_coloumn = atoi(arr[5].c_str());
	this->_totalFrames = atoi(arr[6].c_str());
	this->_elapseTimeSwitchFrame = atof(arr[7].c_str());
	this->_curFrame = 0;
	this->_beforeTimeOld = 0.0f;

	this->_isALive = true;
	this->_isAnimatedSprite = true;

}

std::string Light::className()
{
	return TagClassName::getInstance()->tagLight;
}

void Light::update(float deltaTime)
{
	animated(deltaTime);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

}