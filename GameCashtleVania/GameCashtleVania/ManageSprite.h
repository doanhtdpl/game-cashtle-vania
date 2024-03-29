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
	static ManageSprite* createInstance();
	void init_Sprite(LPD3DXSPRITE spriteHandle);
	void drawObject(ObjectGame *Object, D3DCOLOR transcolor = D3DCOLOR_XRGB(255, 255, 255));

	//ve hinh theo IDImage tai vi tri trung tam. pos la vi tri o giua
	void draw(int IDImage, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF);
	void draw(Texture* texture, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor = 0xFFFFFFFF);
	void update_Camera(float posx_simon, float deltaTime);
	friend class Font;
	~ManageSprite(void);
};

#endif // !__MANAGE_SPRITE_H_