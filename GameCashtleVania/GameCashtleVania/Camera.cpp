#include "Camera.h"

Camera::Camera(void)
{
	_pos.x = 0;
	_pos.y = 600;
	_pos.z = 0;

	D3DXMatrixIdentity(&_MatrixTransform);
	_MatrixTransform._22 = -1;
}

Camera::~Camera(void)
{
}

D3DXVECTOR3 Camera::getPosCamera()
{
	return _pos;
}

void Camera::update(float x)
{
	_pos.x = x - 400;
	if(_pos.x < 0)
		_pos.x = 0;
}

D3DXVECTOR3 Camera::getPointTransform(float x, float y)
{
	
	_MatrixTransform._41 = - _pos.x;
	_MatrixTransform._42 = _pos.y;

	D3DXVECTOR4 v_result;
	D3DXVECTOR3 posOld(x, y, 0);

	D3DXVec3Transform(&v_result, &posOld, &_MatrixTransform);

	return D3DXVECTOR3(v_result.x, v_result.y, v_result.z);
}