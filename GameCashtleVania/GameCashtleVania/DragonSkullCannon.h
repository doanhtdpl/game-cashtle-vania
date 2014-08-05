#ifndef __DRAGON__SKULL__CANNON__
#define __DRAGON__SKULL__CANNON__

#include "Enemy.h"

class DragonSkullCannon : public Enemy
{
public:
	DragonSkullCannon();
	DragonSkullCannon(std::vector<std::string> arr);
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
protected:
private:
};

#endif // !__DRAGON__SKULL__CANNON__
