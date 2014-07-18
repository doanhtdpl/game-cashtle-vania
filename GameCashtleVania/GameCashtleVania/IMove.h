#ifndef __INTERFACE_MOVE_H__
#define __INTERFACE_MOVE_H__

#include "utils.h"

class IMove
{
public:
	float _vx;
	float _vy;
	float _Vx_default;
	float _Vy_default;
	int _JumH_Max;//do cao max khi nhay
	int _High_Jumped;//do cao da nhay duoc
	bool _CanMoveL, _CanMoveR;
	bool _CanJum;// co the nhay
	Posture_Moves _posture;
public:
	virtual void Move(float Delta_Time) = 0;
	virtual void UpdatePostureMove(DWORD deltatime);
	IMove(void);
	~IMove(void);
};

#endif // !__INTERFACE_MOVE_H__
