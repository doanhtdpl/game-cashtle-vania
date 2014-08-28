#include "ManageSprite.h"
#include "ManageTexture.h"

ManageSprite* ManageSprite::_ManSprite_Instance = NULL;

ManageSprite* ManageSprite::createInstance()
{
	if (_ManSprite_Instance == NULL)
		_ManSprite_Instance = new ManageSprite();

	return _ManSprite_Instance;
}

ManageSprite::ManageSprite()
{
}

void ManageSprite::init_Sprite(LPD3DXSPRITE spriteHandle)
{
	_Sprite = new Sprite (spriteHandle);

	_camera = new Camera();
}

void ManageSprite::drawObject(ObjectGame *Object,D3DCOLOR transcolor)
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
	//D3DCOLOR transcolor = D3DCOLOR_XRGB(255, 255, 255);
	D3DXVECTOR3 pos_Draw;

	pos_Draw = _camera->getPointTransform(Object->_pos.x, Object->_pos.y);
	pos_Draw.z = Object->z;

	//khong quay ve ben trai
	if (Object->_Left)
	{
		// ve tai goc trai tren
		pos_Draw.x -= Object->_width / 2;
		pos_Draw.y -= Object->_height / 2;
		_Sprite->draw(texture, rectRS, pos_Draw, transcolor, false);
	}else
	{
		// ve tai trung tam va quay anh.
		_Sprite->drawFlipX(texture, rectRS, pos_Draw, transcolor, true);
	}
	
	//
}

void ManageSprite::update_Camera(float posx_simon, float deltaTime)
{
	_camera->update(posx_simon, deltaTime);
}

void ManageSprite::draw(int IDImage, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor)
{
	Texture* texture = ManageTexture::getInstance()->getTetureByKey(IDImage);
	D3DXVECTOR3 pos_Draw;
	pos_Draw =_camera->getPointTransform(pos.x, pos.y);
	
	_Sprite->draw(texture, RectRS, pos_Draw, transcolor,true);
	//this->_SpriteHandel->Draw(image->Get_Texture(), RectRS, NULL, &pos, transcolor);
}

ManageSprite::~ManageSprite(void)
{
}
