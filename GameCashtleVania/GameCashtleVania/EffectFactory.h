#ifndef __EFFECT__FACTORY__
#define __EFFECT__FACTORY__

#include "ObjectFactoty.h"
#include "Effect.h"

class EffectFactory : public ObjectFactory
{
public:
	static EffectFactory* getInstance();
	Effect* createObj(int ID);
private:
	static EffectFactory* _instance;
	EffectFactory();
};

#endif // !__EFFECT__FACTORY__
