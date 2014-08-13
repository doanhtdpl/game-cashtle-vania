#ifndef __VAMPIRE__BAT__
#define __VAMPIRE__BAT__

#include "Enemy.h"

class VampireBat : public Enemy
{
public:
	VampireBat();
	VampireBat(std::vector<std::string> arr);
	void handleCollisionWithHideObject(float deltatime, HideObject* hideObj);
protected:
private:
};

#endif // !__VAMPIRE__BAT__
