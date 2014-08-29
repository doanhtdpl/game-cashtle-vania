#ifndef __BOSS__H_
#define	__BOSS__H_
#include <d3dx9.h>
#include "Enemy.h"

#define MAX_TIME_CHANGE_POSITION_RANDOM 2
#define MAX_TIME_CHANGE_POSITION_SIMON 3
class Boss : public Enemy
{

public:
	virtual void move(float delta_Time);
	Boss(std::vector<std::string> arr);
	Boss();
	void setMovement(EnemyMovement movement);
	~Boss();
	virtual void animated(float deltaTime);
	virtual void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual void fire();
	float eslapseTimeFire;
	float timeFireCur;
	bool attacking;//dang ban
	float timeDelayAttack;
	float timeDelayCur;
	int countFire;
	
protected:
	D3DXVECTOR3 arrPos[6];
	D3DXVECTOR2 posSimon;
	int dectPos;
	float timeChange;
	bool isAtackSimon;

};



#endif // !__BOSS_LEVEL1_H_
