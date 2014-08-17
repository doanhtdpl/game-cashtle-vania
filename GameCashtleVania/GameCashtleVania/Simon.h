#ifndef __SIMON_H__
#define __SIMON_H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"
#include "IronRod.h"

enum SimonMove;
enum class StepOnStair;

class Simon : public DynamicObject, IAnimatedSprite
{
public:
	Simon();
	std::string className();
	static Simon* getInstance();
	static Simon* createInstance(std::vector<std::string> arr);
	~Simon();
	Simon(std::vector<std::string> arr);
	void updateMovement(float deltaTime);
	void move(float delta_Time);
	void update(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	RECT* updateRectRS(int width, int height);
	void animated(float deltatime);
	void processInput();
	
	//xu ly collision
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	float collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime);
	float collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime);

	bool _onStair;//dang o tren cau thang
	bool _prepareUpStairLeft;
	bool _prepareUpStairRight;
	bool _prepareDownStairLeft;
	bool _prepareDownStairRight;
	float _elapseTimeMoveStair;
	float _timeDelayMoveStair;
	StepOnStair _stepOnStair;
	SimonMove _moveMent;
	IronRod* ironRod;
	//Weapon* weaponCurr;
	TypeWeapon _typeOfWeaponCurr;

	//va cham voi enemy
	bool _collisionEnemy;

	bool _attacking;//dang dung item or dung roi.
protected:
	float HeightDefault;
	float HeightSit;
	float delayJump;
	float _timeDelayJumpCur;
	D3DXVECTOR2 posPrepareOnStair; //vi tri len or xuong cau thang. 
	RECT _rectOfStair;//vung bao cua cau thang. De dung khi di chuyen len xuong cau thang
private:
	static Simon* _instance;
};
#endif // !__SIMON_H__

#ifndef __SIMON_MOVE__
#define __SIMON_MOVE__

enum SimonMove
{
	None,//khong gi ca
	Moves,//dang di
	Idle,//dung yen
	Sit,//dang ngoi
	CollisionEnemy,
	//PrepareUpTheStairLeft,//chuan bi len cau thang ben trai
	//PrepareDownTheStairLeft,//chuan bi xuong cau thang ben trai
	UpStair,//dang di len cau thang
	OnStairUp,//dang o tren cau thang o trang thai di len
	OnStairDown,//dang dung tren cau thang o trang thai di xuong
	DownStair,
	//PrepareUpTheStairRight,//chuan bi len cau thang ben phai
	//PrepareDownTheStairRight,//chuan bi xuong can thang ben phai
	Jump,//dang nhay
	Free//dang roi tu do
};

#endif // !__SIMON_MOVE__

#ifndef __STEP_ON_STAIR__
#define __STEP_ON_STAIR__

enum class StepOnStair
{
	Step0 = 0,//chang lam gi ca
	Step1 = 1,
	Step2 = 2
};
#endif // !__STEP_ON_STAIR__
