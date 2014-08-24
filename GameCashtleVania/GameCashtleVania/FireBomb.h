#ifndef __FIREBOMB_WEAPON_H__
#define __FIREBOMB_WEAPON_H__

#include "Weapon.h"

class FireBomb : public Weapon
{
public:
	FireBomb();
	FireBomb(std::vector<std::string> arr);
	void move(float delta_Time);
	void animated(float deltaTime);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	void handleCollisionWithGround(HideObject* hideObj);
protected:
	float life_Time;//thoi gian ton tai
	bool colGround;
};
#endif __FIREBOMB_WEAPON_H__
