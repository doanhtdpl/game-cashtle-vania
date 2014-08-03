#ifndef __IRON_ROD_FACTORY_H__
#define __IRON_ROD_FACTORY_H__
#include "ObjectFactoty.h"
#include "IronRod.h"
class IronRodFac: public ObjectFactory
{
public:
	static IronRodFac* getInstance();
	IronRod* createObj();
protected:
private:
	static IronRodFac* _instance;
	IronRodFac();
};

#endif // !__IronRod_FACTORY_H__
