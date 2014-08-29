#ifndef __BOSS_LEVEL2_H_
#define	__BOSS_LEVEL2_H_
#include <d3dx9.h>
#include "Boss.h"

class BossLevel2 : public Boss
{

public:
	virtual void move(float delta_Time);
	virtual void animated(float deltaTime);
	virtual void fire();
	BossLevel2(std::vector<std::string> arr);
	BossLevel2();
	~BossLevel2();
	float timeDelayChangMovement;
private:
	

};



#endif // !__BOSS_LEVEL1_H_
