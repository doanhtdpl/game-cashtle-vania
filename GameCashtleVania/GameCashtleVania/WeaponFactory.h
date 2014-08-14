#ifndef __WEAPON_FACTORY_H__
#define __WEAPON_FACTORY_H__

#include "ObjectFactoty.h"
#include "Weapon.h"

class WeaponFactory : public ObjectFactory
{
public:
	WeaponFactory();
	static WeaponFactory* getInstance();
	Weapon* createObj(int ID); 
protected:
private:
	static WeaponFactory* _instance;
};


#endif // !__WEAPON_FACTORY_H__
