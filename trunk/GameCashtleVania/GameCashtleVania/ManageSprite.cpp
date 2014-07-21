#include "ManageSprite.h"
#include "ManageTexture.h"

ManageSprite* ManageSprite::_ManSprite_Instance = NULL;

ManageSprite* ManageSprite::CreateInstance()
{
	if (_ManSprite_Instance == NULL)
		_ManSprite_Instance = new ManageSprite();

	return _ManSprite_Instance;
}

ManageSprite::ManageSprite()
{
}

void ManageSprite::Init_Sprite(LPD3DXSPRITE spriteHandle)
{
	_Sprite = new Sprite (spriteHandle);

	_camera = new Camera();
}

void ManageSprite::DrawObject(ObjectGame *Object)
{
	RECT *rectRS;
	bool isCenter = true;
	if (Object->_isAnimatedSprite == false)
	{
		rectRS = NULL;
		isCenter = false;
	}
	else
		rectRS = Object->_rectRS;

	Texture *texture = ManageTexture::getInstance()->getTetureByKey(Object->_ID_Image);
	D3DCOLOR transcolor = D3DCOLOR_XRGB(255, 255, 255);
	D3DXVECTOR3 pos_Draw;

	pos_Draw = _camera->GetPointTransform(Object->_pos.x, Object->_pos.y);
	

	//khong quay ve ben trai
	if (Object->_Left)
	{
		// ve tai goc trai tren
		pos_Draw.x -= Object->_width / 2;
		pos_Draw.y -= Object->_height / 2;
		_Sprite->Draw(texture, rectRS, pos_Draw, transcolor, false);
	}else
	{
		// ve tai trung tam va quay anh.
		_Sprite->DrawFlipX(texture, rectRS, pos_Draw, transcolor, true);
	}
	
	//
}

void ManageSprite::Update_Camera(float posx_mario)
{
	_camera->Update(posx_mario);
}

void ManageSprite::Draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor)
{
	D3DXVECTOR3 pos_Draw;
	pos_Draw =_camera->GetPointTransform(pos.x, pos.y);
	_Sprite->Draw(image, RectRS, pos_Draw, transcolor);
	//this->_SpriteHandel->Draw(image->Get_Texture(), RectRS, NULL, &pos, transcolor);
}

ManageSprite::~ManageSprite(void)
{
}
