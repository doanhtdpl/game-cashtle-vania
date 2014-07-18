#ifndef __SIMON_H__
#define __SIMON_H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"

enum SimonMove;

class Simon : public DynamicObject, IAnimatedSprite
{
public:
	Simon();
	static Simon* GetInstance();
	static Simon* CreateInstance(std::vector<std::string> arr);
	~Simon();
	Simon(std::vector<std::string> arr);
	void Move(float Delta_Time);
	void Update(float deltatime);
	void Animated(float deltatime);
	void ProcessInput();
protected:
private:
	static Simon* _instance;
	SimonMove _moveMent;
};
#endif // !__SIMON_H__

#ifndef __SIMON_MOVE__
#define __SIMON_MOVE__

enum SimonMove
{
	None,//khong gi ca
	Moves,//dang di
	Stand,//dung yen
	PrepareUpTheStair,//chuan bi len cau thang
	OnStair,//dang dung tren cau thang
	UpTheStair,//len cau thang
	Jum,//dang nhay
	Free//dang roi tu do
};

#endif // !__SIMON_MOVE__