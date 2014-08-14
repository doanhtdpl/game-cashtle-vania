#include "WeaponFactory.h"
#include "Axe.h"
#include "Boomerang.h"
#include "Dagger.h"
#include "FireBomb.h"

WeaponFactory* WeaponFactory::_instance = NULL;

WeaponFactory::WeaponFactory()
{

}

WeaponFactory* WeaponFactory::getInstance()
{
	if(_instance == NULL)
	{
		_instance = new WeaponFactory();
	}
	return _instance;
}

Weapon* WeaponFactory::createObj(int ID)
{
	std::vector<std::string> arr = this->getInfoByID(ID);
	TypeWeapon typeOfWeapon = (TypeWeapon)ID;
	Weapon* weapon = NULL;

	switch (typeOfWeapon)
	{
	case TypeWeapon::Axe:
		weapon = new Axe(arr);
		break;
	case TypeWeapon::Boomerang:
		weapon = new Boomerang(arr);
		break;
	case TypeWeapon::Dagger:
		weapon = new Dagger(arr);
		break;
	case TypeWeapon::FireBomb:
		weapon = new FireBomb(arr);
		break;
	default:
		break;
	}
	return weapon;
}