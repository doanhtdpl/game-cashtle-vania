#ifndef __AXE_WEAPON__
#define __AXE_WEAPON__

#include "Weapon.h"

class Axe : public Weapon
{
public:
	Axe();
	Axe(std::vector<std::string> arr);
	void move(float delta_Time);
	void handleCollisionWithGround(HideObject* hideObj);
};
#endif __AXE_WEAPON__
