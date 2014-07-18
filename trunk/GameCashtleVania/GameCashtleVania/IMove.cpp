#include "IMove.h"


IMove::IMove(void)
{
}

IMove::~IMove(void)
{
}

void IMove::UpdatePostureMove(DWORD deltaTime)
{
//	switch (this->_posture)
//	{
//	case Posture_Moves::Sit:
//		this->_CanJum = false;
//		this->_CanMoveL = false;
//		this->_CanMoveR = false;
//
//		this->_vx = 0;
//		this->_vy = 0;
//		this->_High_Jumped = 0;
//		break;
//	case Posture_Moves::Stand:
//		this->_CanJum = true;
//		this->_CanMoveL = true;
//		this->_CanMoveR = true;
//
//		this->_vx = 0;
//		this->_vy = 0;
//		this->_High_Jumped = 0;
//		break;
//	case Posture_Moves::Free:
//		this->_CanJum = false;
//
//		this->_CanMoveL = false;
//		this->_CanMoveR = false;
//		this->_High_Jumped = 0;
//
//		break;
//	case Posture_Moves::Jum:
//		this->_CanJum = false;
//		//collision
//		if (this->_Left)
//		{
//			this->_CanMoveL = true;
//			this->_CanMoveR = false;
//		}else{
//			this->_CanMoveR = true;
//			this->_CanMoveL = false;
//		}
//
//		if (this->_vy <= 0)
//		{
//			this->_posture  = Posture_Moves::Free;
//		}
//		break;
//	case Posture_Moves::Run:
//		this->_CanJum = true;
//		this->_CanMoveL = true;
//		this->_CanMoveR = true;
//		this->_High_Jumped = 0;
//		this->_vy = 0;
//		break;
//	default:
//		break;
//	}
}
