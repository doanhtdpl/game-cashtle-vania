#ifndef __SIMON_FACTORY_H__
#define __SIMON_FACTORY_H__
#include "ObjectFactoty.h"
#include "Simon.h"
class SimonFactory: public ObjectFactory
{
public:
	static SimonFactory* getInstance();
	Simon* createObj();
protected:
private:
	static SimonFactory* _instance;
	SimonFactory();
};

#endif // !__SIMON_FACTORY_H__
