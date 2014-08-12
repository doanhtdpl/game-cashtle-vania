#include "Camera.h"
#include "utils.h"

Camera::Camera(void)
{
	_pos.x = 0;
	_pos.y = Screen_Height;
	_pos.z = 0;
	this->speedX = 90;

	D3DXMatrixIdentity(&_MatrixTransform);
	_MatrixTransform._22 = -1;
	this->stopScrollScreen = false;
}

Camera::~Camera(void)
{
}

D3DXVECTOR3 Camera::getPosCamera()
{
	return _pos;
}

void Camera::update(float x, float deltaTime)
{
	float x_target = x - Screen_Width / 2;
	float distance = x_target - _pos.x;
	if (!stopScrollScreen)
	{
		if (distance > 0)
		{//di chuyen cau thang qua ben phai
			if (distance > speedX * deltaTime)
			{
				_pos.x += speedX * deltaTime;
			}else
			{
				_pos.x = x_target;
			}
		}else
		{//di chuyen cau thang qua ben trai
			if (abs(distance) > abs(speedX) * deltaTime)
			{
				_pos.x += -speedX * deltaTime;
			}else
			{
				_pos.x = x_target;
			}
		}
		if(_pos.x < 0)
			_pos.x = 0;
	}
}

D3DXVECTOR3 Camera::getPointTransform(float x, float y)
{
	
	_MatrixTransform._41 = - _pos.x;
	_MatrixTransform._42 = _pos.y;

	D3DXVECTOR4 v_result;
	D3DXVECTOR3 posOld(x, y, 0);

	D3DXVec3Transform(&v_result, &posOld, &_MatrixTransform);

	return D3DXVECTOR3(v_result.x, v_result.y - 20, v_result.z);
}

RECT Camera::getScreen()
{
	RECT rect;
	//if (this->_pos.x > Screen_Width / 2)
	//{
	//	rect.left = this->_pos.x - Screen_Width / 2;
	//}else
	//{
	//	rect.left = 0;
	//}
	rect.left = this->_pos.x;	
	rect.right = rect.left + Screen_Width;
	rect.top = this->_pos.y;// + Screen_Height / 2
	rect.bottom = rect.top - Screen_Height;
	return rect;
}