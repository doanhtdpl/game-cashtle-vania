#include "Gate.h"

Gate::Gate()
{

}

Gate::Gate(std::vector<std::string> arr) : GroundBGObj(arr)
{
	this->_coloumn = atoi(arr[5].c_str());
	this->_totalFrames = atoi(arr[6].c_str());
	this->_elapseTimeSwitchFrame = atof(arr[7].c_str());

	this->_curFrame = 0;
	this->_beforeTimeOld = 0;
	this->_Left = false;
	this->finish = false;
	this->_isAnimatedSprite = true;
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

void Gate::update(float deltaTime)
{
	if (!finish)
	{
		animated(deltaTime);
		this->_rectRS = this->updateRectRS(this->_width, this->_height);
	}
}

void Gate::animated(float deltaTime)
{
	_beforeTimeOld += deltaTime;

	if (_beforeTimeOld > _elapseTimeSwitchFrame)
	{
		this->_curFrame ++;
		if (this->_curFrame >= this->_totalFrames)
		{
			this->_curFrame = this->_totalFrames - 1;
			this->finish = true;
		}

		_beforeTimeOld -= _elapseTimeSwitchFrame;
	}
}