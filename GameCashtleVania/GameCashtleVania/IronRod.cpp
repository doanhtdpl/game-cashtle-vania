﻿#include "IronRod.h"

IronRod* IronRod::_instance = NULL;

IronRod* IronRod::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new IronRod();
	}
	return _instance;
}

IronRod* IronRod::createInstance(std::vector<std::string> arr)
{
	if (_instance == NULL)
	{
		_instance = new IronRod(arr);
	}
	return _instance;
}

IronRod::IronRod()
{

}

IronRod::IronRod(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_widthState12 = atoi(arr.at(3).c_str());
	this->_widthState3 = atoi(arr.at(4).c_str());
	this->_height = atoi(arr.at(5).c_str());
	this->realHeight = atoi(arr.at(6).c_str());
	this->_realWidthType12 = atoi(arr.at(7).c_str());
	this->_realWidthType3 = atoi(arr.at(8).c_str());
	this->_elapseTimeState1 = atof(arr.at(9).c_str());
	this->_elapseTimeState2 = atof(arr.at(10).c_str());
	this->_elapseTimeState3 = atoi(arr.at(11).c_str());
	
	this->_coloumn = atoi(arr.at(12).c_str());
	this->_totalFrames = atoi(arr.at(13).c_str());

	this->_width = this->_widthState12;
	this->realWidth = this->_realWidthType12;//loai ra so 1 va so 2// state 3
	this->_typeRod = Type_Rod::Rod1;
	this->_stateRod = State_Rod::Step1;
	this->_isALive = false;

	this->timeChangeState = _elapseTimeState1;
	this->_isAnimatedSprite = true;
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

Type_Rod IronRod::getTypeRod()
{
	return this->_typeRod;
}

State_Rod IronRod::getStateRod()
{
	return this->_stateRod;
}

void IronRod::ChangeState()
{
	switch (this->_stateRod)
	{
	case State_Rod::Step1:
		this->_stateRod = State_Rod::Step2;
		//thay doi thoi gian chuyen state nua
		this->timeChangeState = _elapseTimeState2;
		this->_width = this->_widthState12;
		break;
	case State_Rod::Step2:
		this->_stateRod = State_Rod::Step3;
		this->timeChangeState = _elapseTimeState3;
		this->_width = this->_widthState3;//width state 3 = 320. state 1 va 2  = 160
		//thay doi thoi gian
		break;
	case State_Rod::Step3:
		this->_isALive = false;
		//chuyen ve state 1
		this->_stateRod = State_Rod::Step1;
		this->timeChangeState = _elapseTimeState1;
		this->_width = this->_widthState12;
		// fisnish
		break;
	default:
		break;
	}
}

void IronRod::ChangeTypeRod()
{
	//thay doi chieu dai cua roi
	switch (this->_typeRod)
	{
	case Type_Rod::Rod1:
		this->_typeRod = Type_Rod::Rod2;
		this->realWidth = this->_realWidthType12;
		break;
	case Type_Rod::Rod2:
		this->_typeRod = Type_Rod::Rod3;
		this->realWidth = this->_realWidthType3;
		break;
	case Type_Rod::Rod3:
		//nothing
		break;
	default:
		break;
	}
}

void IronRod::Use(D3DXVECTOR2 posSimon, bool Left)
{
	this->_isALive = true;
	this->_pos = posSimon;
	this->_stateRod = State_Rod::Step1;
	this->_Left = Left;
}

//pos: pos dung de ve Rod.
//nhung box dung de va cham cua no lai khac
Box IronRod::getBox()
{
	// box dung de va cham tinh tu vi tri ve cua no tinh len.
	//Chi dung cho rod o trang thai 3. Trang thai 3 moi co va cham giet quai
	if (this->_Left)
	{
		return Box(this->_pos.x - this->realWidth / 2, this->_pos.y + this->realHeight / 2, 
			this->realWidth, this->realHeight);
	} 
	else
	{
		return Box(this->_pos.x + this->realWidth / 2, this->_pos.y + this->realHeight / 2, 
			this->realWidth, this->realHeight);
	}
	
}

void IronRod::update(float delta_Time, std::list<ObjectGame*> *_ListObjectCollision)
{
	if (this->_isALive)
	{
		/*timeChangeState -= delta_Time;
		if (timeChangeState <= 0)
		{
			ChangeState();
		}*/
		this->_stateRod = State_Rod::Step3;
		this->timeChangeState = _elapseTimeState3;
		this->_width = this->_widthState3;//width state 3 = 320. state 1 va 2  = 160
	}
	animated(delta_Time);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
	// va cham tinh sau.
}

void IronRod::animated(float deltaTime)
{
	this->_curFrame = this->_typeRod * this->_stateRod - 1;
}

RECT* IronRod::updateRectRS(int width, int height)
{
	RECT* rectRS = new RECT();
	int x,y;
	
	if (this->_stateRod == State_Rod::Step3)
	{
		x = (_curFrame % _coloumn) * this->_widthState12;
	}else
	{
		x = (_curFrame % _coloumn) * width;
	}
	
	y = (_curFrame / _coloumn) * height;
	//cập nhật lại vị trí của Rect Resource
	rectRS->left = x;
	rectRS->right = x + width;
	rectRS->top = y ;
	rectRS->bottom = y + height;

	return rectRS;
}