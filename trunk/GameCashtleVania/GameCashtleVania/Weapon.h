#ifndef __TYPE_OF_WEAPON__
#define __TYPE_OF_WEAPON__
enum class TypeWeapon
{
	Axe = 505,
	Boomerang = 506,
	Dagger = 507,
	FireBomb = 508,
	Watch = 509,
	FireBomb2 = 510,
	None = 0
};
#endif __TYPE_OF_WEAPON__

#ifndef __WEAPON__H__
#define __WEAPON__H__

//co 2 loai vu khi. Vu khi chinh: ROd. Va vu khi phu: cac item nhan duoc.
// implement phuong thuc update collision de xac dinh va cham voi enemy

#include "DynamicObject.h"
#include "IAnimatedSprite.h"
#include "HideObject.h"

class Weapon : public DynamicObject,public IAnimatedSprite
{
public:
	Weapon();
	Weapon(std::vector<std::string> arr);
	virtual void setTypeOfWeapon(TypeWeapon typeOfWeapon);
	virtual TypeWeapon getTypeOfWeapon();
	std::string className();
	virtual void Use(D3DXVECTOR2 posSimon, bool Left);
	virtual void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual void move(float delta_Time);
	virtual void handleCollision(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual void handleCollisionWithGround(HideObject* hideObj);
	void completeAttack();
protected:
private:
	TypeWeapon _typeOfWeapon;
};

#endif // !__WEAPON__H__