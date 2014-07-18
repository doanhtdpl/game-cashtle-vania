#include "IAnimatedSprite.h"


IAnimatedSprite::IAnimatedSprite(void)
{
	_curFrame = 0;
	_totalFrames = 0;
	_coloumn = 0;
	_increase = 0;
	//_width = 0;
	//_height = 0;
}

IAnimatedSprite::IAnimatedSprite(int curFrame,int increase, int totalFrames, int coloumn, DWORD elapseTimeSwitchFrame)
{
	_curFrame = curFrame;
	_totalFrames = totalFrames;
	_coloumn = coloumn;
	_increase = increase;
	_elapseTimeSwitchFrame = elapseTimeSwitchFrame;
	_beforeTimeOld = 0.0f;
}

IAnimatedSprite::~IAnimatedSprite(void)
{
}

void IAnimatedSprite::Animated(float deltaTime)
{
	_beforeTimeOld += deltaTime;

	if (_beforeTimeOld > _elapseTimeSwitchFrame)
	{
		this->_curFrame += this->_increase;
		if (this->_curFrame >= this->_totalFrames)
		{
			this->_curFrame = 0;
		}

		_beforeTimeOld -= _elapseTimeSwitchFrame;
	}
	
}

RECT* IAnimatedSprite::UpdateRectRS(int width, int height)
{
	RECT* rectRS = new RECT();
	int x,y;
	x = (_curFrame % _coloumn) * width;
	y = (_curFrame / _coloumn) * height;
	//cập nhật lại vị trí của Rect Resource
	rectRS->left = x;
	rectRS->right = x + width;
	rectRS->top = y ;
	rectRS->bottom = y + height;

	return rectRS;
}
