#ifndef __TEXTURE__H__
#define __TEXTURE__H__

#include <iostream>
#include <d3dx9.h>

class Texture
{
private:
	LPDIRECT3DTEXTURE9 _texture; //Directx Texture
	D3DXIMAGE_INFO _infoImageT; // information Image
	LPDIRECT3DDEVICE9 _d3ddv; // Directx Device
public:
	Texture(LPDIRECT3DDEVICE9 );
	~Texture(void);
	bool load_Image(std::string , D3DCOLOR );
	LPDIRECT3DTEXTURE9 getTexture();
	int getHeight();
	int getWidth();
};

#endif // !__TEXTURE__H__