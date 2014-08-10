#include "Itween.h"

Itween* Itween::_instance = NULL;

Itween* Itween::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Itween();
	}

	return _instance;
}

Itween::Itween()
{
	wasActing = false;
}

bool Itween::MoveTo(ObjectGame* obj,float deltaTime)
{
	

	if (wasActing == false)
	{
		obj->_pos = posFrom;
		wasActing = true;
		countFinish = 0;
	}else
	{
		if (timeDelay >= 0)
		{
			timeDelay -= deltaTime;
		}else
		{
			//duong di chuyen
			D3DXVECTOR2 dir;
			dir.x = speed.x > 0 ? 1 : -1;
			dir.y = speed.y > 0 ? 1 : -1;

			//move
			obj->_pos.x += speed.x * deltaTime;
			obj->_pos.y += speed.y * deltaTime;
			
			////di chuyen qua ben trai
			//if (speed.x > 0)
			//{
			//	if (obj->_pos.x <= posTo.x)
			//	{
			//		//finish
			//		countFinish++;
			//	}
			//}
			//hoan thanh
			if ( (obj->_pos.x - posTo.x) * dir.x >= 0 && (obj->_pos.y - posTo.y) * dir.y >= 0)
			{
				return true;
			}
		}
	}
	return false;
}