#include "utils.h"
#include "Texture.h"
#include "Sprite.h"
#include "Camera.h"

#pragma once
class ManageSprite
{
private:
	static ManageSprite* _ManSprite_Instance;
public:
	Texture *_image;
	Sprite		  *_Sprite;
	Camera		  *_camera;
public:
	ManageSprite();
	static ManageSprite* CreateInstance();
	void Init_Sprite(LPD3DXSPRITE spriteHandle, LPDIRECT3DDEVICE9 d3ddv);
	void GetInfoFromObject(int kind, RECT *RectRS, D3DXVECTOR3 pos);
	//void DrawObject(ObjectGame *Object);
	void Draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor);
	void Update_Camera(float posx_mario);
	friend class Font;
	~ManageSprite(void);
};

