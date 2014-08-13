#ifndef __LIGHT___
#define __LIGHT___

//Doi tuong den - co 2 loai den
//Khi roi danh thi roi item. 
//Ke thua GroundObj

#include "StaticObject.h"
#include "IAnimatedSprite.h"
#include "Item.h"

enum TypeLight;

class Light : public StaticObject, IAnimatedSprite
{
public:
	Light();
	Light(std::vector<std::string> arr);
	std::string className();
	void update(float deltaTime);

	//tao ra item khi va cham voi roi.
	Item* effectWhenCollisionRod();
protected:
	TypeLight _typeLight;
private:
};
#endif // !__LIGHT___

#ifndef __TYPE__LIGHT__
#define __TYPE__LIGHT__

enum TypeLight
{
	BigLightHeart = 601,
	BigLightRod = 602,
	BigLightDagger = 603,
	SmallLightAxe = 611,
	SmallLightBoomerang = 612,
	SmallLightCross = 613,
	SmallLightDoubleShot = 614,
	SmallLightFireBomb = 615,
	SmallLightRandom = 616
};
#endif // !__TYPE__LIGHT__