
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <d3dx9.h>
#pragma once
class Camera
{
private:
	D3DXVECTOR3 _pos;
	D3DXMATRIX _MatrixTransform;
	//static Camera* _Camera_Object;
public:
	//static Camera* CreateInstance();
	Camera(void);
	~Camera(void);
	void update(float x);
	D3DXVECTOR3 getPosCamera();
	D3DXVECTOR3 getPointTransform(float x, float y);
};


#endif // !__CAMERA_H__