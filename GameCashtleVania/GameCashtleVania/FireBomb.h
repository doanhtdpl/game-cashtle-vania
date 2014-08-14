#ifndef __FIREBOMB_WEAPON_H__
#define __FIREBOMB_WEAPON_H__

#include "Weapon.h"

class FireBomb : public Weapon
{
public:
	FireBomb();
	FireBomb(std::vector<std::string> arr);
	void move(float delta_Time);
	void handleCollisionWithGround(HideObject* hideObj);
};
#endif __FIREBOMB_WEAPON_H__
