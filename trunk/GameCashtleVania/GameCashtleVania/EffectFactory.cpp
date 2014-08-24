#include "EffectFactory.h"

EffectFactory* EffectFactory::_instance = NULL;

EffectFactory* EffectFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new EffectFactory();
	}

	return _instance;
}

EffectFactory::EffectFactory()
{

}

Effect* EffectFactory::createObj(int ID)
{
	std::vector<std::string> arr = this->getInfoByID(ID);

	return new Effect(arr);
}