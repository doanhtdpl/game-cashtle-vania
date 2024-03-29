
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <d3dx9.h>
class Camera
{
private:
	D3DXVECTOR3 _pos;
	D3DXMATRIX _MatrixTransform;
	RECT _boundScene;
	//static Camera* _Camera_Object;
public:
	//static Camera* CreateInstance();
	Camera(void);
	~Camera(void);
	bool stopScrollScreen;
	void setBound(RECT rect);
	float speedX;
	
	bool donePrepare;
	float posXTarget;

	void update(float x, float deltaTime);
	bool move(float vx, float posXTarget, float deltaTime, bool dir = false);//mac dinh di qua ben phai
	D3DXVECTOR3 getPosCamera();
	D3DXVECTOR3 getPointTransform(float x, float y);
	RECT getScreen();
};


#endif // !__CAMERA_H__