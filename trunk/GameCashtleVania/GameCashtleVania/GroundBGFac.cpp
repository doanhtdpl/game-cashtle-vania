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
		return new MovingPlatform(arr);
		break;
	case 654:
		return new Gate(arr);
		break;
	default:
		break;
	}

	return NULL;
}

GroundBGObj* GroundBGFac::createObj(std::vector<std::string> arr)
{
	int ID = atoi(arr.at(1).c_str());

	//lay thong tin tu info
	GroundBGObj* obj = createObj(ID);

	//them vao thong tin pos
	int x = atoi(arr.at(2).c_str());
	int y = atoi(arr.at(3).c_str());
	obj->_pos.x = x;
	obj->_pos.y = y;

	return obj;
}
