#include "Weapon.h"
#include "TagClassName.h"
#include "Simon.h"
#include "ManageSprite.h"
#include "QNode.h"
#include "Light.h"
#include "QuadTreeObject.h"
#include "EffectFactory.h"
#include "ManageAudio.h"
Weapon::Weapon()
{
}

Weapon::Weapon(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_coloumn = atoi(arr.at(7).c_str());
	this->_totalFrames = atoi(arr.at(8).c_str());
	this->_elapseTimeSwitchFrame = atof(arr.at(9).c_str());
	this->_isAnimatedSprite = true;

	this->_isALive = false;
	this->_rect = this->getRect();

	this->_beforeTimeOld = 0.0f;
	_can_Use_Weapon = true;
}

std::string Weapon::className()
{
	return TagClassName::getInstance()->tagWeapon;
}

void Weapon::Use(D3DXVECTOR2 posSimon, bool Left)
{
	this->_isALive = true;
	this->_pos = posSimon;
	this->_Left = Left;

}

void Weapon::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	this->handleCollision(delta_Time, _listObjectCollision);
	this->move(delta_Time);
	this->animated(delta_Time);
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	//kiem tra no da ra khoi man hinh chua
	if (!QNode::isBound(this->getRect(), ManageSprite::createInstance()->_camera->getScreen()))
	{
		completeAttack();
	}
}

void Weapon::move(float delta_Time)
{

}

bool Weapon::completeAttack()
{
	this->_isALive = false;
	this->_can_Use_Weapon = true;
	return true;
}

void Weapon::effectWhenAttack(D3DXVECTOR2 pos)
{
	//tao 2 doi tuong effect va add vao quadtree
	Effect* effect0 = EffectFactory::getInstance()->createObj((int)TypeEffect::typeEffect0);
	effect0->_pos = D3DXVECTOR2(pos.x - 5, pos.y + 2);

	Effect* effect1 = EffectFactory::getInstance()->createObj((int)TypeEffect::typeEffect1);
	effect1->_pos = D3DXVECTOR2(pos.x, pos.y - 2);

	QuadTreeObject::getInstance()->addObjectToQuadTree(effect0);
	QuadTreeObject::getInstance()->addObjectToQuadTree(effect1);
}

void Weapon::handleCollision(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	std::vector<ObjectGame*>::iterator it = _listObjectCollision.begin();
	ObjectGame* obj = NULL;
	HideObject* hideObj = NULL;
	float normalX = 0;
	float normalY = 0;
	float timeCollision;
	while(it != _listObjectCollision.end())
	{
		obj = *it;
		this->_box = this->getBox();
		if(obj->className() == TagClassName::getInstance()->tagEnemy)
		{
			Enemy* enemy = (Enemy*)obj;
			timeCollision = this->collision((DynamicObject*)obj, normalX, normalY, delta_Time);
			if((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				D3DXVECTOR2 posEffect = D3DXVECTOR2(enemy->_pos.x, this->_pos.y);
				if (enemy->isAttack())
				{
					this->effectWhenAttack(posEffect);
				}

				if (this->_typeOfWeapon == TypeWeapon::Dagger)
				{
					this->_isALive = false;
					this->_can_Use_Weapon = true;
				}
			//	ManageAudio::getInstance()->playSound(TypeAudio::Hit);
				
			}
		}
		else if(obj->className() == TagClassName::getInstance()->tagHideObject)
		{
			hideObj = (HideObject*)obj;
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, delta_Time);
			if((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				if(hideObj->getTypeHideObject() == TypeHideObect::Ground)
				{
					this->handleCollisionWithGround(hideObj);
				}
			}

		}

		if (obj->className() == TagClassName::getInstance()->tagLight)
		{
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, delta_Time);

			if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				if (this->_typeOfWeapon == TypeWeapon::Dagger)
				{
					this->_isALive = false;
					this->_can_Use_Weapon = true;
				}
				//tao ra hieu ung.

				//goi ham effect cua light
				Light* light = (Light*)obj;
				light->_isALive = false;
				Item* item = light->effectWhenCollisionRod();
				QuadTreeObject::getInstance()->addObjectToQuadTree(item);

				D3DXVECTOR2 posEffect = D3DXVECTOR2(light->_pos.x, this->_pos.y);
				this->effectWhenAttack(posEffect);
			}
		}
		++it;
	}
}

void Weapon::handleCollisionWithGround(HideObject* hideObj)
{

}

void Weapon::handleCollisionWithEnemy(Enemy* enemy)
{

}

void Weapon::setTypeOfWeapon(TypeWeapon typeOfWeapon)
{
	this->_typeOfWeapon = typeOfWeapon;
}

TypeWeapon Weapon::getTypeOfWeapon()
{
	return this->_typeOfWeapon;
}
