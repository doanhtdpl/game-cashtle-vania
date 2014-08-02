#include "IronRod.h"

IronRod* IronRod::_instance = NULL;

IronRod* IronRod::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new IronRod();
	}
	return _instance;
}

IronRod::IronRod()
{

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
		break;
	case State_Rod::Step2:
		this->_stateRod = State_Rod::Step3;
		//thay doi thoi gian
		break;
	case State_Rod::Step3:
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
		break;
	case Type_Rod::Rod2:
		break;
	case Type_Rod::Rod3:
		break;
	default:
		break;
	}
}

void IronRod::Use(D3DXVECTOR2 posSimon)
{

}

Box IronRod::getBox()
{
	return Box();
}

void IronRod::updateRectRS(int width, int height)
{

}
