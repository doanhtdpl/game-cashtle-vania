#ifndef __MANAGE_SPRITE_H_
#define __MANAGE_SPRITE_H_

#include "Texture.h"
#include "Sprite.h"
#include "Camera.h"
#include "ObjectGame.h"

#pragma once
class ManageSprite
{
private:
	static ManageSprite* _ManSprite_Instance;
public:
	Sprite		  *_Sprite;
	Camera		  *_camera;
public:
	ManageSprite();
	static ManageSprite* CreateInstance();
	void Init_Sprite(LPD3DXSPRITE spriteHandle);
	void DrawObject(ObjectGame *Object);
	void Draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor);
	void Update_Camera(float posx_mario);
	friend class Font;
	~ManageSprite(void);
};

#endif // !__MANAGE_SPRITE_H_