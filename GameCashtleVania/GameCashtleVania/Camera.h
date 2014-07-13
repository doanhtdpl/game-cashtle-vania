
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
	void Update(float x);
	D3DXVECTOR3 GetPosCamera();
	D3DXVECTOR3 GetPointTransform(float x, float y);
};


#endif // !__CAMERA_H__