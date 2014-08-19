#ifndef __DAGGER_WEAPON_H__
#define __DAGGER_WEAPON_H__

#include "Weapon.h"

class Dagger : public Weapon
{
public:
	Dagger();
	Dagger(std::vector<std::string> arr);
	void move(float delta_Time);
	void handleCollisionWithGround(HideObject* hideObj);
	void Use(D3DXVECTOR2 posSimon, bool Left);
private:
};
#endif __DAGGER_WEAPON_H__
