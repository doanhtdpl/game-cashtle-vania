#include "Sprite.h"


Sprite::Sprite(LPD3DXSPRITE sprite)
{
	this->_SpriteHandel = sprite;
}

Sprite::~Sprite(void)
{
}

void Sprite::Draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor, bool isCenter)
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
				( RectRS->right - RectRS->left) / 2.0f,
				( RectRS->bottom - RectRS->top) / 2.0f,
				0 );
		}
		
		this->_SpriteHandel->Draw(image->Get_Texture(), RectRS, center, &pos, transcolor);
	}else {
		this->_SpriteHandel->Draw(image->Get_Texture(), RectRS, NULL, &pos, transcolor);

	}	
}

void Sprite::Draw(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DXVECTOR2 scale, D3DCOLOR transcolor /* = 0xFFFFFFFF */, bool isCenter /* = true */)
{
	HRESULT result;

	//Lay ma tran transform hien tai
	D3DXMATRIX oldMatrix;

	//tim ra vi tri moi trong he toa do sau khi scale
	D3DXVECTOR3 newPos = D3DXVECTOR3(pos.x / scale.x, pos.y / scale.y, 0);

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

	this->Draw(image, RectRS, newPos, transcolor, isCenter);

	result = this->_SpriteHandel->SetTransform(&oldMatrix);
	if (result != D3D_OK)
	{
		return;
	}
}

//ve texture theo lat ngang
void Sprite::DrawFlipX(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor, bool isCenter)
{
	D3DXVECTOR2 scaling = D3DXVECTOR2(-1, 1);
	this->Draw(image, RectRS, pos, scaling, transcolor, isCenter);
}

//ve texture theo lap doc
void Sprite::DrawFlipY(Texture* image, RECT *RectRS, D3DXVECTOR3 pos, D3DCOLOR transcolor, bool isCenter)
{
	D3DXVECTOR2 scaling = D3DXVECTOR2(1, -1);
	this->Draw(image, RectRS, pos, scaling, transcolor, isCenter);
}
