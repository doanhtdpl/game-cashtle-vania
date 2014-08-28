#include "IronRod.h"
#include "ManageSprite.h"
#include "TagClassName.h"
#include "Light.h"
#include "QuadTreeObject.h"
#include "Simon.h"

IronRod* IronRod::_instance = NULL;

IronRod* IronRod::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new IronRod();
	}
	return _instance;
}

IronRod* IronRod::createInstance(std::vector<std::string> arr)
{
	if (_instance == NULL)
	{
		_instance = new IronRod(arr);
	}
	return _instance;
}

IronRod::IronRod()
{

}

IronRod::IronRod(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());

	this->_width = atoi(arr.at(3).c_str());
	this->_height = atoi(arr.at(4).c_str());

	this->realHeight = atoi(arr.at(5).c_str());
	this->_realWidthType12 = atoi(arr.at(6).c_str());
	this->_realWidthType3 = atoi(arr.at(7).c_str());
	this->_elapseTimeState1 = atof(arr.at(8).c_str());
	this->_elapseTimeState2 = atof(arr.at(9).c_str());
	this->_elapseTimeState3 = atof(arr.at(10).c_str());
	
	this->_coloumn = atoi(arr.at(11).c_str());
	this->_totalFrames = atoi(arr.at(12).c_str());

	this->realWidth = this->_realWidthType12;//loai ra so 1 va so 2// state 3
	this->_typeRod = Type_Rod::Rod1;
	this->_stateRod = State_Rod::Step1;
	
	//demo
	this->_isALive = false;
	//this->_Left = false;
	//this->_pos = D3DXVECTOR2(100, 68);

	this->timeChangeState = _elapseTimeState1;
	this->_isAnimatedSprite = true;
	this->_rectRS = this->updateRectRS(this->_width, this->_height);
}

Type_Rod IronRod::getTypeRod()
{
	return this->_typeRod;
}

State_Rod IronRod::getStateRod()
{
	return this->_stateRod;
}

void IronRod::ChangeState()
{
	switch (this->_stateRod)
	{
	case State_Rod::Step1:
		this->_stateRod = State_Rod::Step2;
		//thay doi thoi gian chuyen state nua
		this->timeChangeState = _elapseTimeState2;
		break;
	case State_Rod::Step2:
		this->_stateRod = State_Rod::Step3;
		this->timeChangeState = _elapseTimeState3;
		//thay doi thoi gian
		break;
	case State_Rod::Step3:
		this->_isALive = false;
		completeAttack();
		//chuyen ve state 1
		this->_stateRod = State_Rod::Step1;
		this->timeChangeState = _elapseTimeState1;
		// fisnish
		break;
	default:
		break;
	}
}

void IronRod::setStateRod(State_Rod state_rod)
{
	this->_stateRod = state_rod;
}

void IronRod::ChangeTypeRod()
{
	//thay doi chieu dai cua roi
	switch (this->_typeRod)
	{
	case Type_Rod::Rod1:
		this->_typeRod = Type_Rod::Rod2;
		this->realWidth = this->_realWidthType12;
		break;
	case Type_Rod::Rod2:
		this->_typeRod = Type_Rod::Rod3;
		this->realWidth = this->_realWidthType3;
		break;
	case Type_Rod::Rod3:
		//nothing
		break;
	default:
		break;
	}
}

void IronRod::Use(D3DXVECTOR2 posSimon, bool Left)
{
	this->_isALive = true;
	this->_pos = posSimon;
	int dir = Left ? 1 : -1;
	this->_pos.x -= 28 * dir;
	this->_stateRod = State_Rod::Step1;
	this->_Left = Left;
}

bool IronRod::completeAttack()
{
	if (Simon::getInstance()->_attacking)
	{
		//ket thuc tan cong
		Simon::getInstance()->_attacking = false;
	}

	return true;
}

//pos: pos dung de ve Rod.
//nhung box dung de va cham cua no lai khac
Box IronRod::getBox()
{
	// box dung de va cham tinh tu vi tri ve cua no tinh len.
	//Chi dung cho rod o trang thai 3. Trang thai 3 moi co va cham giet quai
	if (this->_Left)
	{
		return Box(this->_pos.x - this->realWidth / 2, this->_pos.y + this->realHeight / 2, 
			this->realWidth, this->realHeight);
	} 
	else
	{
		return Box(this->_pos.x + this->realWidth / 2, this->_pos.y + this->realHeight / 2, 
			this->realWidth, this->realHeight);
	}
	
}

void IronRod::update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision)
{
	timeChangeState -= delta_Time;
	if (timeChangeState <= 0)
	{
		ChangeState();
	}

	if (this->_isALive)
	{	
		animated(delta_Time);
		this->_rectRS = this->updateRectRS(this->_width, this->_height);
		
		std::vector<ObjectGame*>::iterator it = _listObjectCollision.begin();
		ObjectGame* obj = NULL;
		Item* item = NULL;
		float normalX = 0;
		float normalY = 0;
		float timeCollision;
		if(this->_stateRod == State_Rod::Step3)
		{
			while (it != _listObjectCollision.end())
			{
				obj = *it;
				//va cham voi den
				if (obj->className() == TagClassName::getInstance()->tagLight)
				{
					timeCollision = this->collision((StaticObject*)obj, normalX, normalY, delta_Time);

					if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
					{
						//tao ra hieu ung.

						//goi ham effect cua light
						Light* light = (Light*)obj;
						light->_isALive = false;
						item = light->effectWhenCollisionRod();
						QuadTreeObject::getInstance()->addObjectToQuadTree(item);

						D3DXVECTOR2 posEffect = D3DXVECTOR2(light->_pos.x, this->_pos.y);
						this->effectWhenAttack(posEffect);
					}
				}else
				{
					if (obj->className() == TagClassName::getInstance()->tagEnemy)
					{
						Enemy* enemy = (Enemy*)obj;
						timeCollision = this->collision((DynamicObject*)obj, normalX, normalY, delta_Time);
						if((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
						{
							enemy->isAttack();
							D3DXVECTOR2 posEffect = D3DXVECTOR2(enemy->_pos.x, this->_pos.y);
							if (!enemy->pause)
							{
								this->effectWhenAttack(posEffect);
							}
							
						}
						
					}
				}
				it++;
			}
		}
	}
	
	// va cham tinh sau.
}

void IronRod::animated(float deltaTime)
{
	this->_curFrame = (this->_typeRod - 1) * this->_coloumn + this->_stateRod - 1;
}