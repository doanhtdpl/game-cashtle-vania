//#include "ManageSprite.h"
//
//ManageSprite* ManageSprite::_ManSprite_Instance = NULL;
//
//ManageSprite* ManageSprite::CreateInstance()
//{
//	if (_ManSprite_Instance == NULL)
//		_ManSprite_Instance = new ManageSprite();
//
//	return _ManSprite_Instance;
//}
//
//ManageSprite::ManageSprite()
//{
//}
//
//void ManageSprite::Init_Sprite(LPD3DXSPRITE spriteHandle, LPDIRECT3DDEVICE9 d3ddv)
//{
//	_Sprite = new Sprite (spriteHandle);
//	
//	_camera = new Camera();
//}
//
//void ManageSprite::GetInfoFromObject(int kind, RECT *RectRS, D3DXVECTOR3 pos)
//{
//
//}
//
//void ManageSprite::DrawObject(ObjectGame *Object)
//{
//	//if (!Object->_isALive)
//	//	return;
//	RECT *rectRS;
//	if (Object->_isAnimatedSprite == false)
//		rectRS = NULL;
//	else
//		rectRS = Object->_rectRS;
//
//	Texture *texture;
//	D3DCOLOR transcolor;
//	D3DXVECTOR3 pos_Draw;
//
//	pos_Draw = _camera->GetPointTransform(Object->_pos.x, Object->_pos.y);
//	pos_Draw.x -= Object->_width / 2;
//	pos_Draw.y -= Object->_height /2;
//
//	if (Object->className() == "SpecialStone")
//	{
//		//	case Kind_StoneContainsCoin:
//		texture = _image->_SpecialStone;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//
//		pos_Draw.z = 1.0f;
//
//		_Sprite->GetInfoDraw(texture, rectRS, pos_Draw, transcolor);
//		_Sprite->Draw();
//		return;
//	}
//
//	if (Object->className() == "Item")
//	{
//		texture = _image->_Item;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//
//		pos_Draw.z = 1.0f;
//
//		_Sprite->GetInfoDraw(texture, rectRS, pos_Draw, transcolor);
//		_Sprite->Draw();
//		return;
//	}
//	
//	if (Object->className() == "Land")
//	{
//		texture = _image->_Land;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//
//		pos_Draw.z = 1.0f;
//
//		_Sprite->GetInfoDraw(texture, rectRS, pos_Draw, transcolor);
//		_Sprite->Draw();
//		return;
//	}
//
//	switch (Object->_kind)
//	{
//	case Kind_Brick:
//		texture = _image->_Brick;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_PieceBrickLeft:
//		texture = _image->_PieceBrick;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_PieceBrickRight:
//		texture = _image->_PieceBrick;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_BrickContainsCoin:
//		texture = _image->_Brick;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_Block:
//		texture = _image->_Block;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_Stone:
//		texture = _image->_Stone;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_CoinFly:
//		texture = _image->_Coin;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_Coin:
//		texture = _image->_Coin;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_FlowerKillPlayer:
//		texture = _image->_FlowerKillPlayer;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_Draw_Cloud:
//		texture = _image->_Cloud;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_Draw_Fence:
//		texture = _image->_Fence;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_Draw_Finish:
//		texture = _image->_Finish;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_Draw_Grass:
//		texture = _image->_Grass;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_Draw_Mountain:
//		texture = _image->_Mountain;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_Draw_Tree1:
//		texture = _image->_Tree1;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_Draw_Tree2:
//		texture = _image->_Tree2;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 0.5f;
//		break;
//	case Kind_MarioSmall:
//		texture = _image->_MarioSmall;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_MarioBig:
//		texture = _image->_MarioBig;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_MarioGun:
//		texture = _image->_MarioGun;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_MarioSmallSuperman:
//		texture = _image->_MarioSmallSuperman;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_MarioBigSuperman:
//		texture = _image->_MarioBigSuperman;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_MarioGunSuperman:
//		texture = _image->_MarioGunSuperman;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_ShellGreen:
//		texture = _image->_ShellGreen;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_ShellRed:
//		texture = _image->_ShellRed;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		pos_Draw.z = 1.0f;
//		break;
//	case Kind_GreenTortoise:
//		texture = _image->_ToitorseGreen;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_ToxicMushroom:
//		texture = _image->_Mushroom;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_RedTortoise:
//		texture = _image->_ToitorseRed;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_BulletOfMario:
//		texture = _image->_BulletOfMario;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_BulletOfTortoise:
//		texture = _image->_BulletOfTortoise;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_CrossBarVertical:
//		texture = _image->_Bar;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_SewerHorizontalLeft:
//		texture = _image->_SewerHorizontalLeft;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_SewerHorizontalRight:
//		texture = _image->_SewerHorizontalRight;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_SewerVertical1:
//		texture = _image->_SewerVertical1;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_SewerVertical2:
//		texture = _image->_SewerVertical2;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_SewerVertical3:
//		texture = _image->_SewerVertical3;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	case Kind_SewerVerticalCreep:
//		texture = _image->_SewerVertical2;
//		transcolor = D3DCOLOR_XRGB(255, 255, 255);
//		break;
//	default:
//		break;
//	}
//
//
//
//	_Sprite->GetInfoDraw(texture, rectRS, pos_Draw, transcolor);
//	_Sprite->Draw();
//}
//
//void ManageSprite::Update_Camera(float posx_mario)
//{
//	_camera->Update(posx_mario);
//}
//
//void ManageSprite::Draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor)
//{
//	D3DXVECTOR3 pos_Draw;
//	pos_Draw =_camera->GetPointTransform(pos.x, pos.y);
//	_Sprite->GetInfoDraw(image, RectRS, pos_Draw, transcolor);
//	_Sprite->Draw();
//	//this->_SpriteHandel->Draw(image->Get_Texture(), RectRS, NULL, &pos, transcolor);
//}
//
//ManageSprite::~ManageSprite(void)
//{
//}
