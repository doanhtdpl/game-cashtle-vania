#ifndef __FISH__MAN__
#define __FISH__MAN__


#include "Enemy.h"

class FishMan : public Enemy
{
public:
	FishMan();
	FishMan(std::vector<std::string> arr);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	void animated(float deltaTime);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	void fire();
	float eslapseTimeFire;
	float timeFireCur;
	bool attacking;//dang ban
	float timeDelayAttack;
	float timeDelayCur;
	int countFire;
protected:
private:
};

#endif // !__FISH__MAN__
