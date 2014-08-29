#ifndef __DRAGON__SKULL__CANNON__
#define __DRAGON__SKULL__CANNON__

#include "Enemy.h"

class DragonSkullCannon : public Enemy
{
public:
	DragonSkullCannon();
	DragonSkullCannon(std::vector<std::string> arr);
	//void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
protected:
	void fire();
	float eslapseTimeFire;
	float timeFireCur;
private:
};

#endif // !__DRAGON__SKULL__CANNON__
