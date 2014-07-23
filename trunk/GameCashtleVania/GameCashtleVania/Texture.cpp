#include "Texture.h"
#include <d3dx9.h>

Texture::Texture(LPDIRECT3DDEVICE9 d3ddv)
{
	_texture = NULL;
	_d3ddv = d3ddv;
}


Texture::~Texture(void)
{
	if(_texture)
	{
		_texture->Release();
	}

}
bool Texture::load_Image(std::string fileName, D3DCOLOR color )
{
	HRESULT result; // take a value return
	//save information of source file into avaiable _infoImageT
	result = D3DXGetImageInfoFromFile(fileName.c_str(),&_infoImageT);
	if(result != D3D_OK)
	{
		_texture = NULL;
		return 0;
	}
	// create a new Texture by loading bitmap image file
	result = D3DXCreateTextureFromFileEx(
	     _d3ddv, // directx Device
		 fileName.c_str(), // bitmap file
		 _infoImageT.Width, //bitmap image width
		 _infoImageT.Height, //bitmap image Height
		 1,
		 D3DPOOL_DEFAULT, // type of the surface
		 D3DFMT_UNKNOWN, //surface format
		 D3DPOOL_DEFAULT, // memory class for the texture
		 D3DX_DEFAULT, //image filter
		 D3DX_DEFAULT, //mip filter
		 color, // color key for transparency
		 &_infoImageT,//bitmap file information
		 NULL, //color palette
		 &_texture //destination Texture
		);
	if(result != D3D_OK)
	{
		_texture = NULL;
		return 0;
	}
	return  1;
}
LPDIRECT3DTEXTURE9 Texture::getTexture()
{
	return _texture;
}
int Texture::getHeight()
{
	return _infoImageT.Height;
}
int Texture::getWidth()
{
	return _infoImageT.Width;
}