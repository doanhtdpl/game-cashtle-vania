#include "Medusa.h"
#include "ManageGame.h"

Medusa::Medusa()
{

}

Medusa::Medusa(std::vector<std::string> arr) : Enemy(arr)
{
	this->lamda = atoi(arr.at(12).c_str());
	this->k = atoi(arr.at(13).c_str());

	this->_moveMent = EnemyMovement::Moves;
	if (ManageGame::_infoScene->level == 2 && ManageGame::_infoScene->iD_Scene == 4)
	{
		this->_Left = true;
	}else{
		this->_Left = false;
	}
}

void Medusa::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}

void Medusa::move(float delta_Time)
{
	int dir = this->_Left ? -1 : 1;
	this->_vx = dir * this->_Vx_default;

	this->_pos.x += this->_vx * delta_Time;
	this->_pos.y = this->posDefault.y + std::sin((this->_pos.x - this->posDefault.x) / this->lamda * PI) * this->k;
}