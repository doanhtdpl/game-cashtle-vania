#ifndef __BOSS_LEVEL1_H_
#define	__BOSS_LEVEL1_H_
#include <d3dx9.h>
#include "Enemy.h"

#define MAX_TIME_CHANGE_POSITION_RANDOM 2
#define MAX_TIME_CHANGE_POSITION_SIMON 5
class BossLevel1 : public Enemy
{

public:	
	virtual void move(float delta_Time);
	BossLevel1(std::vector<std::string> arr);
	BossLevel1();
	~BossLevel1();
	virtual void animated(float deltaTime);
	virtual void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
private:
	D3DXVECTOR3 arrPos[6];
	D3DXVECTOR2 posSimon;
	int dectPos;
	float timeChange;
	bool isAtackSimon;

};



#endif // !__BOSS_LEVEL1_H_
