#include "GroundBGFac.h"
#include "GroundBGObj.h"
#include "Brick.h"
#include "Stair.h"
#include "Door.h"

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

GroundBGObj* GroundBGFac::createObj(int ID_BG) 
{
	std::vector<std::string> arr = getInfoByIDBG(ID_BG);
	int ID = atoi(arr.at(0).c_str());
	switch (ID)
	{
		//tao vien gach neu ID = 601
	case 601:
		return new Brick(arr);
		break;
		//tao cau thang neu ID = 602
	case 602:
		return new Stair(arr);
		break;
	case 603:
		return new Door(arr);
		break;
	default:
		break;
	}
}

std::vector<std::string> GroundBGFac::getInfoByIDBG(int ID_BG)
{
	//tim arr nao co ID_Image = ID_BG thi lay 
	std::vector<std::string> arr;
	for (int i = 0; i < info.size(); i++)
	{
		arr = info.at(i);
		if (atoi(arr.at(1).c_str()) == ID_BG)
		{
			return arr;
		}
	}
}

//Hash Map chua IDBG -- IDImage
std::hash_map<int, int> GroundBGFac::getLishIDImageIDBG()
{
	std::hash_map<int, int> list;
	//tim nhung cap IDBG -- IDImage
	std::vector<std::string> arr;
	for (int i = 0; i < info.size(); i++)
	{
		arr = info.at(i);
		int IDImage = atoi(arr.at(1).c_str());
		int IDBG = atoi(arr.at(2).c_str());
		list[IDBG] = IDImage;
	}

	return list;
}