#ifndef __DRAGON__SKULL__CANNON__
#define __DRAGON__SKULL__CANNON__

#include "Enemy.h"

class DragonSkullCannon : public Enemy
{
public:
	DragonSkullCannon();
	DragonSkullCannon(std::vector<std::string> arr);
	void handleCollisionWithHideObject(float deltatime, HideObject* hideObj);
protected:
private:
};

#endif // !__DRAGON__SKULL__CANNON__
