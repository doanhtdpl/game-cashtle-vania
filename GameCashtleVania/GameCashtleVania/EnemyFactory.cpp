#include "EnemyFactory.h"
#include "Zombie.h"
#include "BlackKnight.h"
#include "BlackLeopard.h"
#include "DragonSkullCannon.h"
#include "FishMan.h"
#include "AxeMan.h"
#include "Ghost.h"
#include "VampireBat.h"
#include "Medusa.h"
#include "WhiteSkeleton.h"
#include "FireBall.h"

EnemyFactory* EnemyFactory::_instance = NULL;

EnemyFactory* EnemyFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new EnemyFactory();
	}
	return _instance;
}

EnemyFactory::EnemyFactory()
{

}

Enemy* EnemyFactory::createObj(int ID)
{
	std::vector<std::string> arr = getInfoByID(ID);
	//int ID = atoi(arr.at(0).c_str());
	Enemy* enemy = NULL;
	TypeEnemy _typeEnemy = TypeEnemy(ID);
	switch (_typeEnemy)
	{
	case TypeEnemy::ZOMBIE:
		enemy = new Zombie(arr);
		break;
	case TypeEnemy::AXE_MAN:
		enemy = new AxeMan(arr);
		break;
	case TypeEnemy::BLACK_KNIGHT:
		enemy = new BlackKnight(arr);
		break;
	case TypeEnemy::BLACK_LEOPARD:
		enemy = new BlackLeopard(arr);
		break;
	case TypeEnemy::DRAGON_SKULL_CANNON:
		enemy = new DragonSkullCannon(arr);
		break;
	case TypeEnemy::FISH_MAN:
		enemy = new FishMan(arr);
		break;
	case TypeEnemy::GHOST:
		enemy = new Ghost(arr);
		break;
	case TypeEnemy::MEDUSA:
		enemy = new Medusa(arr);
		break;
	case TypeEnemy::VAMPIRE_BAT:
		enemy = new VampireBat(arr);
		break;
	case TypeEnemy::WHITE_SKELETON:
		enemy = new WhiteSkeleton(arr);
		break;
	case TypeEnemy::FIRE_BALL:
		enemy = new FireBall(arr);
		break;
	default:
		break;
	}

	return enemy;
}

Enemy* EnemyFactory::createObj(std::vector<std::string> arr)
{
	int ID = atoi(arr.at(1).c_str());

	//lay thong tin tu info
	Enemy* obj = createObj(ID);

	//them vao thong tin pos
	int x = atoi(arr.at(2).c_str());
	int y = atoi(arr.at(3).c_str());
	obj->_pos.x = x;
	obj->_pos.y = y;
	obj->posDefault = obj->_pos;
	
	return obj;
}

std::vector<std::string> EnemyFactory::getInfoByID(int _ID)
{
	//tim arr nao co ID = _ID thi lay 
	std::vector<std::string> arr;
	for (int i = 0; i < info.size(); i++)
	{
		arr = info.at(i);
		if (atoi(arr.at(0).c_str()) == _ID)
		{
			return arr;
		}
	}
}