#include "BossLevel1.h"
#include "ManageGame.h"
#include "FireBall.h"
#include "EnemyFactory.h"

BossLevel1::BossLevel1()
{
}

BossLevel1::~BossLevel1()
{
}



BossLevel1::BossLevel1(std::vector<std::string> arr) : Boss(arr)
{	
	
	this->arrPos[0] = D3DXVECTOR3(1100, 230, 0);
	this->arrPos[1] = D3DXVECTOR3(1250, 240, 0);
	this->arrPos[2] = D3DXVECTOR3(1470, 250, 0);
	this->arrPos[3] = D3DXVECTOR3(1150, 170, 0);
	this->arrPos[4] = D3DXVECTOR3(1300, 190, 0);
	this->arrPos[5] = D3DXVECTOR3(1400, 180, 0);
	this->dectPos = 0;
	this->timeChange = 0;
	this->isAtackSimon = false;
}

void BossLevel1::fire()
{
	FireBall* fireBall = (FireBall*)EnemyFactory::getInstance()->createObj((int)TypeEnemy::FIRE_BALL);
	fireBall->appear(this->_pos,Simon::getInstance()->_pos);
	QuadTreeObject::getInstance()->addObjectToQuadTree(fireBall);
}
