#ifndef __IANIMATED_SPRITE_H__
#define __IANIMATED_SPRITE_H__
#include <d3d9.h>

class IAnimatedSprite
{
public:
	float _elapseTimeSwitchFrame;
	float _beforeTimeOld;
	int _curFrame;//curent frame
	int _increase;//increase curFrame;
	int _totalFrames;// total frame
	int _coloumn;//count coloumn frame
public:

	IAnimatedSprite(void);
	IAnimatedSprite(int curFrame,int increase, int totalFrames, int coloumn, DWORD _elapseTimeSwitchFrame);
	~IAnimatedSprite(void);
	virtual void Animated(float deltaTime);//change curframe
	RECT* UpdateRectRS(int width, int height);
};

#endif // !__IANIMATED_SPRITE_H__
