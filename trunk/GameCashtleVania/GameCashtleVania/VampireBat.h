#ifndef __VAMPIRE__BAT__
#define __VAMPIRE__BAT__

#include "Enemy.h"

class VampireBat : public Enemy
{
public:
	VampireBat();
	VampireBat(std::vector<std::string> arr);
	void move(float delta_Time);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
protected:
	
	float lamda;
	float k;//vung bound y.
private:
};

#endif // !__VAMPIRE__BAT__
