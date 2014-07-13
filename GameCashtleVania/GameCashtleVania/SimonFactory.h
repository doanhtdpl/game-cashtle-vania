#ifndef __SIMON_FACTORY_H__
#define __SIMON_FACTORY_H__
#include "ObjectFactoty.h"

class SimonFactory: public ObjectFactory
{
public:
	ObjectGame* CreateObj(); 
protected:
private:
};

#endif // !__SIMON_FACTORY_H__
