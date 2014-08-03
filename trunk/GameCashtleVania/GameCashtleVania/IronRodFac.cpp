#include "IronRodFac.h"
#include "IronRod.h"

IronRodFac* IronRodFac::_instance = NULL;

IronRodFac* IronRodFac::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new IronRodFac();
	}
	return _instance;
}

IronRodFac::IronRodFac() 
{

}

IronRod* IronRodFac::createObj() 
{
	return IronRod::createInstance(info.at(0));
}