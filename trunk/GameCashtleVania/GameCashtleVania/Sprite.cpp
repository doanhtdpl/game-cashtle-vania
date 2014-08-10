#include "Sprite.h"


Sprite::Sprite(LPD3DXSPRITE sprite)
{
	this->_SpriteHandel = sprite;
}

Sprite::~Sprite(void)
{
}

void Sprite::draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor, bool isCenter)
{
	if (isCenter)
	{
		D3DXVECTOR3* center;
		if (RectRS == NULL)
		{
			center = NULL;
		}else
		{
			center = new D3DXVECTOR3(
				(RectRS->right - RectRS->left) / 2.0f,
				(RectRS->bottom - RectRS->top) / 2.0f,
				0);
		}
		this->_SpriteHandel->Draw(image->getTexture(), RectRS, center, &pos, transcolor);
	}else {
		
		this->_SpriteHandel->Draw(image->getTexture(), RectRS, NULL, &pos, transcolor);
	}	
}

void Sprite::draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scale, D3DCOLOR transcolor /* = 0xFFFFFFFF */, bool isCenter /* = true */)
{
	HRESULT result;

	//Lay ma tran transform hien tai
	D3DXMATRIX oldMatrix;

	//tim ra vi tri moi trong he toa do sau khi scale
	D3DXVECTOR3 newPos = D3DXVECTOR3(pos.x / scale.x, pos.y / scale.y, pos.z);

	result = this->_SpriteHandel->GetTransform(&oldMatrix);
	if (result != D3D_OK)
	{
		return;
	}

	// Tạo ma trận transform mới
	D3DXMATRIX newMatrix;

	D3DXMatrixIdentity(&newMatrix);
	newMatrix._11 = scale.x;
	newMatrix._22 = scale.y;

	//ap dung ma tran transform moi de ve
	result = this->_SpriteHandel->SetTransform(&newMatrix);
	if (result != D3D_OK)
	{
		return;
	}

	//doi nguoc truc z lai
	//newPos.z = -newPos.z;

	this->draw(image, RectRS, newPos, transcolor, isCenter);

	result = this->_SpriteHandel->SetTransform(&oldMatrix);
	if (result != D3D_OK)
	{
		return;
	}
}

//ve texture theo lat ngang
void Sprite::drawFlipX(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor, bool isCenter)
{
	D3DXVECTOR2 scaling = D3DXVECTOR2(-1, 1);
	this->draw(image, RectRS, pos, scaling, transcolor, isCenter);
}

//ve texture theo lap doc
void Sprite::drawFlipY(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor, bool isCenter)
{
	D3DXVECTOR2 scaling = D3DXVECTOR2(1, -1);
	this->draw(image, RectRS, pos, scaling, transcolor, isCenter);
}
