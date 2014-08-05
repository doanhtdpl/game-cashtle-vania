#ifndef __VAMPIRE__BAT__
#define __VAMPIRE__BAT__

#include "Enemy.h"

class VampireBat : public Enemy
{
public:
	VampireBat();
	VampireBat(std::vector<std::string> arr);
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
protected:
private:
};

#endif // !__VAMPIRE__BAT__
