#ifndef __EFFECT__
#define __EFFECT__

#include "StaticObject.h"
#include "IAnimatedSprite.h"
enum TypeEffect;

class Effect : public StaticObject, public IAnimatedSprite
{
public:
	TypeEffect _typeEffect;
	Effect();
	Effect(std::vector<std::string> arr);
	~Effect();

	virtual std::string className();
	void update(float deltaTime);
	void animated(float deltaTime);
private:
	float lifeTime;
};

#endif // !__EFFECT__

#ifndef __TYPE__EFFECT__

enum TypeEffect
{
	typeEffect0 = 350,
	typeEffect1 = 351,
	typeEffect2 = 352
};
#endif // !__TYPE__EFFECT__

