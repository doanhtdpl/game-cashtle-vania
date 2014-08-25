#include "GroundBGFac.h"
#include "GroundBGObj.h"
//#include "Brick.h"
//#include "Stair.h"
//#include "Door.h"
#include "Gate.h"

GroundBGFac* GroundBGFac::_instance = NULL;

GroundBGFac* GroundBGFac::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new GroundBGFac();
	}
	return _instance;
}

GroundBGFac::GroundBGFac() 
{

}

GroundBGObj* GroundBGFac::createObj(int ID) 
{
	std::vector<std::string> arr = getInfoByID(ID);
	switch (ID)
	{
		//tao vien gach neu ID = 601
	case 651:
		return new Gate(arr);
		break;
		//tao cau thang neu ID = 602
	case 652:
		return new Gate(arr);
		break;
	case 653:
		return new Gate(arr);
		break;
	case 654:
		return new Gate(arr);
		break;
	default:
		break;
	}

	return NULL;
}
