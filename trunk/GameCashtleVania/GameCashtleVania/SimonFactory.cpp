#include "SimonFactory.h"
#include "Simon.h"

SimonFactory* SimonFactory::_instance = NULL;

SimonFactory* SimonFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new SimonFactory();
	}
	return _instance;
}

SimonFactory::SimonFactory() 
{

}

Simon* SimonFactory::createObj() 
{
	return Simon::createInstance(info);
}