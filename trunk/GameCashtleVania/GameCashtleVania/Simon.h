#ifndef __SIMON_H__
#define __SIMON_H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"
#include "IronRod.h"

enum SimonMove;

class Simon : public DynamicObject, IAnimatedSprite
{
public:
	Simon();
	static Simon* getInstance();
	static Simon* createInstance(std::vector<std::string> arr);
	~Simon();
	Simon(std::vector<std::string> arr);
	void updateMovement(float deltaTime);
	void move(float delta_Time);
	void update(float deltatime);
	void update(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	RECT* updateRectRS(int width, int height);
	void animated(float deltatime);
	void processInput();
	
	//xu ly collision
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	float collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime);
	float collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime);

	IronRod* ironRod;
protected:
	float HeightDefault;
	float HeightSit;
	float delayJump;
	float _timeDelayJumpCur;
	float _attacking;//dang dung item or dung roi.
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
	Sit,//dang ngoi
	PrepareUpTheStair,//chuan bi len cau thang
	PrepareDownTheStair,
	UpStair,//dang di len cau thang
	DownStair,
	PrepareLeaveTheStair,//len cau thang
	Jum,//dang nhay
	Free//dang roi tu do
};

#endif // !__SIMON_MOVE__