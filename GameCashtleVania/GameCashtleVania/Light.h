#ifndef __LIGHT___
#define __LIGHT___

//Doi tuong den - co 2 loai den
//Khi roi danh thi roi item. 
//Ke thua GroundObj

#include "StaticObject.h"
#include "IAnimatedSprite.h"

class Light : public StaticObject, IAnimatedSprite
{
public:
	Light();
	Light(std::vector<std::string> arr);
	std::string className();
	void update(float deltaTime);
protected:
private:
};
#endif // !__LIGHT___
