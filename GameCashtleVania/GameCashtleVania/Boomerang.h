#ifndef __BOOMERANG_WEAPON_H__
#define __BOOMERANG_WEAPON_H__

#include "Weapon.h"

class Boomerang : public Weapon
{
public:
	Boomerang();
	Boomerang(std::vector<std::string> arr);
	void move(float delta_Time);
	void handleCollisionWithGround(HideObject* hideObj);
private:
	float _SPACE_MAX;  //Khoang cach toi da co the bay
	float _totalSpace; //Khoang cach hien tai so voi simon
};
#endif __BOOMERANG_WEAPON_H__
